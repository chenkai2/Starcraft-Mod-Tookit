//---------------------------------------------------------------------------

#ifndef SavePatchH
#define SavePatchH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Dialogs.hpp>
//---------------------------------------------------------------------------
class TPatchSaveForm : public TForm
{
__published:	// IDE-managed Components
        TListBox *QDPList;
        TButton *AddQDP;
        TButton *ConfigQDP;
        TButton *RemoveQDP;
        TLabel *Label1;
        TButton *PatchSetupOK;
        TOpenDialog *OFD;
        void __fastcall FormShow(TObject *Sender);
        void __fastcall AddQDPClick(TObject *Sender);
        void __fastcall ConfigQDPClick(TObject *Sender);
        void __fastcall RemoveQDPClick(TObject *Sender);
        void __fastcall PatchSetupOKClick(TObject *Sender);
private:	// User declarations
        String ExePath;
        String MpqPath;
public:		// User declarations
        __fastcall TPatchSaveForm(TComponent* Owner);
        void SetPaths(String szExe, String szMpq);
        bool CanSave();

        void SaveExe(LPSTR szExe, LPSTR szMpq);
        void ReplaceMPQ(LPSTR szExe, LPSTR szMpq);
        //QDP
        void ClearPlugins();
        bool QDPluginAdd(LPSTR path);
        bool QDPluginConfig();
        void QDPluginRemove();
};
//---------------------------------------------------------------------------
extern PACKAGE TPatchSaveForm *PatchSaveForm;
//---------------------------------------------------------------------------
#endif
