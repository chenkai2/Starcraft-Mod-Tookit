//---------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "About.h"
#include "Data.h"
//---------------------------------------------------------------------
#pragma resource "*.dfm"
TAboutBox *AboutBox;
extern "C" Ver;
//---------------------------------------------------------------------
__fastcall TAboutBox::TAboutBox(TComponent* AOwner)
	: TForm(AOwner)
{
}
//---------------------------------------------------------------------
/*
############################################################################
This handler sets the "Datedit" label to display the current version number.
############################################################################
*/
void __fastcall TAboutBox::FormCreate(TObject *Sender)
{
AboutBox->ProductName->Caption = "DatEdit v"+Form1->GetVer();        
}
//---------------------------------------------------------------------------
/*
############################################################################
This handler changes the colour of a label (mail address) when the mouse
is moved over it.
############################################################################
*/
void __fastcall TAboutBox::LabelMouseEnter(TObject *Sender)
{
TLabel* Stuff = (TLabel*) Sender;
Stuff->Font->Color=clBlue;
Stuff->Font->Style=TFontStyles()<< fsUnderline;
}
//---------------------------------------------------------------------------
/*
############################################################################
This handler changes the colour of a label (mail address) when the mouse
is moved away from it.
############################################################################
*/
void __fastcall TAboutBox::LabelMouseLeave(TObject *Sender)
{
TLabel* Stuff = (TLabel*) Sender;
Stuff->Font->Style=TFontStyles();
Stuff->Font->Color=clRed;
}
//---------------------------------------------------------------------------
/*
############################################################################
This handler activates the system's default mailing program when the
mail address is clicked.
############################################################################
*/
void __fastcall TAboutBox::Label6Click(TObject *Sender)
{
String url="mailto:"+AboutBox->Label6->Caption;
ShellExecute(Application->Handle,"open",url.c_str(),"","",SW_SHOW);
}
//---------------------------------------------------------------------------



