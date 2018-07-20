//----------------------------------------------------------------------------
#ifndef AboutH
#define AboutH
//----------------------------------------------------------------------------
#include <vcl\System.hpp>
#include <vcl\Windows.hpp>
#include <vcl\SysUtils.hpp>
#include <vcl\Classes.hpp>
#include <vcl\Graphics.hpp>
#include <vcl\Forms.hpp>
#include <vcl\Controls.hpp>
#include <vcl\StdCtrls.hpp>
#include <vcl\Buttons.hpp>
#include <vcl\ExtCtrls.hpp>
#include <jpeg.hpp>
//----------------------------------------------------------------------------
class TAboutBox : public TForm
{
__published:
	TPanel *Panel1;
	TLabel *ProductName;
        TLabel *Label1;
        TLabel *Label11;
        TLabel *Label2;
        TLabel *Label5;
        TLabel *Label6;
        TLabel *Label3;
        TLabel *Label4;
        TLabel *Label8;
        TLabel *Label9;
        TButton *OKButton;
        TImage *Image1;
        TPanel *Panel2;
        void __fastcall FormCreate(TObject *Sender);
        void __fastcall LabelMouseEnter(TObject *Sender);
        void __fastcall LabelMouseLeave(TObject *Sender);
        void __fastcall Label6Click(TObject *Sender);
private:
public:
	virtual __fastcall TAboutBox(TComponent* AOwner);
};
//----------------------------------------------------------------------------
extern PACKAGE TAboutBox *AboutBox;
//----------------------------------------------------------------------------
#endif    
