//---------------------------------------------------------------------------

#ifndef CreditsH
#define CreditsH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <Graphics.hpp>
//---------------------------------------------------------------------------
class TCreditsBox : public TForm
{
__published:	// IDE-managed Components
        TPanel *CreditsStuff;
        TLabel *ProductName;
        TLabel *Label1;
        TLabel *Label2;
        TLabel *Label3;
        TLabel *Label5;
        TLabel *Label6;
        TLabel *Label11;
        TLabel *Label12;
        TLabel *Label13;
        TLabel *Label14;
        TButton *OKButton;
        TLabel *Label15;
        TLabel *Label16;
        TLabel *Label4;
        TLabel *Label17;
        TLabel *Label18;
        TLabel *Label19;
        TLabel *Label20;
        TLabel *Label21;
        TLabel *Label22;
        TLabel *Label23;
        TLabel *Label24;
        TLabel *Label25;
        TImage *Image1;
        TImage *Image2;
	TLabel *Label26;
	TLabel *Label27;
	TLabel *Label28;
        TLabel *Label29;
        TLabel *Label30;
        TLabel *Label7;
        TLabel *Label8;
        TLabel *Label9;
        TLabel *Label10;
        TLabel *Label31;
        TLabel *Label32;
        TLabel *Label33;
        TLabel *Label34;
        TLabel *Label35;
        TLabel *Label36;
        TLabel *Label37;
        TLabel *Label38;
        TLabel *Label39;
        TLabel *Label40;
        TLabel *Label41;
        TLabel *Label42;
        TLabel *Label43;
        TLabel *SFlink;
        void __fastcall OKButtonClick(TObject *Sender);
        void __fastcall SFlinkMouseEnter(TObject *Sender);
        void __fastcall SFlinkMouseLeave(TObject *Sender);
        void __fastcall SFlinkClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TCreditsBox(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TCreditsBox *CreditsBox;
//---------------------------------------------------------------------------
#endif
