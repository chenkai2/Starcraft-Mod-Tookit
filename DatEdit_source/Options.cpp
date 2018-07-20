//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include "Options.h"
#include "Main.h"
#include "Data.h"
#include "LoadList.h"
#include "EntryData.h"
#include "SFmpqapi.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TOptionsBox *OptionsBox;
//---------------------------------------------------------------------------
__fastcall TOptionsBox::TOptionsBox(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
/*
############################################################################
This handler loads the Support Programs elements when the form is created.
It is placed here and not in the main form's OnCreate event simply because
when the main form launches this event, the OptionsBox form has not yet
been created :)
############################################################################
*/
void __fastcall TOptionsBox::FormCreate(TObject *Sender)
{
Form1->ExternalProgramsChangeExecute(Form1->ExternalProgramsChange);        
}
//---------------------------------------------------------------------------
/*
############################################################################
When the Options box is shown, this handler reflects the status of the
user-customizable program options in the interface.
############################################################################
*/
void __fastcall TOptionsBox::FormShow(TObject *Sender)
{
StartEditor->ItemIndex = Form1->Options.StartEditor;
ShowHints->Checked = Form1->Options.ShowHints;
ConfirmOnExit->Checked = Form1->Options.ConfirmOnExit;
ShowSplash->Checked = Form1->Options.ShowSplash;
UseBackwardReporting->Checked = Form1->Options.UseBackwardReporting;
UseCustomLabels->Checked = Form1->Options.UseCustomLabels;
ShowSelCirclePreview->Checked = Form1->Options.ShowSelCirclePreview;
UseOldOpenDirectory->Checked = Form1->Options.UseOldOpenDirectory;
LoadGRPFromMPQ->Checked = Form1->Options.LoadGRPFromMPQ;
ExtGRPSourcePath->Text = Form1->Options.ExternalGRPSource;


if (Form1->GetGRPMPQHandle() != NULL) {
   String Path="";
   SFileGetArchiveName(Form1->GetGRPMPQHandle(),Path.c_str(),1024);
   OptionsBox->Caption = Path;
//   ExtGRPSourcePath->Text = Path;
}

if (Form1->Options.UnitSizePreviewType == 0) {
   SizePrevOff->Checked = true;
}
else if (Form1->Options.UnitSizePreviewType == 1) {
   SizePrevSimple->Checked = true;
}
else if (Form1->Options.UnitSizePreviewType == 2) {
   SizePrevGRP->Checked = true;
}
//IF THERE IS NO STARCRAFT INSTALLATION DETECTED,THE GRP PREVIEWS
//SHOULD BE DISABLED
if (Form1->GetIsSC() == false) {
   ShowSelCirclePreview->Enabled = false;
   SizePrevGRP->Enabled = false;
}

StatPath->Text = Form1->TBLs[0].FileName;
ImagesPath->Text = Form1->TBLs[1].FileName;
PortdataPath->Text = Form1->TBLs[2].FileName;
SfxPath->Text = Form1->TBLs[3].FileName;
MapdataPath->Text = Form1->TBLs[4].FileName;
IconsPath->Text = Form1->Icons.FileName;
}
//---------------------------------------------------------------------------
/*
############################################################################
############################################################################
*/
void __fastcall TOptionsBox::FormClose(TObject *Sender, TCloseAction &Action)
{
Form1->ChangeTab->Execute();
};
//---------------------------------------------------------------------------
/*
############################################################################
This handler closes the Options box when the Escape key is pressed.
############################################################################
*/
void __fastcall TOptionsBox::FormKeyDown(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
if (Key == VK_ESCAPE) {
   OptionsBox->Close();
}
};
//---------------------------------------------------------------------------
/*
############################################################################
This handler sets the main form's dimensions to default values, when
the "Default Size" button is clicked.
############################################################################
*/
void __fastcall TOptionsBox::DefaultSizeClick(TObject *Sender)
{
Form1->Width = 800;
Form1->Height = 580;
Form1->InfoText->Width = 205;
Form1->ElGrandoListos->Width = 318;
};
//---------------------------------------------------------------------------
/*
############################################################################
This handler closes the Options box when the OK button is clicked.
############################################################################
*/
void __fastcall TOptionsBox::OptionsBoxOKClick(TObject *Sender)
{
OptionsBox->Close();
};
//---------------------------------------------------------------------------
/*
############################################################################
If the Icons-linked "..." button is clicked, the Icons OpenDialog will
open. If a TBL-linked button is pressed, this routine sets the TBL-loading
OpenDialog's properties: Filter,Tag and Title to values specific to
a particular TBL file (depending on which "..." button was clicked).
############################################################################
*/
void __fastcall TOptionsBox::OptionsCustomFileLoad(TObject *Sender)
{
int TBLTag=-1;
String TBLName="";
if (Sender == StatLoad) {
   TBLTag = 0;
   TBLName = "stat_txt.tbl";
}
else if (Sender == ImagesLoad) {
   TBLTag = 1;
   TBLName = "images.tbl";
}
else if (Sender == PortdataLoad) {
   TBLTag = 2;
   TBLName = "portdata.tbl";
}
else if (Sender == SfxLoad) {
   TBLTag = 3;
   TBLName = "sfxdata.tbl";
}
else if (Sender == MapdataLoad) {
   TBLTag = 4;
   TBLName = "mapdata.tbl";
}
LoadFile->Filter = String(GetTBLType(TBLTag)+".tbl | "+GetTBLType(TBLTag)+".tbl");
LoadFile->Tag = TBLTag;
LoadFile->Execute();
};
//---------------------------------------------------------------------------
/*
############################################################################
When the "Default" button is pressed for a particular link (TBL file or
the Icons link), and if the currently used file is not the default one,
this routine will load the file from the "/default" directory and
mark the appropriate Editors that point to this file to be reloaded.
############################################################################
*/
void __fastcall TOptionsBox::OptionsDefaultClick(TObject *Sender)
{
if (Sender == StatDefault) {
   if (String(Form1->GetProgPath()+"Default\\stat_txt.tbl") != StatPath->Text) {
      StatPath->Text = (Form1->GetProgPath()+"Default\\stat_txt.tbl");
      Form1->TBLs[0].Load(StatPath->Text);
      Form1->SetTBLIsMPQImport(0,false);
      Form1->SetEditorReload(0,true);
      Form1->SetEditorReload(1,true);
      Form1->SetEditorReload(5,true);
      Form1->SetEditorReload(6,true);
      Form1->SetEditorReload(10,true);
   }
}
else if (Sender == ImagesDefault) {
   if (String(Form1->GetProgPath()+"Default\\images.tbl") != ImagesPath->Text) {
      ImagesPath->Text = (Form1->GetProgPath()+"Default\\images.tbl");
      Form1->TBLs[1].Load(ImagesPath->Text);
      Form1->SetTBLIsMPQImport(1,false);
      Form1->SetEditorReload(4,true);
   }
}
else if (Sender == PortdataDefault) {
   if (String(Form1->GetProgPath()+"Default\\portdata.tbl") != PortdataPath->Text) {
      PortdataPath->Text = (Form1->GetProgPath()+"Default\\portdata.tbl");
      Form1->TBLs[2].Load(PortdataPath->Text);
      Form1->SetTBLIsMPQImport(2,false);
      Form1->SetEditorReload(8,true);
   }
}
else if (Sender == SfxDefault) {
   if (String(Form1->GetProgPath()+"Default\\sfxdata.tbl") != SfxPath->Text) {
      SfxPath->Text = (Form1->GetProgPath()+"Default\\sfxdata.tbl");
      Form1->TBLs[3].Load(SfxPath->Text);
      Form1->SetTBLIsMPQImport(3,false);
      Form1->SetEditorReload(7,true);
   }
}
else if (Sender == MapdataDefault) {
   if (String(Form1->GetProgPath()+"Default\\mapdata.tbl") != MapdataPath->Text) {
      MapdataPath->Text = (Form1->GetProgPath()+"Default\\mapdata.tbl");
      Form1->TBLs[4].Load(MapdataPath->Text);
      Form1->SetTBLIsMPQImport(4,false);
      Form1->SetEditorReload(9,true);
   }
}
else if (Sender == IconsDefault) {
   if (String(Form1->GetProgPath()+"Default\\cmdicons.grp") != IconsPath->Text) {
      IconsPath->Text = (Form1->GetProgPath()+"Default\\cmdicons.grp");
      Form1->Icons.Load(IconsPath->Text);
      Form1->SetEditorReload(1,true);
      Form1->SetEditorReload(5,true);
      Form1->SetEditorReload(6,true);
   }
}
};
//---------------------------------------------------------------------------
/*
############################################################################
If the path-containing textbox's content is modified, and if the
target file really exists on the hard drive, this handler will
load this file, set it as NOT being an MPQ-import and mark the
appropriate Editors/Lists, which links to this file to be reloaded.
############################################################################
*/
void __fastcall TOptionsBox::OptionsPathChange(TObject *Sender)
{
if (((TEdit*)(Sender))->Modified == true && FileExists(((TEdit*)(Sender))->Text)) {
   if (Sender == StatPath) {
      Form1->TBLs[0].Load(StatPath->Text);
      Form1->SetTBLIsMPQImport(0,false);
      Form1->SetEditorReload(0,true);
      Form1->SetEditorReload(1,true);
      Form1->SetEditorReload(5,true);
      Form1->SetEditorReload(6,true);
      Form1->SetEditorReload(10,true);

      Form1->SetListReload(0,true);
      Form1->SetListReload(1,true);
      Form1->SetListReload(5,true);
      Form1->SetListReload(6,true);
   }
   else if (Sender == ImagesPath) {
      Form1->TBLs[1].Load(ImagesPath->Text);
      Form1->SetTBLIsMPQImport(1,false);
      Form1->SetEditorReload(4,true);
   }
   else if (Sender == PortdataPath) {
      Form1->TBLs[2].Load(PortdataPath->Text);
      Form1->SetTBLIsMPQImport(2,false);
      Form1->SetEditorReload(8,true);
   }
   else if (Sender == SfxPath) {
      Form1->TBLs[3].Load(SfxPath->Text);
      Form1->SetTBLIsMPQImport(3,false);
      Form1->SetEditorReload(7,true);
   }
   else if (Sender == MapdataPath) {
      Form1->TBLs[4].Load(MapdataPath->Text);
      Form1->SetTBLIsMPQImport(4,false);
      Form1->SetEditorReload(9,true);
   }
   else if (Sender == IconsPath) {
      Form1->Icons.Load(IconsPath->Text);
      Form1->SetIconIsMPQImport(false);
      Form1->SetEditorReload(1,true);
      Form1->SetEditorReload(5,true);
      Form1->SetEditorReload(6,true);
   }
}
};
//---------------------------------------------------------------------------
/*
############################################################################
If the "Associate DATs" button is clicked, this routine will
display a confirmation dialog, and if positive, it will register
DatEdit as the default application for opening them with double-click.
############################################################################
*/
void __fastcall TOptionsBox::AssociateDATClick(TObject *Sender)
{
if (MessageDlg("Are you sure you want to associate DAT files with DatEdit?", mtConfirmation, TMsgDlgButtons() << mbYes << mbNo , 0) == 6) {
   TRegistry *Reg = new TRegistry();
   Reg->RootKey = HKEY_CLASSES_ROOT;
   Reg->OpenKey(".dat", true);
   Reg->WriteString("", "StarCraft.DATfile");
   Reg->CloseKey();

   Reg->OpenKey("StarCraft.DATfile", true);
   Reg->WriteString("", "StarCraft data source file");
   Reg->OpenKey("DefaultIcon", true);
   Reg->WriteString("", ParamStr(0) + ",0");
   Reg->OpenKey("shell", true);
   Reg->WriteString("", "open");
   Reg->OpenKey("open", true);
   Reg->WriteString("", "&Open");
   Reg->OpenKey("command", true);
   Reg->WriteString("", ParamStr(0) + " \"\%1\"");
   Reg->CloseKey();
   MessageDlg("DAT files successfully associated with DatEdit.", mtInformation, TMsgDlgButtons() << mbOK, 0);
   delete Reg;
}
};
//---------------------------------------------------------------------------
/*
############################################################################
The following handlers store modifications to the program's various
options in the Options member structure of the main form.
############################################################################
*/
void __fastcall TOptionsBox::StartEditorChange(TObject *Sender)
{
Form1->Options.StartEditor = StartEditor->ItemIndex;
}

void __fastcall TOptionsBox::ShowHintsClick(TObject *Sender)
{
Form1->Options.ShowHints = ShowHints->Checked;
}

void __fastcall TOptionsBox::ConfirmOnExitClick(TObject *Sender)
{
Form1->Options.ConfirmOnExit = ConfirmOnExit->Checked;
}

void __fastcall TOptionsBox::ShowSplashClick(TObject *Sender)
{
Form1->Options.ShowSplash = ShowSplash->Checked;
}

void __fastcall TOptionsBox::UseBackwardReportingClick(TObject *Sender)
{
Form1->Options.UseBackwardReporting = UseBackwardReporting->Checked;
}

void __fastcall TOptionsBox::ShowSelCirclePreviewClick(TObject *Sender)
{
Form1->Options.ShowSelCirclePreview = ShowSelCirclePreview->Checked;
}

//THIS HANDLER WILL ALSO SET THE 4 CUSTOM NAMES-USING LIST
//TO BE RELOADED.
void __fastcall TOptionsBox::UseCustomLabelsClick(TObject *Sender)
{
Form1->Options.UseCustomLabels = UseCustomLabels->Checked;
Form1->SetListReload(0,true);
Form1->SetListReload(1,true);
Form1->SetListReload(5,true);
Form1->SetListReload(6,true);
}

void __fastcall TOptionsBox::SizePrevClick(TObject *Sender)
{
if (Sender == SizePrevOff) {
   Form1->Options.UnitSizePreviewType = 0;
}
else if (Sender == SizePrevSimple) {
   Form1->Options.UnitSizePreviewType = 1;
}
else if (Sender == SizePrevGRP) {
   Form1->Options.UnitSizePreviewType = 2;
}
};

void __fastcall TOptionsBox::UseOldOpenDirectoryClick(TObject *Sender)
{
Form1->Options.UseOldOpenDirectory = UseOldOpenDirectory->Checked;
}

void __fastcall TOptionsBox::LoadGRPFromMPQClick(TObject *Sender)
{
Form1->Options.LoadGRPFromMPQ = LoadGRPFromMPQ->Checked;
}
//---------------------------------------------------------------------------
/*
############################################################################
This routine launches the Support Program loading dialog.
############################################################################
*/
void __fastcall TOptionsBox::AddExternalProgClick(TObject *Sender)
{
LoadFile->Filter = "All files (*.*)|*.*";
LoadFile->Execute();
}
//---------------------------------------------------------------------------
/*
############################################################################
This handler removes the currently selected element from the Support
Programs list.
############################################################################
*/
void __fastcall TOptionsBox::RemExternalProgClick(TObject *Sender)
{
if (ExternalProgList->ItemIndex != -1) {
   Form1->ExternalPrograms->Delete(ExternalProgList->ItemIndex);
}
};
//---------------------------------------------------------------------------
/*
############################################################################
This handler removes all elements from the Support Programs list.
############################################################################
*/
void __fastcall TOptionsBox::RemAllExternalProgsClick(TObject *Sender)
{
if (MessageDlg("Are you sure you want to remove all external links?",mtConfirmation,TMsgDlgButtons() << mbYes << mbNo,0) == 6) {
   Form1->ExternalPrograms->Clear();
}
}
//---------------------------------------------------------------------------

void __fastcall TOptionsBox::LoadFileCanClose(TObject *Sender,
      bool &CanClose)
{
//CASE 1: Loading External programs
if (LoadFile->Filter.Pos("*.*") != 0) {
   if (FileExists(LoadFile->FileName)) {
      Form1->ExternalPrograms->Add(LoadFile->FileName);
      CanClose = true;
   }
   else {
      MessageDlg("The selected file does not exist!", mtError, TMsgDlgButtons() <<mbOK, 0);
      CanClose=false;
   }
}
//CASE 2: Loading a custom GRP-source MPQ archive
else if (LoadFile->Filter.Pos("mpq") != 0) {
   CanClose = false;
   void *MpqHandle;
   if (Form1->GetGRPMPQHandle() != NULL) {
      SFileCloseArchive(Form1->GetGRPMPQHandle());
   }
   if (SFileOpenArchive(LoadFile->FileName.c_str(),100,0,&MpqHandle) == false) {
      MessageDlg("File is not an MPQ archive.\nYou must choose an MPQ archive.", mtError, TMsgDlgButtons() << mbOK, 0);
      Form1->SetGRPMPQHandle(NULL);
      delete MpqHandle;
   }
   else {
      Form1->SetGRPMPQHandle(MpqHandle);
      ExtGRPSourcePath->Text = LoadFile->FileName;
      Form1->Options.ExternalGRPSource = LoadFile->FileName;
      CanClose = true;
   }
}
//CASE 3: Loading a custom icons file
else if (LoadFile->Filter.Pos("grp") != 0) {
   CanClose = false;
   if (ExtractFileName(LoadFile->FileName).AnsiCompareIC("cmdicons.grp") != 0) {
      MessageDlg("File is not \"cmdicons.grp\".\nYou must choose a \"cmdicons.grp\" file.", mtError, TMsgDlgButtons() << mbOK, 0);
      CanClose = false;
   }
   else if (ExtractFileName(LoadFile->FileName).AnsiCompareIC("cmdicons.grp") == 0) {
      IconsPath->Text = LoadFile->FileName;
      Form1->SetIconIsMPQImport(false);
      Form1->Icons.Load(LoadFile->FileName);
      Form1->SetEditorReload(1,true);
      Form1->SetEditorReload(5,true);
      Form1->SetEditorReload(6,true);
      CanClose = true;
   }
}
//CASE 4: Loading custom TBL files
else if (LoadFile->Filter.Pos("tbl") != 0) {
   if (ExtractFileExt(LoadFile->FileName).AnsiCompareIC(".tbl") != 0) {
      MessageDlg("The selected file is not a TBL file. Please choose a TBL file.", mtError, TMsgDlgButtons() <<mbOK, 0);
      CanClose = false;
   }
   else {
      for (int i=0;i<5;i++) {
          if (LoadFile->Tag == i) {
             if (ExtractFileName(LoadFile->FileName).AnsiCompareIC(GetTBLType(i)+".tbl") != 0) {
                CanClose = false;
                MessageDlg("File is not \""+GetTBLType(i)+".tbl\".",mtError,TMsgDlgButtons() <<mbOK,0);
             }
             else if (ExtractFileName(LoadFile->FileName).AnsiCompareIC(GetTBLType(i)+".tbl") == 0) {
                CanClose = true;
                Form1->SetTBLIsMPQImport(i,false);
                switch (i) {
                case 0:
                  StatPath->Text = LoadFile->FileName;
                  Form1->TBLs[LoadFile->Tag].Load(StatPath->Text);
                  Form1->SetEditorReload(0,true);
                  Form1->SetEditorReload(1,true);
                  Form1->SetEditorReload(5,true);
                  Form1->SetEditorReload(6,true);
                  Form1->SetEditorReload(10,true);
                  break;
                case 1:
                  ImagesPath->Text = LoadFile->FileName;
                  Form1->TBLs[LoadFile->Tag].Load(ImagesPath->Text);
                  Form1->SetEditorReload(4,true);
                  break;
                case 2:
                  PortdataPath->Text = LoadFile->FileName;
                  Form1->TBLs[LoadFile->Tag].Load(PortdataPath->Text);
                  Form1->SetEditorReload(8,true);
                  break;
                case 3:
                  SfxPath->Text = LoadFile->FileName;
                  Form1->TBLs[LoadFile->Tag].Load(SfxPath->Text);
                  Form1->SetEditorReload(7,true);
                  break;
                case 4:
                  MapdataPath->Text = LoadFile->FileName;
                  Form1->TBLs[LoadFile->Tag].Load(MapdataPath->Text);
                  Form1->SetEditorReload(9,true);
                  break;
                }
             }
          }
      }
   }
}
};
//---------------------------------------------------------------------------

void __fastcall TOptionsBox::ExtGRPSourceLoadClick(TObject *Sender)
{
LoadFile->Filter = "MPQ archives (*.mpq)|*.mpq";
LoadFile->Execute();
}
//---------------------------------------------------------------------------

void __fastcall TOptionsBox::IconsLoadClick(TObject *Sender)
{
LoadFile->Filter = "GRP files (*.grp)|*.grp";
LoadFile->Execute();
}
//---------------------------------------------------------------------------

