//---------------------------------------------------------------------------

#ifndef MultiMPQH
#define MultiMPQH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
//---------------------------------------------------------------------------
class TExportBox : public TForm
{
__published:	// IDE-managed Components
        TLabel *Label3;
        TButton *ExportOK;
        TButton *ExportCancel;
        TCheckBox *KeepExportList;
        TListBox *FileList;
        TListBox *ExportList;
        TButton *AddToExportList;
        TButton *RemoveFromExportList;
        TLabel *Label1;
        TLabel *Label2;
        TGroupBox *ExportOptions;
        TRadioButton *ExportAsMPQ;
        TRadioButton *ExportAsEXE;
        TLabel *Label4;
        void __fastcall ExportOKClick(TObject *Sender);
        void __fastcall FormShow(TObject *Sender);
        void __fastcall FormKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
        void __fastcall AddToExportListClick(TObject *Sender);
        void __fastcall ExportAsMPQClick(TObject *Sender);
private:	// User declarations
public:
       __fastcall TExportBox(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TExportBox *ExportBox;
//---------------------------------------------------------------------------
#endif
