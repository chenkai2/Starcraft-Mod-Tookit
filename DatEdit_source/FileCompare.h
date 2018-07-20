//---------------------------------------------------------------------------

#ifndef FileCompareH
#define FileCompareH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ComCtrls.hpp>
#include <Dialogs.hpp>
#include <SysUtils.hpp>
#include <ImgList.hpp>
#include <ActnList.hpp>
#include <StrUtils.hpp>
#include <ExtCtrls.hpp>
#include <Menus.hpp>
//---------------------------------------------------------------------------
class TCompareFiles : public TForm
{
__published:	// IDE-managed Components
        TLabel *LabelFile1;
        TButton *BrowseFile1;
        TGroupBox *CompareFilesBox;
        TEdit *FileName1;
        TLabel *LabelFile2;
        TButton *BrowseFile2;
        TButton *ActionButton;
        TListView *CompareResult;
        TOpenDialog *OpenDialog;
        TImageList *ImageList1;
        TLabel *Label1;
        TButton *SetFile1ToCurrent;
        TEdit *FileName2;
        TLabel *Label2;
        TButton *SetFile2ToDefault;
        TButton *SetFile2ToCurrent;
        TBevel *Bevel1;
        TButton *SetFile1ToDefault;
        TPopupMenu *List;
        TActionList *ActionList1;
        TAction *DATListClick;
        TMenuItem *Units1;
        TMenuItem *Weapons1;
        TMenuItem *Flindy1;
        TMenuItem *Sprites1;
        TMenuItem *Images1;
        TMenuItem *Upgrades1;
        TMenuItem *Tech1;
        TMenuItem *Sounds1;
        TMenuItem *Portraits1;
        TMenuItem *Map1;
        TMenuItem *Orders1;
        TRadioButton *ActionCompare;
        TRadioButton *ActionMerge;
        TGroupBox *MergeOptions;
        TRadioButton *SourceDefault;
        TRadioButton *SourceAsk;
        TRadioButton *SourceFile1;
        TRadioButton *SourceFile2;
        TGroupBox *MergeResult;
        TRadioButton *TargetOther;
        TRadioButton *TargetFile1;
        TRadioButton *TargetFile2;
        TSaveDialog *SaveMergeResult;
        void __fastcall FormShow(TObject *Sender);
        void __fastcall BrowseFileClick(TObject *Sender);
        void __fastcall OpenDialogCanClose(TObject *Sender,
          bool &CanClose);
        void __fastcall ActionButtonClick(TObject *Sender);
        void __fastcall FormKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
        void __fastcall SetFile(TObject *Sender);
        void __fastcall ListPopup(TObject *Sender);
        void __fastcall DATListClickExecute(TObject *Sender);
        void __fastcall ActionCompareClick(TObject *Sender);
        void __fastcall ActionMergeClick(TObject *Sender);
        void __fastcall SaveMergeResultCanClose(TObject *Sender,
          bool &CanClose);
        
private:	// User declarations
public:		// User declarations
        float ConvertValue (int Value,int DATTypeID,int PropertyID);        
        __fastcall TCompareFiles(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TCompareFiles *CompareFiles;
//---------------------------------------------------------------------------
#endif
