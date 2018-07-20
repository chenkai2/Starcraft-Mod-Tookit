//---------------------------------------------------------------------------

#ifndef OptionsH
#define OptionsH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <Dialogs.hpp>
#include <ComCtrls.hpp>
//---------------------------------------------------------------------------
class TOptionsBox : public TForm
{
__published:	// IDE-managed Components
        TGroupBox *CustomTBLs;
        TLabel *PortdataLabel;
        TLabel *ImagesLabel;
        TLabel *StatLabel;
        TLabel *SfxLabel;
        TLabel *MapdataLabel;
        TEdit *StatPath;
        TEdit *ImagesPath;
        TEdit *PortdataPath;
        TEdit *SfxPath;
        TEdit *MapdataPath;
        TButton *StatLoad;
        TButton *ImagesLoad;
        TButton *PortdataLoad;
        TButton *SfxLoad;
        TButton *MapdataLoad;
        TButton *StatDefault;
        TButton *ImagesDefault;
        TButton *PortdataDefault;
        TButton *SfxDefault;
        TButton *MapdataDefault;
        TGroupBox *CustomIcons;
        TLabel *cmdiconsLabel;
        TButton *IconsDefault;
        TButton *IconsLoad;
        TEdit *IconsPath;
        TGroupBox *GenOptionsPanel;
        TLabel *StartEditorLabel;
        TCheckBox *ConfirmOnExit;
        TCheckBox *UseBackwardReporting;
        TComboBox *StartEditor;
        TCheckBox *ShowHints;
        TCheckBox *ShowSplash;
        TCheckBox *UseCustomLabels;
        TCheckBox *ShowSelCirclePreview;
        TCheckBox *UseOldOpenDirectory;
        TPageControl *OptionsTabs;
        TTabSheet *SettingsTab;
        TTabSheet *CustomPathsTab;
        TButton *OptionsBoxOK;
        TButton *DefaultSize;
        TButton *AssociateDAT;
        TButton *ClearHistory;
        TLabel *ExtGRPSourceLabel;
        TButton *ExtGRPSourceLoad;
        TGroupBox *UnitGRPPrevBox;
        TLabel *UnitSizeLabel;
        TRadioButton *SizePrevOff;
        TRadioButton *SizePrevSimple;
        TRadioButton *SizePrevGRP;
        TEdit *ExtGRPSourcePath;
        TCheckBox *LoadGRPFromMPQ;
        TTabSheet *ExternalProgramsTab;
        TGroupBox *ExternalProgsPanel;
        TButton *AddExternalProg;
        TButton *RemExternalProg;
        TListBox *ExternalProgList;
        TButton *RemAllExternalProgs;
        TLabel *Label1;
        TLabel *Label2;
        TLabel *Label3;
        TOpenDialog *LoadFile;
        void __fastcall FormKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
        void __fastcall DefaultSizeClick(TObject *Sender);
        void __fastcall OptionsBoxOKClick(TObject *Sender);
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
        void __fastcall OptionsCustomFileLoad(TObject *Sender);
        void __fastcall OptionsDefaultClick(TObject *Sender);
        void __fastcall OptionsPathChange(TObject *Sender);
        void __fastcall AssociateDATClick(TObject *Sender);
        void __fastcall UseCustomLabelsClick(TObject *Sender);
        void __fastcall SizePrevClick(TObject *Sender);
        void __fastcall FormShow(TObject *Sender);
        void __fastcall StartEditorChange(TObject *Sender);
        void __fastcall ShowHintsClick(TObject *Sender);
        void __fastcall ConfirmOnExitClick(TObject *Sender);
        void __fastcall ShowSplashClick(TObject *Sender);
        void __fastcall UseBackwardReportingClick(TObject *Sender);
        void __fastcall ShowSelCirclePreviewClick(TObject *Sender);
        void __fastcall UseOldOpenDirectoryClick(TObject *Sender);
        void __fastcall LoadGRPFromMPQClick(TObject *Sender);
        void __fastcall AddExternalProgClick(TObject *Sender);
        void __fastcall RemExternalProgClick(TObject *Sender);
        void __fastcall FormCreate(TObject *Sender);
        void __fastcall RemAllExternalProgsClick(TObject *Sender);
        void __fastcall LoadFileCanClose(TObject *Sender, bool &CanClose);
        void __fastcall ExtGRPSourceLoadClick(TObject *Sender);
        void __fastcall IconsLoadClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TOptionsBox(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TOptionsBox *OptionsBox;
//---------------------------------------------------------------------------
#endif
