//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Credits.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TCreditsBox *CreditsBox;
//---------------------------------------------------------------------------
__fastcall TCreditsBox::TCreditsBox(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
/*
############################################################################
This routine closes the Credits form when the OK button is clicked.
############################################################################
*/
void __fastcall TCreditsBox::OKButtonClick(TObject *Sender)
{
CreditsBox->Close();
};
//---------------------------------------------------------------------------



void __fastcall TCreditsBox::SFlinkMouseEnter(TObject *Sender)
{
SFlink->Font->Style = TFontStyles() << fsUnderline;
}
//---------------------------------------------------------------------------

void __fastcall TCreditsBox::SFlinkMouseLeave(TObject *Sender)
{
SFlink->Font->Style = TFontStyles();
}
//---------------------------------------------------------------------------

void __fastcall TCreditsBox::SFlinkClick(TObject *Sender)
{
String url="http://"+SFlink->Caption;
ShellExecute(Application->Handle,"open",url.c_str(),"","",SW_SHOW);
}
//---------------------------------------------------------------------------

