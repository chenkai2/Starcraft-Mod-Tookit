//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "SavePatch.h"
#include "Funcs.h"
#include "Resources.h"
#include "SFmpqapi.h"
#include "Main.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
#pragma warn -aus

TPatchSaveForm *PatchSaveForm;
//---------------------------------------------------------------------------
__fastcall TPatchSaveForm::TPatchSaveForm(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
/*
############################################################################
Code provided courtesy of DiscipleOfAdun, interface adapted by me.
############################################################################
*/
void TPatchSaveForm::SetPaths(String szExe, String szMpq)
{
PatchSaveForm->ExePath = szExe;
PatchSaveForm->MpqPath = szMpq;
};
//---------------------------------------------------------------------------

bool TPatchSaveForm::CanSave()
{
        return FileExists(MpqPath);
};

void __fastcall TPatchSaveForm::FormShow(TObject *Sender)
{
        ClearPlugins();
}
//---------------------------------------------------------------------------

void __fastcall TPatchSaveForm::AddQDPClick(TObject *Sender)
{
        OFD->Title = "Open";
        OFD->FileName = "";
	OFD->DefaultExt = ".qdp";
        OFD->Filter = "MPQDraft Plugins(*.qdp)|*.qdp";

        if (OFD->Execute()) {
           QDPluginAdd(OFD->FileName.c_str());
        }
}
//---------------------------------------------------------------------------

void __fastcall TPatchSaveForm::ConfigQDPClick(TObject *Sender)
{
        if (!QDPluginConfig()) {
           Application->MessageBox("The selected plugin was unable to complete configuration.  It has been removed to prevent errors.", "Error: Configuration Fail", MB_OK);
        }
}
//---------------------------------------------------------------------------

void __fastcall TPatchSaveForm::RemoveQDPClick(TObject *Sender)
{
        QDPluginRemove();        
}
//---------------------------------------------------------------------------

void __fastcall TPatchSaveForm::PatchSetupOKClick(TObject *Sender)
{
        if (FileExists(ExePath)) {
           ReplaceMPQ(ExePath.c_str(), MpqPath.c_str());
        }
        else {
           SaveExe(ExePath.c_str(), MpqPath.c_str());
        }
        ModalResult = mrOk;
}
//---------------------------------------------------------------------------
void TPatchSaveForm::SaveExe(LPSTR szExe, LPSTR szMpq)
{
        int fh, i, iCur;
        DWORD dwMagic, dwMPQCount, dwPluginCount;
        DWORD dwSize, dwOffset, j;
        LPVOID lpData;
        MPQDRAFTPLUGIN * lpMPQDraftPlugin;

        //Create the file
        fh = FileCreate(szExe);

        if (fh == -1) {
           Application->MessageBox("Unable to create the target file.", "Error: FileCreate Failed", MB_ICONSTOP|MB_OK);
           return;
        }

        //Load the stub exe from this exe and write it out.
        lpData = LoadResource(MAKEINTRESOURCE(IDR_PATCHLOADER), "Stub", &dwSize);
        FileWrite(fh, lpData, dwSize);
        FileSeek(fh, (int)dwSize, 0);

        dwOffset = dwSize;

        // write patch header
        dwMagic = 'FGEP';
        dwMPQCount = 1;
        dwPluginCount = QDPList->Items->Count;
        FileWrite(fh, &dwMagic, sizeof(DWORD));
        FileWrite(fh, &dwPluginCount, sizeof(DWORD));
        FileWrite(fh, &dwMPQCount, sizeof(DWORD));

        // write mpqd plugins
        for (unsigned i = 0; i < dwPluginCount; i++) {
            lpMPQDraftPlugin = (MPQDRAFTPLUGIN*)QDPList->Items->Objects[i];

            FileWrite(fh, &lpMPQDraftPlugin->dwComponentID, sizeof(DWORD));
            FileWrite(fh, &lpMPQDraftPlugin->dwSize, sizeof(DWORD));
            FileWrite(fh, &lpMPQDraftPlugin->dwPluginModules, sizeof(DWORD));
            FileWrite(fh, lpMPQDraftPlugin->lpData, lpMPQDraftPlugin->dwSize);

            for (j=0; j<lpMPQDraftPlugin->dwPluginModules; j++) {
                FileWrite(fh, &lpMPQDraftPlugin->lpPluginModulesData[j].dwModuleID, sizeof(DWORD));
                FileWrite(fh, &lpMPQDraftPlugin->lpPluginModulesData[j].dwDataSize, sizeof(DWORD));
                FileWrite(fh, lpMPQDraftPlugin->lpPluginModulesData[j].lpData, lpMPQDraftPlugin->lpPluginModulesData[j].dwDataSize);
            }
        }

        //write the mpq.
        iCur = FileSeek(fh, 0, 1);
        if ((iCur%512)) {
           iCur = FileSeek(fh, 512-(iCur%512), 1);
        }

        ReadWholeFile(szMpq, &lpData, &dwSize);
        FileWrite(fh, lpData, dwSize);
        delete[] lpData;

        // abuse an unused field in the DOS header
        FileSeek(fh, 24, 0);
        FileWrite(fh, &dwOffset, sizeof(DWORD));

        FileClose(fh);
};
//---------------------------------------------------------------------------

void TPatchSaveForm::ReplaceMPQ(LPSTR szExe, LPSTR szMpq)
{
        TMemoryStream * exe = new TMemoryStream();
        int h = FileOpen(szExe, fmOpenRead);
        int pos = SFileFindMpqHeader((void*)h);
        if (pos == -1) {
           return;
        }
        LPVOID data = new char[pos];
        FileSeek(h, 0, 0);
        FileRead(h, data, pos);
        FileClose(h);
        exe->Write(data, pos);
        delete[] data;

        h = FileOpen(szMpq, fmOpenRead);
        pos = FileSeek(h, 0, 2);
        FileSeek(h, 0, 0);
        data = new char[pos];
        FileRead(h, data, pos);
        FileClose(h);
        exe->Write(data, pos);
        delete[] data;

        exe->SaveToFile(szExe);
};
//---------------------------------------------------------------------------

#pragma nopackwarning 
