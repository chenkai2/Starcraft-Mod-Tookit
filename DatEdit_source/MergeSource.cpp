//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "MergeSource.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TMergeDialog *MergeDialog;
//---------------------------------------------------------------------------
__fastcall TMergeDialog::TMergeDialog(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void TMergeDialog::SetProperty(String property,double Value1,double Value2,double DefaultValue)
{
PropertyInfo->Items->Clear();
PropertyInfo->AddItem(property,NULL);
PropertyInfo->Items->Item[0]->SubItems->Add(Value1);
PropertyInfo->Items->Item[0]->SubItems->Add(Value2);
PropertyInfo->Items->Item[0]->SubItems->Add(DefaultValue);
};
//---------------------------------------------------------------------------

void __fastcall TMergeDialog::SourceFile1Click(TObject *Sender)
{
SourceOk->ModalResult = mrYes;
}
//---------------------------------------------------------------------------

void __fastcall TMergeDialog::SourceFile2Click(TObject *Sender)
{
SourceOk->ModalResult = mrNo;
}
//---------------------------------------------------------------------------

void __fastcall TMergeDialog::SourceDefaultClick(TObject *Sender)
{
SourceOk->ModalResult = mrAll;
}
//---------------------------------------------------------------------------


