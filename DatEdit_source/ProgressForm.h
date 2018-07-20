//---------------------------------------------------------------------------

#ifndef ProgressFormH
#define ProgressFormH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ComCtrls.hpp>
//---------------------------------------------------------------------------
class TProgForm : public TForm
{
__published:	// IDE-managed Components
        TProgressBar *ProgressBar;
        void __fastcall FormShow(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TProgForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TProgForm *ProgForm;
//---------------------------------------------------------------------------
#endif
