//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "ProgressForm.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TProgForm *ProgForm;
//---------------------------------------------------------------------------
__fastcall TProgForm::TProgForm(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
/*
############################################################################
This handler, activated when this form is shown (mostly programmatically
from within other routines) sets the progress bar's Position to 0, i.e.
clears out traces of any previous progress bar actions.
############################################################################
*/
void __fastcall TProgForm::FormShow(TObject *Sender)
{
ProgForm->ProgressBar->Position=0;         
}
//---------------------------------------------------------------------------

