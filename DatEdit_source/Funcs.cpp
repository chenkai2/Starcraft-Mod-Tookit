//---------------------------------------------------------------------------


#pragma hdrstop

#include "Funcs.h"
#include "SavePatch.h"

//---------------------------------------------------------------------------
/*
############################################################################
Code provided courtesy of DiscipleOfAdun.
############################################################################
*/
#pragma package(smart_init)

void TPatchSaveForm::ClearPlugins()
{
        for (int i = 0; i < QDPList->Items->Count; i++)
        {
                MPQDRAFTPLUGIN * lpMPQDraftPlugin = (MPQDRAFTPLUGIN*)QDPList->Items->Objects[i];
                delete[] lpMPQDraftPlugin->lpPluginModules;
                for (unsigned int j = 0; j < lpMPQDraftPlugin->dwPluginModules; j++)
	                delete[] lpMPQDraftPlugin->lpPluginModulesData[j].lpData;
		delete[] lpMPQDraftPlugin->lpPluginModulesData;
                delete lpMPQDraftPlugin;
        }
        QDPList->Clear();
};

bool TPatchSaveForm::QDPluginAdd(LPSTR path)
{
        MPQDRAFTPLUGIN * lpMPQDraftPlugin = new MPQDRAFTPLUGIN;
	if(!lpMPQDraftPlugin)
	{
		Application->MessageBox("Out of Memory!", "Error: Memory", MB_ICONSTOP|MB_OK);
		return FALSE;
	}

	// Initialize the plugin data structure
	ZeroMemory(lpMPQDraftPlugin, sizeof(MPQDRAFTPLUGIN));

	strcpy(lpMPQDraftPlugin->szMPQDraftPlugin, path);
	// Load the Plugin
	lpMPQDraftPlugin->hQDP = LoadLibrary(lpMPQDraftPlugin->szMPQDraftPlugin);
	if(!lpMPQDraftPlugin->hQDP)
	{
		delete lpMPQDraftPlugin;
		Application->MessageBox("This file is not a valid MPQDraft Plugin.", "Error: Invalid File", MB_ICONSTOP|MB_OK);
		return FALSE;
	}

	// Search for the main initialisation function
	GetMPQDraftPlugin_ GetMPQDraftPlugin = (GetMPQDraftPlugin_)GetProcAddress(lpMPQDraftPlugin->hQDP, "GetMPQDraftPlugin");
	if(!GetMPQDraftPlugin)
	{
		FreeLibrary(lpMPQDraftPlugin->hQDP);
		delete lpMPQDraftPlugin;
		Application->MessageBox("This file is not a valid MPQDraft Plugin.", "Error: Invalid File", MB_ICONSTOP|MB_OK);
		return FALSE;
	}

	// Get an instance of the plugin-interface
	if(!GetMPQDraftPlugin(&lpMPQDraftPlugin->lpIMPQDraftPlugin) || lpMPQDraftPlugin->lpIMPQDraftPlugin==0)
	{
		FreeLibrary(lpMPQDraftPlugin->hQDP);
		delete lpMPQDraftPlugin;
		Application->MessageBox("Could not get the MPQDraft Plugin Interface.", "Error: Invalid Plugin Interface", MB_ICONSTOP|MB_OK);
		return FALSE;
	}

	if(!lpMPQDraftPlugin->lpIMPQDraftPlugin->Identify(&lpMPQDraftPlugin->dwComponentID))
	{
		FreeLibrary(lpMPQDraftPlugin->hQDP);
		delete lpMPQDraftPlugin;
		Application->MessageBox("Could not get the MPQDraft Plugin Identifier.", "Error: Invalid MPQDraft Plugin", MB_ICONSTOP|MB_OK);
		return FALSE;
	}

        for (int i = 0; i < QDPList->Items->Count; i++)
        {
                MPQDRAFTPLUGIN * a = (MPQDRAFTPLUGIN*)QDPList->Items->Objects[i];
                if (a->dwComponentID == lpMPQDraftPlugin->dwComponentID)
                {
                        FreeLibrary(lpMPQDraftPlugin->hQDP);
                        delete lpMPQDraftPlugin;
                        Application->MessageBox("A plugin with that ID is loaded already.", "Error: Duplicate MPQDraft Plugin ID", MB_ICONSTOP|MB_OK);
                        return false;
                }
        }

	if(!lpMPQDraftPlugin->lpIMPQDraftPlugin->GetPluginName(lpMPQDraftPlugin->szMPQDraftPluginName, MPQDRAFT_MAX_PLUGIN_NAME) || lpMPQDraftPlugin->szMPQDraftPluginName[0]=='\0')
	{
		FreeLibrary(lpMPQDraftPlugin->hQDP);
		delete lpMPQDraftPlugin;
		Application->MessageBox("Could not get the MPQDraft Plugin Name.", "Error: Invalid Plugin Name", MB_ICONSTOP|MB_OK);
		return FALSE;
	}
        //Removed because it doesn't need to be in here.
        /*if (!lpMPQDraftPlugin->lpIMPQDraftPlugin->CanPatchExecutable(//STARCRAFT PATH//))
        {
                FreeLibrary(lpMPQDraftPlugin->hQDP);
                delete lpMPQDraftPlugin;
                Application->MessageBox("This plugin cannot be applied to the current exe.", "Error: MPQDraft Plugin Version", MB_ICONSTOP|MB_OK);
                return FALSE;
        }*/

	lpMPQDraftPlugin->fIsConfigured = lpMPQDraftPlugin->lpIMPQDraftPlugin->ReadyForPatch();

        if (!lpMPQDraftPlugin->fIsConfigured)
    	        Application->MessageBox("This plugin requires configuration!\nThe configuration dialog of the selected plugin will now be called!", "Information", MB_OK);

	while(!lpMPQDraftPlugin->fIsConfigured)
	{       //CHANGE THE HANDLE TO A CURRENT VERSION OF THE EXE
		if(!lpMPQDraftPlugin->lpIMPQDraftPlugin->Configure(Application->Handle))
		{
			FreeLibrary(lpMPQDraftPlugin->hQDP);
			delete lpMPQDraftPlugin;
			Application->MessageBox("Plugin configuration failed!", "Error: MPQDraft Plugin Configuration", MB_OK);
			return FALSE;
		}
		lpMPQDraftPlugin->fIsConfigured = lpMPQDraftPlugin->lpIMPQDraftPlugin->ReadyForPatch();
		if(!lpMPQDraftPlugin->fIsConfigured)
		{
			if(Application->MessageBox("The plugin is still not configured correctly, do you want to try again?", "Error: Configuration Failed", MB_YESNO)==IDNO)
			{
				FreeLibrary(lpMPQDraftPlugin->hQDP);
				delete lpMPQDraftPlugin;
				return FALSE;
			}
		}
	}

	if(!lpMPQDraftPlugin->lpIMPQDraftPlugin->GetModules(NULL, &lpMPQDraftPlugin->dwPluginModules))
	{
		FreeLibrary(lpMPQDraftPlugin->hQDP);
		delete lpMPQDraftPlugin;
		Application->MessageBox("Could not get the MPQDraft plugin modules.", "Error: GetModules Failed", MB_ICONSTOP|MB_OK);
		return FALSE;
	}

	if(lpMPQDraftPlugin->dwPluginModules>0)
	{
		lpMPQDraftPlugin->lpPluginModules = new MPQDRAFTPLUGINMODULE[lpMPQDraftPlugin->dwPluginModules];
		if(!lpMPQDraftPlugin->lpIMPQDraftPlugin->GetModules(lpMPQDraftPlugin->lpPluginModules, &lpMPQDraftPlugin->dwPluginModules))
		{
			delete[] lpMPQDraftPlugin->lpPluginModules;
			FreeLibrary(lpMPQDraftPlugin->hQDP);
			delete lpMPQDraftPlugin;
			Application->MessageBox("Could not get the MPQDraft plugin modules.", "Error: GetModules Failed", MB_ICONSTOP|MB_OK);
			return FALSE;
		}
		lpMPQDraftPlugin->lpPluginModulesData = new MPQDRAFTPLUGINMODULED[lpMPQDraftPlugin->dwPluginModules];
		for(unsigned int i=0;i<lpMPQDraftPlugin->dwPluginModules;i++)
		{
        	        lpMPQDraftPlugin->lpPluginModulesData[i].dwModuleID = lpMPQDraftPlugin->lpPluginModules[i].dwModuleID;
        	        if (!ReadWholeFile(lpMPQDraftPlugin->lpPluginModules[i].szModuleFileName, &(void*)lpMPQDraftPlugin->lpPluginModulesData[i].lpData, &lpMPQDraftPlugin->lpPluginModulesData[i].dwDataSize))
                        {
				for(unsigned int j=0; j<i; j++)
                                {
					delete[] lpMPQDraftPlugin->lpPluginModulesData[j].lpData;
				}
				delete[] lpMPQDraftPlugin->lpPluginModulesData;
				delete[] lpMPQDraftPlugin->lpPluginModules;
				FreeLibrary(lpMPQDraftPlugin->hQDP);
				delete lpMPQDraftPlugin;
				Application->MessageBox("Could not load one of the MPQDraft plugin modules.", "Error: Unable to read file", MB_ICONSTOP|MB_OK);
				return FALSE;
			}
		}
		delete[] lpMPQDraftPlugin->lpPluginModules;
	}

        if (!ReadWholeFile(lpMPQDraftPlugin->szMPQDraftPlugin, &(void*)lpMPQDraftPlugin->lpData, &lpMPQDraftPlugin->dwSize))
        {
		for(unsigned int j=0; j<lpMPQDraftPlugin->dwPluginModules; j++)
		{
			delete[] lpMPQDraftPlugin->lpPluginModulesData[j].lpData;
		}
		delete[] lpMPQDraftPlugin->lpPluginModulesData;
		FreeLibrary(lpMPQDraftPlugin->hQDP);
		delete lpMPQDraftPlugin;
		Application->MessageBox("Could not load the MPQDraft plugin.", "Error: Unable to load file", MB_ICONSTOP|MB_OK);
		return FALSE;
	}
        FreeLibrary(lpMPQDraftPlugin->hQDP);

        QDPList->AddItem(lpMPQDraftPlugin->szMPQDraftPluginName, (TObject*)lpMPQDraftPlugin);
        return true;
};

