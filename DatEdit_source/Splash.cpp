//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Splash.h"
#include "Main.h"
#include "Options.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TSplashForm *SplashForm;
//---------------------------------------------------------------------------
__fastcall TSplashForm::TSplashForm(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
/*
############################################################################
This handler hides the splash screen and shows the main program form
if any key is pressed.
############################################################################
*/
void __fastcall TSplashForm::FormKeyDown(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
SplashForm->Close();
Form1->Show();
}
//---------------------------------------------------------------------------
/*
############################################################################
This handler hides the splash screen and shows the main program form
if the user clicks on the splash image.
############################################################################
*/
void __fastcall TSplashForm::SplashImageClick(TObject *Sender)
{
SplashForm->Close();
Form1->Show();
}
//---------------------------------------------------------------------------
/*
############################################################################
If the "Show Splash" option is turned on, this handler sets the version
label to show the current version and brings the Splash form to front.
############################################################################
*/
void __fastcall TSplashForm::FormCreate(TObject *Sender)
{
if (Form1->Options.ShowSplash == true) {
   Version->Caption = "v"+Form1->GetVer();
   SplashForm->Show();
   SplashForm->BringToFront();
}
else {
   Form1->Show();
}
}
//---------------------------------------------------------------------------

