//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
//---------------------------------------------------------------------------
USEFORM("About.cpp", AboutBox);
USEFORM("Credits.cpp", CreditsBox);
USEFORM("DoodadInfo.cpp", DoodadInfoBox);
USEFORM("Options.cpp", OptionsBox);
USEFORM("Splash.cpp", SplashForm);
USEFORM("LoadDir.cpp", OpenDirBox);
USEFORM("Main.cpp", Form1);
USEFORM("ProgressForm.cpp", ProgForm);
USEFORM("FileCompare.cpp", CompareFiles);
USEFORM("ExportBox.cpp", ExportBox);
USEFORM("MergeSource.cpp", MergeDialog);
//---------------------------------------------------------------------------
USEFORM("SavePatch.cpp", PatchSaveForm)
//---------------------------------------------------------------------------
WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
        try
        {
                 Application->Initialize();
                 Application->Title = "DatEdit";
                 Application->CreateForm(__classid(TForm1), &Form1);
                 Application->CreateForm(__classid(TSplashForm), &SplashForm);
                 Application->CreateForm(__classid(TOptionsBox), &OptionsBox);
                 Application->CreateForm(__classid(TAboutBox), &AboutBox);
                 Application->CreateForm(__classid(TCreditsBox), &CreditsBox);
                 Application->CreateForm(__classid(TDoodadInfoBox), &DoodadInfoBox);
                 Application->CreateForm(__classid(TOpenDirBox), &OpenDirBox);
                 Application->CreateForm(__classid(TProgForm), &ProgForm);
                 Application->CreateForm(__classid(TCompareFiles), &CompareFiles);
                 Application->CreateForm(__classid(TExportBox), &ExportBox);
                 Application->CreateForm(__classid(TPatchSaveForm), &PatchSaveForm);
                 Application->CreateForm(__classid(TMergeDialog), &MergeDialog);
                 Application->ShowMainForm = false;
                 Application->Run();
        }
        catch (Exception &exception)
        {
                 Application->ShowException(&exception);
        }
        catch (...)
        {
                 try
                 {
                         throw Exception("");
                 }
                 catch (Exception &exception)
                 {
                         Application->ShowException(&exception);
                 }
        }
        return 0;
}
//---------------------------------------------------------------------------