bool TPatchSaveForm::QDPluginConfig()
{
        if (QDPList->Count == 0)
                return true;
        int i = QDPList->ItemIndex;
        MPQDRAFTPLUGIN * lpMPQDraftPlugin = (MPQDRAFTPLUGIN*)(QDPList->Items->Objects[i]);

        lpMPQDraftPlugin->hQDP = LoadLibrary(lpMPQDraftPlugin->szMPQDraftPlugin);
	if(!lpMPQDraftPlugin->hQDP)
	{
                QDPluginRemove();
		return FALSE;
	}
        //Get interface
        GetMPQDraftPlugin_ GetMPQDraftPlugin = (GetMPQDraftPlugin_)GetProcAddress(lpMPQDraftPlugin->hQDP, "GetMPQDraftPlugin");
	if(!GetMPQDraftPlugin)
	{
		FreeLibrary(lpMPQDraftPlugin->hQDP);
		QDPluginRemove();
		return FALSE;
	}

	// Get an instance of the plugin-interface
	if(!GetMPQDraftPlugin(&lpMPQDraftPlugin->lpIMPQDraftPlugin) || lpMPQDraftPlugin->lpIMPQDraftPlugin==0)
	{
		FreeLibrary(lpMPQDraftPlugin->hQDP);
		QDPluginRemove();
		return FALSE;
	}

        //Clear old data
        for(unsigned int j=0; j<lpMPQDraftPlugin->dwPluginModules; j++)
	{
		delete[] lpMPQDraftPlugin->lpPluginModulesData[j].lpData;
	}
        delete[] lpMPQDraftPlugin->lpPluginModulesData;

        lpMPQDraftPlugin->fIsConfigured = false;
        while(!lpMPQDraftPlugin->fIsConfigured)
	{
                if(!lpMPQDraftPlugin->lpIMPQDraftPlugin->Configure(Application->Handle))
                {
                        FreeLibrary(lpMPQDraftPlugin->hQDP);
                        QDPluginRemove();
                        return false;
                }
                lpMPQDraftPlugin->fIsConfigured = lpMPQDraftPlugin->lpIMPQDraftPlugin->ReadyForPatch();
                if(!lpMPQDraftPlugin->fIsConfigured)
		{
			if(Application->MessageBox("The plugin is still not configured correctly, do you want to try again?", "Error: Configuration Failed", MB_YESNO)==IDNO)
			{
                                FreeLibrary(lpMPQDraftPlugin->hQDP);
                                QDPluginRemove();
                                return false;
                        }
                }
        }

        if(!lpMPQDraftPlugin->lpIMPQDraftPlugin->GetModules(NULL, &lpMPQDraftPlugin->dwPluginModules))
	{
                FreeLibrary(lpMPQDraftPlugin->hQDP);
                QDPluginRemove();
		return FALSE;
	}

	if(lpMPQDraftPlugin->dwPluginModules>0)
	{
		lpMPQDraftPlugin->lpPluginModules = new MPQDRAFTPLUGINMODULE[lpMPQDraftPlugin->dwPluginModules];
		if(!lpMPQDraftPlugin->lpIMPQDraftPlugin->GetModules(lpMPQDraftPlugin->lpPluginModules, &lpMPQDraftPlugin->dwPluginModules))
		{
			delete[] lpMPQDraftPlugin->lpPluginModules;
			FreeLibrary(lpMPQDraftPlugin->hQDP);
			QDPluginRemove();
                        return FALSE;
		}
		lpMPQDraftPlugin->lpPluginModulesData = new MPQDRAFTPLUGINMODULED[lpMPQDraftPlugin->dwPluginModules];
		for(unsigned int i=0;i<lpMPQDraftPlugin->dwPluginModules;i++)
		{
        	        lpMPQDraftPlugin->lpPluginModulesData[i].dwModuleID = lpMPQDraftPlugin->lpPluginModules[i].dwModuleID;
        	        if (!ReadWholeFile(lpMPQDraftPlugin->lpPluginModules[i].szModuleFileName, &(void*)lpMPQDraftPlugin->lpPluginModulesData[i].lpData, &lpMPQDraftPlugin->lpPluginModulesData[i].dwDataSize))
                        {
				for(unsigned int j=0; j<i; j++)
                                {
					delete[] lpMPQDraftPlugin->lpPluginModulesData[j].lpData;
				}
				delete[] lpMPQDraftPlugin->lpPluginModulesData;
				delete[] lpMPQDraftPlugin->lpPluginModules;
				FreeLibrary(lpMPQDraftPlugin->hQDP);
                                QDPluginRemove();
                                return FALSE;
			}
		}
		delete[] lpMPQDraftPlugin->lpPluginModules;
	}
        FreeLibrary(lpMPQDraftPlugin->hQDP);
        return true;
};

