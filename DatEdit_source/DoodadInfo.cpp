//---------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "DoodadInfo.h"
//--------------------------------------------------------------------- 
#pragma resource "*.dfm"
TDoodadInfoBox *DoodadInfoBox;
//--------------------------------------------------------------------- 
__fastcall TDoodadInfoBox::TDoodadInfoBox(TComponent* AOwner)
	: TForm(AOwner)
{
}
//---------------------------------------------------------------------
/*
############################################################################
This routine closes the "Doodad Info" box when the OK button is clicked.
############################################################################
*/
void __fastcall TDoodadInfoBox::OKButtonClick(TObject *Sender)
{
DoodadInfoBox->Close();        
}
//---------------------------------------------------------------------------
/*
############################################################################
This routine closes the "Doodan Info" box if the Escape key is pressed.
############################################################################
*/
void __fastcall TDoodadInfoBox::FormKeyDown(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
if (Key == VK_ESCAPE) {
   DoodadInfoBox->Close();
}
}
//---------------------------------------------------------------------------



