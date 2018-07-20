//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "LoadDir.h"
#include "LoadList.h"
#include "Data.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TOpenDirBox *OpenDirBox;
//---------------------------------------------------------------------------
__fastcall TOpenDirBox::TOpenDirBox(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
/*
############################################################################
This routine closes the Load Directory form without doing
anything, if the "Cancel" button is clicked.
############################################################################
*/
void __fastcall TOpenDirBox::OpenDirCancelClick(TObject *Sender)
{
OpenDirBox->Close();
}
//---------------------------------------------------------------------------
/*
############################################################################
Activated with the OK button, this routine runs the function that searches
for DAT files in the user-specificed directory and then closes the form.
############################################################################
*/
void __fastcall TOpenDirBox::OpenDirOKClick(TObject *Sender)
{
if (OpenDirLabel->Text != "") {
   LoadDATDir(OpenDirLabel->Text);
}
OpenDirBox->Close();
}
//---------------------------------------------------------------------------
/*
############################################################################
This routine closes the Load Directory form without doing
anything, if the Escape key is pressed.
############################################################################
*/
void __fastcall TOpenDirBox::FormKeyDown(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
if (Key == VK_ESCAPE) {
   OpenDirBox->Close();
}
}
//---------------------------------------------------------------------------
/*
############################################################################
This routine reflects the changes from the directory listing into the
textbox below.
############################################################################
*/
void __fastcall TOpenDirBox::OpenDirViewChange(TObject *Sender)
{
OpenDirLabel->Text = OpenDirView->Directory;
}
//---------------------------------------------------------------------------
/*
############################################################################
This handler first clears the textbox that stores the directory path,
and then reads the directory form the directory listing above it.
############################################################################
*/
void __fastcall TOpenDirBox::FormShow(TObject *Sender)
{
OpenDirLabel->Text = "";
OpenDirLabel->Text = OpenDirView->Directory;        
}
//---------------------------------------------------------------------------


