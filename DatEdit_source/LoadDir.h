//---------------------------------------------------------------------------

#ifndef LoadDirH
#define LoadDirH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <FileCtrl.hpp>
#include <Dialogs.hpp>
//---------------------------------------------------------------------------
class TOpenDirBox : public TForm
{
__published:	// IDE-managed Components
        TDirectoryListBox *OpenDirView;
        TButton *OpenDirOK;
        TButton *OpenDirCancel;
        TLabel *OpenDirText;
        TDriveComboBox *OpenDirDrive;
        TEdit *OpenDirLabel;
        void __fastcall OpenDirCancelClick(TObject *Sender);
        void __fastcall OpenDirOKClick(TObject *Sender);
        void __fastcall FormKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
        void __fastcall OpenDirViewChange(TObject *Sender);
        void __fastcall FormShow(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TOpenDirBox(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TOpenDirBox *OpenDirBox;
//---------------------------------------------------------------------------
#endif
