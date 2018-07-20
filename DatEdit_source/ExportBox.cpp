//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "ExportBox.h"
#include "Data.h"
#include "Main.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TExportBox *ExportBox;
//---------------------------------------------------------------------------
__fastcall TExportBox::TExportBox(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
/*
############################################################################
This routine, activated by the OK button, analyzes the export list,
and passes this info over to the program's main form (the call to
Form1->SetMultiMPQIcons() near the end), which is then used in the
exporting routine.
############################################################################
*/
void __fastcall TExportBox::ExportOKClick(TObject *Sender)
{
bool ExportDats[11];
bool ExportTBLs[5];
bool ExportIcons=false;
bool DatToExport=false;
int ExportCount=0;
Form1->ExportSaveDialog->Tag = 0;

for (int i=0;i<11;i++) {
    ExportDats[i] = false;
    if (ExportList->Items->IndexOf(GetDATType(i)+".dat") != -1) {
       ExportDats[i] = true;
       DatToExport = true;
       ExportCount++;
    }
}
for (int i=0;i<5;i++) {
    ExportTBLs[i] = false;
    if (ExportList->Items->IndexOf(GetTBLType(i)+".tbl") != -1) {
       ExportTBLs[i] = true;
       ExportCount++;
    }
}
if (ExportList->Items->IndexOf("cmdicons.grp") != -1) {
   ExportIcons = true;
   ExportCount++;
}

ExportBox->ModalResult = mrNone;
if (DatToExport == true) {
   for (int i=0;i<11;i++) {
       Form1->SetDatExport(i,ExportDats[i]);
       if (i<5) {
          Form1->SetTBLExport(i,ExportTBLs[i]);
       }
   }
   Form1->SetIconExport(ExportIcons);
   Form1->ExportSaveDialog->Tag = ExportCount;
   ExportBox->ModalResult = mrOk;
}
else {
   MessageDlg("No DAT files selected for exporting. It's DAT-Edit, allright? Please choose at least 1 DAT file for export.Thank you.", mtError, TMsgDlgButtons() << mbOK, 0);
}
}
//---------------------------------------------------------------------------
/*
############################################################################
This routine checks if the file lists are empty and fill up the list
if necessary, or leaves it if the 'Keep the export list' is checked.
############################################################################
*/
void __fastcall TExportBox::FormShow(TObject *Sender)
{
if (KeepExportList->Checked == false) {
   FileList->Items->Clear();
   ExportList->Items->Clear();
}

if (FileList->Items->Count == 0 && ExportList->Items->Count == 0) {
   for (int i=0;i<11;i++) {
       FileList->Items->Add(GetDATType(i)+".dat");
   }
   for (int i=0;i<5;i++) {
       FileList->Items->Add(GetTBLType(i)+".tbl");
   }
   FileList->Items->Add("cmdicons.grp");
}
FileList->SetFocus();
if (FileList->Items->Count > 0) {
   FileList->Selected[0] = true;
}
ExportAsMPQ->Checked = true;
}
//---------------------------------------------------------------------------
/*
############################################################################
This routine closes the Export dialog without doing anything when
the Escape key is pressed.
############################################################################
*/
void __fastcall TExportBox::FormKeyDown(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
if (Key == VK_ESCAPE) {
   ExportBox->Close();
}
}
//---------------------------------------------------------------------------
/*
############################################################################
This routine moves the selected entries between the two lists.
############################################################################
*/
void __fastcall TExportBox::AddToExportListClick(TObject *Sender)
{
TListBox *Source,*Target;
if (Sender == AddToExportList) {
   Source = FileList;
   Target = ExportList;
}
else if (Sender == RemoveFromExportList) {
   Source = ExportList;
   Target = FileList;
}
if (Source->SelCount > 0) {
   Source->MoveSelection(Target);
   if (Source->Items->Count > 0) {
      if (Source->ItemIndex+1 == Source->Items->Count || Source->ItemIndex == 0) {
         Source->Selected[Source->ItemIndex] = true;
      }
      else {
         Source->Selected[Source->ItemIndex+1] = true;
      }
   }
}
}
//---------------------------------------------------------------------------
/*
############################################################################
This handler sets the appropriate property if the file(s) are to be exported
to a Self-executable MPQ file.
############################################################################
*/

void __fastcall TExportBox::ExportAsMPQClick(TObject *Sender)
{
Form1->SetSEExport(ExportAsEXE->Checked);
}
//---------------------------------------------------------------------------