void TPatchSaveForm::QDPluginRemove()
{
        if (QDPList->Count == 0)
                return;
        int i = QDPList->ItemIndex;
        MPQDRAFTPLUGIN * lpMPQDraftPlugin = (MPQDRAFTPLUGIN*)QDPList->Items->Objects[i];
        delete[] lpMPQDraftPlugin->lpPluginModules;
        for (unsigned int j = 0; j < lpMPQDraftPlugin->dwPluginModules; j++)
	        delete[] lpMPQDraftPlugin->lpPluginModulesData[j].lpData;
        delete[] lpMPQDraftPlugin->lpPluginModulesData;

        delete lpMPQDraftPlugin;

        QDPList->DeleteSelected();
};

bool ReadWholeFile(char * szFileName, LPVOID * lpData, DWORD * lpSize)
{
        int fd;

        fd = FileOpen(szFileName, fmOpenRead | fmShareDenyWrite);
        if (fd == -1)
                return false;
        *lpSize = FileSeek(fd, 0, 2);
        FileSeek(fd, 0, 0);

	*lpData = new char[*lpSize];
	FileRead(fd, *lpData, *lpSize);

        FileClose(fd);

        return true;
};

LPVOID LoadResource(LPCSTR szResName, LPCSTR szType, LPDWORD lpSize)
{
	HRSRC hResInfo;
	HGLOBAL hResData;

	hResInfo = ::FindResource(0, szResName, szType);
	hResData = ::LoadResource(0, hResInfo);
	*lpSize = ::SizeofResource(0, hResInfo);
	return ::LockResource(hResData);
};

#pragma nopackwarning 
