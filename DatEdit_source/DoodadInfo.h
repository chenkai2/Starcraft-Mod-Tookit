//----------------------------------------------------------------------------
#ifndef DoodadInfoH
#define DoodadInfoH
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
#include <ComCtrls.hpp>
//----------------------------------------------------------------------------
class TDoodadInfoBox : public TForm
{
__published:
        TPanel *DoodadInfoPanel;
	TButton *OKButton;
        TLabel *Label1;
        TLabel *Label2;
        TLabel *Label3;
        TLabel *Label4;
        TLabel *Label5;
        TLabel *Label6;
        TLabel *Label7;
        TMemo *Memo1;
        TMemo *Memo2;
        TMemo *Memo3;
        TMemo *Memo4;
        TMemo *Memo5;
        TMemo *Memo6;
        TMemo *Memo7;
        TMemo *Memo8;
        TLabel *Label8;
        TLabel *Label9;
        TMemo *Memo9;
        TMemo *Memo10;
        TMemo *Memo11;
        TMemo *Memo12;
        TMemo *Memo13;
        TMemo *Memo14;
        TMemo *Memo15;
        TMemo *Memo16;
        void __fastcall OKButtonClick(TObject *Sender);
        void __fastcall FormKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
private:
public:
	virtual __fastcall TDoodadInfoBox(TComponent* AOwner);
};
//----------------------------------------------------------------------------
extern PACKAGE TDoodadInfoBox *DoodadInfoBox;
//----------------------------------------------------------------------------
#endif    
