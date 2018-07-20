//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop
#include "FileCompare.h"
#include "Main.h"
#include "Data.h"
#include "MergeSource.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TCompareFiles *CompareFiles;
String MergeTargetName;
//---------------------------------------------------------------------------
__fastcall TCompareFiles::TCompareFiles(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
/*
############################################################################
This handler clears the textboxes containing paths to files to be compared
when the form is shown.
############################################################################
*/
void __fastcall TCompareFiles::FormShow(TObject *Sender)
{
CompareResult->Clear();
FileName1->Text = "";
FileName1->Tag = -1;
FileName2->Text = "";
FileName2->Tag = -1;
SourceFile1->Enabled = ActionMerge->Checked;
SourceFile2->Enabled = ActionMerge->Checked;
SourceDefault->Enabled = ActionMerge->Checked;
SourceAsk->Enabled = ActionMerge->Checked;
TargetFile1->Enabled = ActionMerge->Checked;
TargetFile2->Enabled = ActionMerge->Checked;
TargetOther->Enabled = ActionMerge->Checked;
};
//---------------------------------------------------------------------------
/*
############################################################################
This handler launches the dialog to browse for the file to be compared.
############################################################################
*/
void __fastcall TCompareFiles::BrowseFileClick(TObject *Sender)
{
if (Sender == BrowseFile1) {
   OpenDialog->Tag = 1;
}
else if (Sender == BrowseFile2) {
   OpenDialog->Tag = 2;
}
OpenDialog->Execute();
}
//---------------------------------------------------------------------------
/*
############################################################################
This handler loads the selected file's path to the textbox and
reads its DAT-type from its size.
############################################################################
*/
void __fastcall TCompareFiles::OpenDialogCanClose(TObject *Sender,
      bool &CanClose)
{
TMemoryStream* WorkFile = new TMemoryStream();
if (WorkFile) {
   WorkFile->LoadFromFile(OpenDialog->FileName);
   for (int i=0;i<11;i++) {
       if (WorkFile->Size == Form1->GetDATFile(i)->GetFilesize()) {
          if (FileExists(OpenDialog->FileName)) {
             switch (OpenDialog->Tag) {
                 case 1:
                      FileName1->Text = OpenDialog->FileName;
                      FileName1->Tag = i;
                      break;
                 case 2:
                      FileName2->Text = OpenDialog->FileName;
                      FileName2->Tag = i;
                      break;
             }
             if (OpenDialog->FileName.Pos(GetDATType(i)) == 0) {
                MessageDlg("\""+OpenDialog->FileName+"\" is a mislabeled \""+GetDATType(i)+".dat\"-type file.", mtInformation, TMsgDlgButtons() << mbOK, 0);
             }
             CanClose = true;
             break;
          }
       }
       else if (i==10) {
          CanClose = false;
          MessageDlg("\""+OpenDialog->FileName+"\" is not a valid DAT file.", mtError, TMsgDlgButtons() << mbOK, 0);
       }
   }
}
else {
   MessageDlg("Failed to allocate memory to open \""+OpenDialog->FileName+"\".", mtError, TMsgDlgButtons() << mbOK, 0);
}
delete WorkFile;
};
//---------------------------------------------------------------------------
/*
############################################################################
This routine performs the entry-by-entry, property-by-property comparison
check and outputs the results to the table.
############################################################################
*/
void __fastcall TCompareFiles::ActionButtonClick(TObject *Sender)
{
if ((FileExists(FileName1->Text) &&  FileExists(FileName2->Text)) || (FileExists(FileName2->Text) && !FileExists(FileName1->Text) && FileName1->Text.Pos("#") != 0)) {
   if (FileName1->Tag == FileName2->Tag) {
      CompareResult->Clear();
      int Tag=FileName1->Tag;
      bool MergeFiles = ((TComponent*)(Sender))->Tag; 
      FileData File1,File2,Merge,Default;
      TStringList *List = new TStringList;
      TStringList *Format = new TStringList;

      List->AddStrings(Form1->GetDATEntryNames(Tag));
      Format->AddStrings(Form1->GetDATFormat(Tag));
      File1.SetDATTypeID(Tag);
      File1.LoadFormat(Format);
      File2.SetDATTypeID(Tag);
      File2.LoadFormat(Format);
      if (MergeFiles == true) {
         if (TargetFile1->Checked == true) {
            Merge = File1;
         }
         else if (TargetFile2->Checked == true) {
            Merge = File2;
         }
         else {
            Merge.SetDATTypeID(Tag);
            Merge.LoadFormat(Format);
         }
         Default.SetDATTypeID(Tag);
         Default.LoadFormat(Format);
         Default.LoadFile(Form1->GetProgPath()+"Default\\"+GetDATType(Tag)+".dat");
      }  

      if (FileName1->Text == Form1->GetDATFile(Tag)->GetDatName() && FileName1->Text.Pos(String(Form1->GetProgPath()+"Default\\")) == 0) {
         File1 = Form1->GetDATFile(Tag);
      }
      else {
         File1.LoadFile(FileName1->Text);
      }
      if (FileName2->Text == Form1->GetDATFile(Tag)->GetDatName() && FileName2->Text.Pos(String(Form1->GetProgPath()+"Default\\")) == 0) {
         File2 = Form1->GetDATFile(Tag);
      }
      else {
         File2.LoadFile(FileName2->Text);
      }
      int LastIndex=-1;
      for (int j=0;j<File1.GetOutputEntrycount();j++) {
          for (int i=0;i<File1.GetVarcount();i++) {
              if (File1.GetData()[j*File1.GetVarcount()+i] != File2.GetData()[j*File2.GetVarcount()+i]) {
                 if (LastIndex != j) {
                   if (LastIndex != -1) {
                      CompareResult->AddItem("",NULL);
                   }
                   CompareResult->AddItem("Entry #"+String(j)+":"+List->Strings[j],NULL);
                 }
                 if (Format->Values[String(i)+"Name"].Pos(":") != 0) {
                    TStringList *FlagNames = new TStringList();
                    String PropertyName = Form1->GetDATFormat(Tag)->Values[String(i)+"Name"];
                    FlagNames->CommaText = PropertyName.SubString(PropertyName.Pos(":")+1,PropertyName.Length()-PropertyName.Pos(":"));
                    int Diff = (File1.GetData()[j*File1.GetVarcount()+i])^(File2.GetData()[j*File2.GetVarcount()+i]);
                    for (int k=0;k<32;k++) {
                        if (bool(int(Power(2,float(k)))&Diff)) {
                           CompareResult->AddItem(FlagNames->Strings[k],NULL);
                           CompareResult->Items->Item[CompareResult->Items->Count-1]->SubItems->Add(int(bool(int(Power(2,float(k)))&File1.GetData()[j*File1.GetVarcount()+i])));
                           CompareResult->Items->Item[CompareResult->Items->Count-1]->SubItems->Add(int(bool(int(Power(2,float(k)))&File2.GetData()[j*File2.GetVarcount()+i])));
                           CompareResult->Items->Item[CompareResult->Items->Count-1]->Indent = 10;
                        }
                    }
                    delete FlagNames;
                 }
                 else {
                    CompareResult->AddItem(Format->Values[String(i)+"Name"],NULL);
                    if (ConvertValue(File1.GetData()[j*File1.GetVarcount()+i],Tag,i) != File1.GetData()[j*File1.GetVarcount()+i]) {
                       CompareResult->Items->Item[CompareResult->Items->Count-1]->SubItems->Add(String(ConvertValue(File1.GetData()[j*File1.GetVarcount()+i],Tag,i)));
                       CompareResult->Items->Item[CompareResult->Items->Count-1]->SubItems->Add(String(ConvertValue(File2.GetData()[j*File2.GetVarcount()+i],Tag,i)));
                    }
                    else {
                       CompareResult->Items->Item[CompareResult->Items->Count-1]->SubItems->Add(File1.GetData()[j*File1.GetVarcount()+i]);
                       CompareResult->Items->Item[CompareResult->Items->Count-1]->SubItems->Add(File2.GetData()[j*File2.GetVarcount()+i]);
                    }
                    CompareResult->Items->Item[CompareResult->Items->Count-1]->Indent = 10;
                 }
                 LastIndex = j;
                 
                 if (MergeFiles == true) {
                    if (SourceFile1->Checked == true) {
                       if (File1.GetData()[j*File1.GetVarcount()+i] != Default.GetData()[j*Default.GetVarcount()+i]) {
                          Merge.GetData()[j*Merge.GetVarcount()+i] = File1.GetData()[j*File1.GetVarcount()+i];
                       }
                       else {
                          Merge.GetData()[j*Merge.GetVarcount()+i] = File2.GetData()[j*File2.GetVarcount()+i];
                       }                                                  
                    }
                    else if (SourceFile2->Checked == true) {
                       if (File2.GetData()[j*File2.GetVarcount()+i] != Default.GetData()[j*Default.GetVarcount()+i]) {
                          Merge.GetData()[j*Merge.GetVarcount()+i] = File2.GetData()[j*File2.GetVarcount()+i];
                       }
                       else {
                          Merge.GetData()[j*Merge.GetVarcount()+i] = File1.GetData()[j*File1.GetVarcount()+i];
                       }
                    }
                    else if (SourceDefault->Checked == true) {
                       Merge.GetData()[j*Merge.GetVarcount()+i] = Default.GetData()[j*Default.GetVarcount()+i];
                    }
                    else if (SourceAsk->Checked == true) {
                       MergeDialog->SetProperty(CompareResult->Items->Item[CompareResult->Items->Count-1]->Caption,CompareResult->Items->Item[CompareResult->Items->Count-1]->SubItems->Strings[0].ToDouble(),CompareResult->Items->Item[CompareResult->Items->Count-1]->SubItems->Strings[1].ToDouble(),ConvertValue(Default.GetData()[j*Default.GetVarcount()+i],Tag,i));
                       MergeDialog->ShowModal();
                       if (MergeDialog->ModalResult == mrYes) {
                          Merge.GetData()[j*Merge.GetVarcount()+i] = File1.GetData()[j*File1.GetVarcount()+i];
                       }
                       else if (MergeDialog->ModalResult == mrNo) {
                          Merge.GetData()[j*Merge.GetVarcount()+i] = File2.GetData()[j*File2.GetVarcount()+i];
                       }
                       else if (MergeDialog->ModalResult == mrAll) {
                          Merge.GetData()[j*Merge.GetVarcount()+i] = Default.GetData()[j*Default.GetVarcount()+i];
                       }
                    }
                 }
              }
              else if (MergeFiles == true && TargetOther->Checked == true) {
                 Merge.GetData()[j*Merge.GetVarcount()+i] = File1.GetData()[j*File1.GetVarcount()+i];
              }
          }
      }
      if (LastIndex == -1) {
         MessageDlg("Files are identical!", mtInformation, TMsgDlgButtons() << mbOK, 0);
      }
      else if (MergeFiles == true) {
         MergeTargetName="";
         if (TargetFile1->Checked == true) {
            MergeTargetName = File1.GetDatName();
            Merge.SaveData(File1.GetDatName());
         }
         else if (TargetFile2->Checked == true) {
            MergeTargetName = File2.GetDatName();
            Merge.SaveData(File2.GetDatName());
         }
         else if (TargetOther->Checked == true) {
            SaveMergeResult->Execute();
            if (MergeTargetName != "") {
               Merge.SaveData(MergeTargetName);
            }
         }
         if (FileExists(MergeTargetName)) {
            MessageDlg("Merge result saved as \""+MergeTargetName+"\".", mtInformation, TMsgDlgButtons() << mbOK, 0);
         }
      }
      delete File1,File2,Merge,Default;
   }
   else {
      MessageDlg("Incompatible DAT files!", mtError, TMsgDlgButtons() << mbOK, 0);
   }
}
else {
   MessageDlg("At least 1 file does not exist!", mtError, TMsgDlgButtons() << mbOK, 0);
}
}
//---------------------------------------------------------------------------
/*
############################################################################
This handler closes the Compare Files form if the Escape key was pressed.
############################################################################
*/
void __fastcall TCompareFiles::FormKeyDown(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
if (Key == VK_ESCAPE) {
   CompareFiles->Close();
}
}
//---------------------------------------------------------------------------
/*
############################################################################
this function returns a property's value which is stored as different
to what is used in the interface.
############################################################################
*/
float TCompareFiles::ConvertValue (int Value,int DATTypeID,int PropertyID)
{
float Modulo=1;
switch (DATTypeID) {
       case 0:
            if (PropertyID == 8) {
               Modulo = 256;
            }
            else if (PropertyID == 47) {
               Modulo = 15;
            }
            else if (PropertyID == 50 || PropertyID == 51) {
               Modulo = 2;
            }
            break;
       case 1:
            if (PropertyID == 4 || PropertyID == 5) {
               Modulo = 16;
            }
            break;
       case 5:
            if (PropertyID == 4 || PropertyID == 5) {
               Modulo = 15;
            }
            break;
       case 6:
            if (PropertyID == 2) {
               Modulo = 15;
            }
            break;
}
return (float(Value)/Modulo);
};
//---------------------------------------------------------------------------
/*
############################################################################
This routine sets a comparison file to one of the default or currently
edited files.
############################################################################
*/
void __fastcall TCompareFiles::SetFile(TObject *Sender)
{
List->Tag = 0;
List->HelpContext = 0;
if (((TComponent*)(Sender))->Name.Pos("File1") != 0) {
   List->Tag = 1;
}
else if (((TComponent*)(Sender))->Name.Pos("File2") != 0) {
   List->Tag = 2;
}
if (((TComponent*)(Sender))->Name.Pos("Default") != 0) {
   List->HelpContext = 1;
   List->Popup(Mouse->CursorPos.x,Mouse->CursorPos.y);
}
else if (((TComponent*)(Sender))->Name.Pos("Current") != 0) {
   List->HelpContext = 2;
   List->Popup(Mouse->CursorPos.x,Mouse->CursorPos.y);
}
}
//---------------------------------------------------------------------------
/*
############################################################################
This routine marks the currently used file on the filelist.
############################################################################
*/
void __fastcall TCompareFiles::ListPopup(TObject *Sender)
{
for (int i=0;i<11;i++) {
    if (i == Form1->GetPage()) {
       if (List->HelpContext == 2) {
          List->Items->Items[i]->Checked = true;
       }
       else  {
          List->Items->Items[i]->Checked = false;
       }
    }
}
};
//---------------------------------------------------------------------------
/*
############################################################################
This routine loads the path of the default/edited file selected from the list.
############################################################################
*/
void __fastcall TCompareFiles::DATListClickExecute(TObject *Sender)
{
TEdit *Target=NULL;
String Path="";
if (List->Tag == 1) {
   Target = FileName1;
}
else if (List->Tag == 2) {
   Target = FileName2;
}
if (List->HelpContext == 1) {
   Path = String(Form1->GetProgPath()+"Default\\"+GetDATType(((TMenuItem*)(Sender))->MenuIndex)+".dat");
}
else if (List->HelpContext == 2) {
   Path = String(Form1->GetDATFile(((TMenuItem*)(Sender))->MenuIndex)->GetDatName());
}
Target->Text = Path;
Target->Tag = ((TMenuItem*)(Sender))->MenuIndex;
};
//---------------------------------------------------------------------------

void __fastcall TCompareFiles::ActionCompareClick(TObject *Sender)
{
ActionButton->Caption = "Compare!";
ActionButton->Tag = ActionMerge->Checked;
SourceFile1->Enabled = ActionMerge->Checked;
SourceFile2->Enabled = ActionMerge->Checked;
SourceDefault->Enabled = ActionMerge->Checked;
SourceAsk->Enabled = ActionMerge->Checked;
TargetFile1->Enabled = ActionMerge->Checked;
TargetFile2->Enabled = ActionMerge->Checked;
TargetOther->Enabled = ActionMerge->Checked;
}
//---------------------------------------------------------------------------

void __fastcall TCompareFiles::ActionMergeClick(TObject *Sender)
{
ActionButton->Caption = "Merge!";
ActionButton->Tag = ActionMerge->Checked;
SourceFile1->Enabled = ActionMerge->Checked;
SourceFile2->Enabled = ActionMerge->Checked;
SourceDefault->Enabled = ActionMerge->Checked;
SourceAsk->Enabled = ActionMerge->Checked;
TargetFile1->Enabled = ActionMerge->Checked;
TargetFile2->Enabled = ActionMerge->Checked;
TargetOther->Enabled = ActionMerge->Checked;
}
//---------------------------------------------------------------------------


void __fastcall TCompareFiles::SaveMergeResultCanClose(TObject *Sender,
      bool &CanClose)
{
MergeTargetName = "";
if (SaveMergeResult->FileName != "" && !FileExists(SaveMergeResult->FileName) || (FileExists(SaveMergeResult->FileName) && MessageDlg("Are you sure you want to replace the selected DAT file?", mtConfirmation, mbOKCancel, 0) == 1)) {
   MergeTargetName = ChangeFileExt(SaveMergeResult->FileName,".dat");
   CanClose = true;
}
else {
   CanClose = false;  
}
}
//---------------------------------------------------------------------------

