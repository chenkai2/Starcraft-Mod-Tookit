//---------------------------------------------------------------------------

#ifndef MergeSourceH
#define MergeSourceH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <ComCtrls.hpp>
//---------------------------------------------------------------------------
class TMergeDialog : public TForm
{
__published:	// IDE-managed Components
        TPanel *Panel1;
        TLabel *Label1;
        TButton *SourceOk;
        TListView *PropertyInfo;
        TRadioButton *SourceFile1;
        TRadioButton *SourceFile2;
        TRadioButton *SourceDefault;
        void __fastcall SourceFile1Click(TObject *Sender);
        void __fastcall SourceFile2Click(TObject *Sender);
        void __fastcall SourceDefaultClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
        void SetProperty(String property,double Value1,double Value2,double DefaultValue);
        __fastcall TMergeDialog(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TMergeDialog *MergeDialog;
//---------------------------------------------------------------------------
#endif
