/*
############################################################################
   DATEDIT source code - A Logical Knot/Star Alliance release;
   Made by BroodKiller (Jacek Kominek) 2005-2007.
                                                   
   This is the complete C++ source code that makes up for
   DatEdit, application used to edit the *.DAT data files
   used in the Blizzard RTS game StarCraft. I didn't hide
   anything from you, this code will compile into the very
   same application that you can download from the web.

   Please, remember that all the comments that are put here
   have been made exclusively for this release. Normally
   I don't do anything like that but I tried to comment this
   code to the best of my abilities.
   Also, keep in mind that these comments are intended to help
   those of you with already some programming experience.
   DO NOT, and let me repeat this, DO NOT look into this code if
   you're just starting your adventure with C++ or Borland C++ Builder.
   You may learn some bad habits from it, and I don't want to
   be responsible for that.
   For more, while writing this code, I myself was still
   learning and discovering many things about C++/VCL
   programming. Thus, some problems may be solved one way
   in one part of the program, and in another way elsewhere.
   Don't blame me for it - rather try to learn on my mistakes :)

   Finally, I am aware that, as a whole, this code could be much better,
   but a fellow coder and a friend of mine told me this once:

   "First of all, get it to work - everything else is optional".

   And I agree with this. After all, my point was to give to the
   community a useful and working application, not a beautiful
   source code ;)

   If these lines of C++-code-wannabe will help or inspire you
   in any way - that's great. Personally, I don't require you
   to credit me for anything you do with what is included here,
   although it would be nice if you mention me somewhere around
   the Credits if you would directly copy some parts from
   DatEdit's code 8)

   And remeber: "Sharing is caring", so

      Open source all the way!

   -BroodKiller

############################################################################
*/
/*
############################################################################
   This program in its entirety is free software; you can redistribute it
   and/or modify it under the terms of the GNU General Public License as
   published by the Free Software Foundation; either version 2 of the
   License, or (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301 USA
############################################################################
*/

//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Main.h"
#include "About.h"
#include "LoadList.h"
#include "Data.h"
#include "TBLParser.h"
#include "Credits.h"
#include "LoadDir.h"
#include "ExportBox.h"
#include "DoodadInfo.h"
#include "EntryData.h"
#include "FileData.h"
#include "Options.h"
#include "TForm1.h"
#include "Splash.h"
#include "ProgressForm.h"
#include "FileCompare.h"
#include "SavePatch.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
#pragma warn -aus
TForm1 *Form1;
bool GoodEvent=false;
extern "C" bool SkipMultiDraw;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
/*
############################################################################
This is the main form's initial routine, it includes:
-call to initialize program's internal variables,
-reading the config INI data
-loading the external files with Hints, Origin sortdata, and FAQ Menu
-loading default DAT files.
-Loading bookmarks
Program will terminate if the "/Data" and "/default" directories
do not exist.
############################################################################
*/

void __fastcall TForm1::FormCreate(TObject *Sender)
{
InitializeValues();
if (DirectoryExists(GetProgPath()+"Default\\") && DirectoryExists(GetProgPath()+"Data\\")) {
   ReadConfig->Execute();
   ReadConfigOptions->Execute();

   Hints->LoadFromFile(GetProgPath()+"Data\\Hints.txt");
   Origins->LoadFromFile(GetProgPath()+"Data\\Origins.txt");
   FAQ->LoadFromFile(GetProgPath()="Data\\FAQ.txt");
   LoadFAQ->Execute();
   for (int i=0;i<=10;i++) {
       if (!FileExists(GetProgPath()+"Data\\"+GetDATType(i)+".txt")) {
          MessageDlg("Could not find a DAT entry list: "+GetProgPath()+"Data\\"+GetDATType(i)+".txt"+".\nDatEdit will terminate.", mtError, TMsgDlgButtons() << mbOK, 0);
          Application->Terminate();
       }
       else if (!FileExists(GetProgPath()+"Formats\\"+GetDATType(i)+".def")) {
          MessageDlg("Could not find a DAT format file: "+GetProgPath()+"Formats\\"+GetDATType(i)+".def"+".\nDatEdit will terminate.", mtError, TMsgDlgButtons() << mbOK, 0);
          Application->Terminate();
       }
       else if (FileExists(GetProgPath()+"Data\\"+GetDATType(i)+".txt") && FileExists(GetProgPath()+"Formats\\"+GetDATType(i)+".def")) {
          GetDATEntryNames(i)->LoadFromFile(GetProgPath()+"Data\\"+GetDATType(i)+".txt");
          GetDATFormat(i)->LoadFromFile(GetProgPath()+"Formats\\"+GetDATType(i)+".def");
          ReadLabels->Execute();
          GetDATFile(i)->SetDATTypeID(i);
          GetDATFile(i)->LoadFormat(GetDATFormat(i));
          CheckDATFile((GetProgPath())+"Default\\"+GetDATType(i)+".dat");
       }
   }
   ReadBookmarks->Execute();
}
else {
     if (!DirectoryExists(GetProgPath()+"Default\\")) {
        MessageDlg("The default DAT directory not found.\n       DatEdit will terminate.", mtError, TMsgDlgButtons() << mbOK, 0);
        Application->Terminate();
     }
     if (!DirectoryExists(GetProgPath()+"Data\\")) {
        MessageDlg("The program Data directory not found.\n       DatEdit will terminate.", mtError, TMsgDlgButtons() << mbOK, 0);
        Application->Terminate();
     }
}
};
//---------------------------------------------------------------------------
/*
############################################################################
This routine is activated when the main form is shown. Here takes place
handling of any files that are passed as a parameter at launch. It is
also here that the "Start Editor" is shown.
############################################################################
*/
void __fastcall TForm1::FormShow(TObject *Sender)
{
Editors->ActivePageIndex = Options.StartEditor;
ChangeTab->Execute();
if (ParamStr(1) != "") {
   if (FileExists(ParamStr(1)) == true) {
      String LoadFileName = ParamStr(1);
      void *MpqHandle;
      if (DirectoryExists(LoadFileName)) {
         LoadDATDir(LoadFileName);
      }
      if (SFileOpenArchive(LoadFileName.c_str(),0,0,&MpqHandle)) {
         AddHistoryItem(LoadFileName);
         SetLastFolder(ExtractFileDir(LoadFileName));
         CheckMPQFile(LoadFileName);
      }
      else if (ExtractFileExt(LoadFileName).LowerCase() == ".dat") {
         AddHistoryItem(LoadFileName);
         SetLastFolder(ExtractFileDir(LoadFileName));
         CheckDATFile(LoadFileName);
      }
      else {
         MessageDlg(String("\""+LoadFileName+"\" is not a file that DatEdit recognize."), mtError, TMsgDlgButtons() << mbOK, 0);
      }
      SFileCloseArchive(MpqHandle);
   }
   DragAcceptFiles(Handle, true);
   GetDATEntryList(GetPage())->SetFocus();
}
};
//---------------------------------------------------------------------------
/*
############################################################################
This is the program's pre-terminal routine. If the option is not disabled
it will display the "Are you sure?" dialog.
############################################################################
*/
void __fastcall TForm1::FormCloseQuery(TObject *Sender, bool &CanClose)
{
CanClose = true;
if (Options.ConfirmOnExit == true) {
     if (MessageDlg("Are you sure you want to exit DatEdit?", mtConfirmation, mbOKCancel, 0) == 1) {
        CanClose = true;
     }
     else
        CanClose = false;
}
};
//---------------------------------------------------------------------------
/*
############################################################################
This it the program's terminal routine. It writes to the config INI file,
and closes the opened SC archives, if previously found any.
############################################################################
*/
void __fastcall TForm1::FormClose(TObject *Sender, TCloseAction &Action)
{
SaveConfig->Execute();
SaveConfigOptions->Execute();  
if (GetIsSC() == true) {
   for (int i=0;i<3;i++) {
       SFileCloseArchive(GetSCMPQHandles(i));
   }
}
if (Form1->GetMPQHandle() != NULL) {
   SFileCloseArchive(Form1->GetMPQHandle());
}
if (Form1->GetGRPMPQHandle() != NULL) {
   SFileCloseArchive(Form1->GetGRPMPQHandle());
}                                
for (int i=0;i<11;i++) {
    delete GetDATFile(i);
//    GetDATFile(i)->~FileData();
}
delete Hints,Origins;
};
//---------------------------------------------------------------------------
/*
############################################################################
This and the the few following functions call a custom routine (LoadList
or LoadTBLList) that handles loading of the appropriate lists from the
text files (or a TBL) from the "Data/" dir to the correct dropdown boxes
in different editors (you can easily get which particular editor is in
question from a particular function's name).
############################################################################
*/
/*
############################################################################
UNITS EDITOR
############################################################################
*/

void __fastcall TForm1::UnitBasicShow(TObject *Sender)
{
if (UnitWeaponGroundList->Items->Count == 0) {
   LoadList(UnitWeaponGroundList,"Weapons",false);
}
if (UnitWeaponAirList->Items->Count == 0) {
   LoadList(UnitWeaponAirList,"Weapons",false);
}
if (UnitArmorUpgrade->Items->Count == 0) {
   LoadList(UnitArmorUpgrade,"Upgrades",false);
}
if (UnitSize->Items->Count == 0) {
   LoadList(UnitSize,"UnitSize",false);
}
};
//---------------------------------------------------------------------------

void __fastcall TForm1::UnitAdvShow(TObject *Sender)
{
if (UnitSub1->Items->Count == 0) {
   LoadList(UnitSub1,"Units",false);
}
if (UnitSub2->Items->Count == 0) {
   UnitSub2->Items = UnitSub1->Items;
}
if (UnitInfestationList->Items->Count == 0) {
   LoadList(UnitInfestationList,"Units",false);
}
};
//---------------------------------------------------------------------------
//SMALL LOADING TIME OPTIMIZATION HERE
void __fastcall TForm1::UnitSoundShow(TObject *Sender)
{
if (UnitSndReadyList->Items->Count == 0) {
   LoadList(UnitSndReadyList,"sfxdata",false);
}
if (UnitSndYesStartList->Items->Count == 0) {
   UnitSndYesStartList->Items = UnitSndReadyList->Items;
//   LoadList(UnitSndYesStartList,"sfxdata",false);
}
if (UnitSndYesEndList->Items->Count == 0) {
  UnitSndYesEndList->Items = UnitSndReadyList->Items;
//   LoadList(UnitSndYesEndList,"sfxdata",false);
}
if (UnitSndWhatStartList->Items->Count == 0) {
   UnitSndWhatStartList->Items = UnitSndReadyList->Items;
//   LoadList(UnitSndWhatStartList,"sfxdata",false);
}
if (UnitSndWhatEndList->Items->Count == 0) {
   UnitSndWhatEndList->Items = UnitSndReadyList->Items;
//   LoadList(UnitSndWhatEndList,"sfxdata",false);
}
if (UnitSndAnnStartList->Items->Count == 0) {
   UnitSndAnnStartList->Items = UnitSndReadyList->Items;
//   LoadList(UnitSndAnnStartList,"sfxdata",false);
}
if (UnitSndAnnEndList->Items->Count == 0) {
   UnitSndAnnEndList->Items = UnitSndReadyList->Items;
//   LoadList(UnitSndAnnEndList,"sfxdata",false);
}
};
//---------------------------------------------------------------------------

void __fastcall TForm1::UnitGraphicsShow(TObject *Sender)
{
if (UnitGfxList->Items->Count == 0) {
   LoadList(UnitGfxList,"Flingy",false);
}
if (UnitConstructionList->Items->Count == 0) {
   LoadList(UnitConstructionList,"Images",false);
}
if (UnitPortraitList->Items->Count == 0) {
   LoadList(UnitPortraitList,"Portdata",false);
}
if (UnitElevationLevelList->Items->Count == 0) {
   LoadList(UnitElevationLevelList,"ElevationLevels",false);
}           

SizeRect->Visible = false;
SizeRefPoint->Visible = false;
SizeGRPPrev->Visible = false;
if (Options.UnitSizePreviewType != 0) {
   SizeRect->Visible = true;
   SizeRefPoint->Visible = true;
   if (Options.UnitSizePreviewType == 2) {
      SizeGRPPrev->Visible = true;
   }
}
};
//---------------------------------------------------------------------------

void __fastcall TForm1::UnitSEShow(TObject *Sender)
{
if (GetEditorReload(0) == true) {

   //A DIRTY HACK TO INCLUDE ONLY THE RIGHT ENTRIES FOR THE
   //"RANK" PROPERTY, WHICH IS A 1301-BASED, 2-BYTE BIG
   //STAT_TXT.TBL POINTER.
   UnitRankList->Clear();
   LoadTBLList(UnitRankList,"stat_txt");
   for (int i=0,j=0;i<UnitRankList->Items->Count;i++) {
       if (j<1302 || j >= 1556) {
          UnitRankList->Items->Delete(i);
          i--;
          j++;
       }
   }
   UnitRankList->Items->Insert(0,"No sublabel");
   SetEditorReload(0,false);
}
};
//---------------------------------------------------------------------------

void __fastcall TForm1::UnitAIShow(TObject *Sender)
{
if (UnitAICompIdle->Items->Count == 0) {
   LoadList(UnitAICompIdle,"Orders",false);
}
if (UnitAIHumanIdle->Items->Count == 0) {
   UnitAIHumanIdle->Items = UnitAICompIdle->Items;
//   LoadList(UnitAIHumanIdle,"Orders",false);
}
if (UnitAIAttackUnit->Items->Count == 0) {
   UnitAIAttackUnit->Items = UnitAICompIdle->Items;
//   LoadList(UnitAIAttackUnit,"Orders",false);
}
if (UnitAIAttackMove->Items->Count == 0) {
   UnitAIAttackMove->Items = UnitAICompIdle->Items;
//   LoadList(UnitAIAttackMove,"Orders",false);
}
if (UnitAIReturn->Items->Count == 0) {
   UnitAIReturn->Items = UnitAICompIdle->Items;
//  LoadList(UnitAIReturn,"Orders",false);
}
if (UnitAIRightClick->Items->Count == 0) {
   LoadList(UnitAIRightClick,"RightClick",false);
}
};
//---------------------------------------------------------------------------
/*
############################################################################
WEAPONS EDITOR
############################################################################
*/

void __fastcall TForm1::WeapEditShow(TObject *Sender)
{
if (GetEditorReload(1) == true && GoodEvent == true) {
   LoadTBLList (WeapLabel,"stat_txt");
   WeapError->Items->Assign(WeapLabel->Items);
   SetEditorReload(1,false);
}
if (WeapGraphicsList->Items->Count ==0) {
   LoadList(WeapGraphicsList,"Flingy",false);
}
if (WeapIconList->Items->Count ==0) {
   LoadList(WeapIconList,"Icons",false);
}
if (WeapDamageUpgrade->Items->Count ==0) {
   LoadList(WeapDamageUpgrade,"Upgrades",false);
}
if (WeapBehaviour->Items->Count ==0) {
   LoadList(WeapBehaviour,"Behaviours",false);
}
if (WeapUnused->Items->Count ==0) {
   LoadList(WeapUnused,"Techdata",false);
}
if (WeapDamageType->Items->Count ==0) {
   LoadList(WeapDamageType,"DamTypes",false);
}
if (WeapDamageExplosion->Items->Count ==0) {
   LoadList(WeapDamageExplosion,"Explosions",false);
}
};
//---------------------------------------------------------------------------
/*
############################################################################
FLINGY EDITOR
############################################################################
*/

void __fastcall TForm1::FlingyEditShow(TObject *Sender)
{
if (FlingyMoveControl->Items->Count ==0) {
   LoadList(FlingyMoveControl,"FlingyControl",false);
}
if (FlingySpriteList->Items->Count ==0) {
   LoadList(FlingySpriteList,"Sprites",false);
}
};
//---------------------------------------------------------------------------
/*
############################################################################
SPRITES EDITOR
############################################################################
*/

void __fastcall TForm1::SpriteEditShow(TObject *Sender)
{
if (SpriteSelCircleList->Items->Count ==0) {
   LoadList(SpriteSelCircleList,"SelCircleSize",false);
}
if (SpriteImageList->Items->Count ==0) {
   LoadList(SpriteImageList,"Images",false);
}
CirclePrev->Visible = false;
CircleUnitPrev->Visible = false;
if (Options.ShowSelCirclePreview == true) {
   CirclePrev->Visible = true;
   CircleUnitPrev->Visible = true;
}
};
//---------------------------------------------------------------------------
/*
############################################################################
IMAGES EDITOR
############################################################################
*/

void __fastcall TForm1::ImageEditShow(TObject *Sender)
{
if (ImgDrawFunctionList->Items->Count == 0) {
   LoadList(ImgDrawFunctionList,"DrawList",false);
}
if (ImgRemapList->Items->Count == 0) {
   LoadList(ImgRemapList,"Remapping",false);
}
if (ImgShieldOL->Items->Count == 0) {
   LoadList(ImgShieldOL,"ShieldSize",false);
}
if (ImgIscriptIDList->Items->Count == 0) {
   LoadList(ImgIscriptIDList,"IscriptIDList",false);
}
if (GetEditorReload(4) == true && GoodEvent == true) {
   LoadTBLList(ImgGRPList,"images");
   ImgOL1List->Items = ImgGRPList->Items;
   ImgOL2List->Items = ImgGRPList->Items;
   ImgOL3List->Items = ImgGRPList->Items;
   ImgOL4List->Items = ImgGRPList->Items;
   ImgOL5List->Items = ImgGRPList->Items;
   ImgShieldList->Items = ImgGRPList->Items;
   SetEditorReload(4,false);
}
};
//---------------------------------------------------------------------------
/*
############################################################################
UPGRADE EDITOR
############################################################################
*/

void __fastcall TForm1::UpgradeEditShow(TObject *Sender)
{
if (UpgIconList->Items->Count == 0) {
   LoadList(UpgIconList,"Icons",false);
}
if (UpgRace->Items->Count == 0) {
   LoadList(UpgRace,"Races",false);
}
if (GetEditorReload(5) == true && GoodEvent == true) {
   LoadTBLList(UpgLabelList,"stat_txt");
   SetEditorReload(5,false);
}
};
//---------------------------------------------------------------------------
/*
############################################################################
TECHNOLOGY EDITOR
############################################################################
*/

void __fastcall TForm1::TechEditShow(TObject *Sender)
{
if (TechIconList->Items->Count == 0) {
   LoadList(TechIconList,"Icons",false);
}
if (TechRace->Items->Count == 0) {
   LoadList(TechRace,"Races",false);
}
if (GetEditorReload(6) == true && GoodEvent == true) {
   LoadTBLList(TechLabelList,"stat_txt");
   SetEditorReload(6,false);
}
};
//---------------------------------------------------------------------------
/*
############################################################################
SOUND EDITOR
############################################################################
*/

void __fastcall TForm1::SoundEditShow(TObject *Sender)
{
if (GetEditorReload(7) == true  && GoodEvent == true) {
   LoadTBLList(SoundFileList,"sfxdata");
   SetEditorReload(7,false);
}
};
//---------------------------------------------------------------------------
/*
############################################################################
PORTRAIT EDITOR
############################################################################
*/
void __fastcall TForm1::PortEditShow(TObject *Sender)
{
if (GetEditorReload(8) == true  && GoodEvent == true) {
   LoadTBLList(PortFileList,"portdata");
   SetEditorReload(8,false);
}
};
//---------------------------------------------------------------------------
/*
############################################################################
CAMPAIGN EDITOR
############################################################################
*/

void __fastcall TForm1::MapEditShow(TObject *Sender)
{
if (GetEditorReload(9) == true  && GoodEvent == true) {
   LoadTBLList(MapFileList,"mapdata");
   SetEditorReload(9,false);
}
};
//---------------------------------------------------------------------------
/*
############################################################################
ORDER EDITOR
############################################################################
*/

void __fastcall TForm1::OrderEditShow(TObject *Sender)
{
if (OrdTargeting->Items->Count == 0) {
   LoadList(OrdTargeting,"Weapons",false);
}
if (OrdEnergy->Items->Count == 0) {
   LoadList(OrdEnergy,"Techdata",false);
}
if (OrdObscured->Items->Count == 0) {
   LoadList(OrdObscured,"Orders",false);
}
if (OrdAnimation->Items->Count == 0) {
   LoadList(OrdAnimation,"Animations",false);
}
if (OrdHighlightList->Items->Count == 0) {
   LoadList(OrdHighlightList,"Icons",false);
}
if (GetEditorReload(10) == true && GoodEvent == true) {
   LoadTBLList(OrdLabel,"stat_txt");
   SetEditorReload(10,false);
}
};
//---------------------------------------------------------------------------
/*
############################################################################
This function displays the "About" box.
############################################################################
*/
void __fastcall TForm1::AboutClick(TObject *Sender)
{
AboutBox->ShowModal();
}
//---------------------------------------------------------------------------
/*
############################################################################
This function displays the "Credits" box.
############################################################################
*/
void __fastcall TForm1::CreditsClick(TObject *Sender)
{
CreditsBox->ShowModal();
};
//---------------------------------------------------------------------------
/*
############################################################################
This function displays the 'Doodads Information' box.
############################################################################
*/

void __fastcall TForm1::DoodadsInfo1Click(TObject *Sender)
{
DoodadInfoBox->ShowModal();
};
//---------------------------------------------------------------------------
/*
############################################################################
This function opens the "Select Directory" dialog: either the custom
one or the one used by the system.
############################################################################
*/

void __fastcall TForm1::OpenDirExecute(TObject *Sender)
{
if (Options.UseOldOpenDirectory == true) {
   OpenDirBox->ShowModal();
}
else {
     String Dir;
     SelectDirectory("Select a directory with DAT files to load from:","",Dir);
     if (Dir != "") {
        LoadDATDir(Dir);
     }
}
};
//---------------------------------------------------------------------------
/*
############################################################################
This function displays the "Open File" box.
############################################################################
*/

void __fastcall TForm1::OpenExecute(TObject *Sender)
{
if (GetLastFolder() != "") {
   OpenDialog->InitialDir = GetLastFolder();
}
OpenDialog->Execute();
};
//---------------------------------------------------------------------------
/*
############################################################################
This function is activated after a user selects a file for opening using
the "Load File" dialog box. It checks for the correct file extension and
acts appropriately: if it is a DAT, it passes the file over to the
DAT-parsing routine, if it is an MPQ- to the MPQ importing routine,
and if it is something different - it displays an error message.
############################################################################
*/

void __fastcall TForm1::OpenDialogCanClose(TObject *Sender,
      bool &CanClose)
{
String LoadExt,LoadFileName;
LoadFileName = OpenDialog->FileName;
LoadExt = ExtractFileExt(LoadFileName).LowerCase();
void *MpqHandle;

if (SFileOpenArchive(LoadFileName.c_str(),0,0,&MpqHandle)) {
   SFileCloseArchive(MpqHandle);
   AddHistoryItem(LoadFileName);
   SetLastFolder(ExtractFileDir(LoadFileName));
   CheckMPQFile(LoadFileName);
}
else if (LoadExt == ".dat") {
    if (FileExists(LoadFileName)) {
       TFileStream* LoadFile = new TFileStream (LoadFileName,fmOpenRead | fmShareDenyNone);
       if (LoadFile != NULL) {
          if (LoadExt == ".dat") {
             for (int i=0;i<11;i++) {
                 if (LoadFile->Size == GetDATFile(i)->GetFilesize()) {
                    AddHistoryItem(LoadFileName);
                    SetLastFolder(ExtractFileDir(LoadFileName));
                    CheckDATFile(LoadFileName);
                    break;
                 }
                 else if (i==10){
                    MessageDlg(String("\""+LoadFileName+"\" is not a valid DAT file that DatEdit can recognize."), mtError, TMsgDlgButtons() << mbOK, 0);
                 }
             }
          }
       }
       else {
           MessageDlg(String("\""+LoadFileName+"\" cannot be opened."), mtError, TMsgDlgButtons() << mbOK, 0);
       }
       delete LoadFile;
    }
    else {
       MessageDlg("Target file does not exist!", mtError, TMsgDlgButtons() << mbOK, 0);
    }
}
else {
    MessageDlg("Unsupported file type. Please choose a DAT or an MPQ file.", mtError, TMsgDlgButtons() << mbOK, 0);
}

};
//---------------------------------------------------------------------------
/*
############################################################################
This routine displays various warnings related to file saving and runs
the very file output routine for a currently used DAT file.
############################################################################
*/
void __fastcall TForm1::SaveExecute(TObject *Sender)
{
if (GetDATFile(GetPage())->GetLoadState() == true) {
   if (GetDATFile(GetPage())->GetDefaultState() == true) {
      String DatType = GetDATType(GetPage());

      int DefaultOverwriteMode = int (MessageDlg(("Are you sure that you want to overwrite the default \""+DatType+".dat\" file?").c_str(), mtConfirmation, mbYesNoCancel, 0));

      if (DefaultOverwriteMode == 6) {
         GetDATFile(GetPage())->SaveData(GetDATFile(GetPage())->GetDatName());
         MessageDlg("File saved succesfully.", mtInformation, TMsgDlgButtons() << mbOK, 0);
      }
      else if (DefaultOverwriteMode == 7) {
         Form1->SaveAs->Execute();
      }
   }
   else {
      GetDATFile(GetPage())->SaveData(GetDATFile(GetPage())->GetDatName());
      MessageDlg("File saved succesfully.", mtInformation, TMsgDlgButtons() << mbOK, 0);
   }
}
else if (GetDATFile(GetPage())->GetLoadState() == false) {
     MessageDlg("No DAT File of the current type was loaded. Load a DAT file first.", mtError, TMsgDlgButtons() << mbOK, 0);
}
};
//---------------------------------------------------------------------------
/*
############################################################################
This function opens up the "Save As" box.
############################################################################
*/
void __fastcall TForm1::SaveAsExecute(TObject *Sender)
{
if (GetDATFile(GetPage())->GetLoadState() == true) {
    FileSaveDialog->FileName=(GetDATType(GetPage())+".dat");
    FileSaveDialog->Execute();
}
};
//---------------------------------------------------------------------------
/*
############################################################################
This function carries out the "Saving As" process, after the user selects
a file (or inputs a filename) to save to.
############################################################################
*/
void __fastcall TForm1::FileSaveDialogCanClose(TObject *Sender, bool &CanClose)
{
String SaveExt,SaveFileName,DATExt;
SaveFileName = FileSaveDialog->FileName;
SaveExt = ExtractFileExt(SaveFileName);
int DATExist=0;

if (SaveExt != ".dat" && SaveExt != "") {
    MessageDlg("Unsupported file type. Please choose a DAT or an MPQ file.", mtError, TMsgDlgButtons() << mbOK, 0);
    }
else {
    if (SaveExt == "") {
       DATExt = ".dat";
    }
    else if (SaveExt == ".dat") {
       DATExt = "";
    }
    if (FileExists(SaveFileName+DATExt)) {
        if (MessageDlg("Are you sure you want to replace this DAT file?", mtConfirmation, TMsgDlgButtons() << mbYes << mbNo, 0) == mrYes) {
             DATExist = 1;
        }
    }
    else if (!FileExists(SaveFileName+DATExt)) {
        DATExist = 2;
    }
if (DATExist != 0) {
    GetDATFile(GetPage())->SaveData(SaveFileName+DATExt);
    MessageDlg("File saved succesfully.", mtInformation, TMsgDlgButtons() << mbOK, 0);
    CheckDATFile(SaveFileName+DATExt);
}
}
};
//---------------------------------------------------------------------------
/*
############################################################################
This function shows the file exporting dialog and if it returns a valid
 result, activates exporting (also to SEMPQ archives).
############################################################################
*/

void __fastcall TForm1::FileExportExecute(TObject *Sender)
{
ExportBox->ShowModal();
if (ExportBox->ModalResult != mrCancel && Form1->ExportSaveDialog->Tag != 0) {
   if (GetSEExport() == true) {
      ExportSaveDialog->FilterIndex = 2;
   }
   else {
      ExportSaveDialog->FilterIndex = 1;
   }
   ExportSaveDialog->Execute();

   if (GetSEExport() == true && ExportSaveDialog->FileName != "") {
      if (FileExists(ChangeFileExt(ExportSaveDialog->FileName,".tempmpq"))) {
         PatchSaveForm->SetPaths(ChangeFileExt(ExportSaveDialog->FileName,".exe"),ChangeFileExt(ExportSaveDialog->FileName,".tempmpq"));
         if (PatchSaveForm->CanSave()) {
            PatchSaveForm->ShowModal();
         }
         if (FileExists(ChangeFileExt(ExportSaveDialog->FileName,".tempmpq"))) {
            DeleteFile(ChangeFileExt(ExportSaveDialog->FileName,".tempmpq"));
         }
         MessageDlg("Succesful export to file: "+ChangeFileExt(ExportSaveDialog->FileName,".exe"), mtInformation, TMsgDlgButtons() <<mbOK, 0);
      }
   }
}
};
//---------------------------------------------------------------------------
/*
############################################################################
This is the file exporting routine. It also controls the
exporting progress bar.
############################################################################
*/
void __fastcall TForm1::ExportSaveDialogCanClose(TObject *Sender, bool &CanClose)
{
String ExportFileName = ExportSaveDialog->FileName;
int ExportFileExist=0;
void *FileHandle=NULL;

const char *TempMpqName;
TempMpqName = new const char[1000];
if (GetMPQHandle() != NULL) {
   SFileGetFileName(GetMPQHandle(),TempMpqName,1000);
}
if (ExportFileName == TempMpqName) {
   SFileCloseArchive(GetMPQHandle());
}

if (FileExists(ExportFileName) && !SFileOpenArchive(ExportFileName.c_str(),0,0,&FileHandle)) {
    SFileCloseArchive(FileHandle);
    ExportFileExist = -1;
    int Handle = FileOpen(ExportFileName,0);
    if (FileSeek(Handle,0,2) == 0) {
       ExportFileExist=2;
    }
    else {
       MessageDlg("Unsupported file type. Please choose an MPQ file.", mtError, TMsgDlgButtons() << mbOK, 0);
    }
    FileClose(Handle);
}
SFileCloseArchive(FileHandle);

if (FileExists(ExportFileName) && ExportFileExist == 0) {
   if (MessageDlg("Are you sure you want to export the selected files into this archive?", mtConfirmation, TMsgDlgButtons() << mbYes << mbNo, 0) == mrYes) {
      ExportFileExist = 1;
   }
}
else if (!FileExists(ExportFileName)) {
   if (ExtractFileExt(ExportFileName) != ".mpq" && GetSEExport() == false) {
      ExportFileName = ChangeFileExt(ExportFileName,".mpq");
   }
   if (GetSEExport() == true) {
      ExportFileName = ChangeFileExt(ExportFileName,".tempmpq");
   }
   ExportFileExist = 1;
}
if (ExportFileExist > 0) {
   ProgForm->Caption = "Exporting Progress...";
   ProgForm->Show();

   int ExportCount=ExportSaveDialog->Tag;
   if (GetIconExport() == true) {
      if (GetIconIsMPQImport() == false) {
         ExportToMpq(ExportFileName, Icons.FileName,0,0);
      }
      else {
         ExportToMpq(ExportFileName,"cmdicons.grp",MpqIcons.Data,MpqIcons.Size);
      }
      ProgForm->ProgressBar->StepBy(50/ExportCount);
   }
   for (int i=0;i<5;i++) {
       if (GetTBLExport(i) == true) {
          if (GetTBLIsMPQImport(i) == false) {
             ExportToMpq(ExportFileName, TBLs[i].FileName,0,0);
          }
          else {
             ExportToMpq(ExportFileName, String(GetTBLType(i)+".tbl"),MpqTBLs[i].Data,MpqTBLs[i].Size);
          }
          ProgForm->ProgressBar->StepBy(50/ExportCount);
       }
   }
   for (int i=0;i<11;i++) {
       if (GetDatExport(i) == true) {
          ExportToMpq(ExportFileName, GetDATType(i)+".dat",GetDATFile(i)->PrepareData(),GetDATFile(i)->GetFilesize());
          ProgForm->ProgressBar->StepBy(50/ExportCount);
       }
   }
   ProgForm->Hide();
   if (GetSEExport() == false) {
      MessageDlg("Succesful export to file: "+ExportFileName, mtInformation, TMsgDlgButtons() <<mbOK, 0);
      CanClose = true;
   }
   if (ExportFileName == TempMpqName) {
      SFileOpenArchive(ExportFileName.c_str(),1000,0,&FileHandle);
      Form1->SetMPQHandle(FileHandle);
   }
}
};
//---------------------------------------------------------------------------
/*
############################################################################
This is a general purpose routine that performs jumps from an entry in
one Editor to a linked entry in another editor.
############################################################################
*/

void __fastcall TForm1::JumpToDATExecute(TObject *Sender)
{
if (GetDATEntryList(GetPage())->Selected != NULL) {
   int Value=-1,Var=0;
   int TargetPage=0;
   int Tag = ((TComponent*)(Sender))->Tag;
   String Name = ((TComponent*)(Sender))->Name;

   TargetPage = Tag;
   if (abs(Tag) > 999) {
      Var = Tag/1000;
      TargetPage = abs(Tag-((Tag/1000)*1000));
   }
   if (String(Form1->FindComponent(Name.SubString(1,Name.Length()-4))->ClassName()) == "TEdit") {
      Value = ((TEdit*)(Form1->FindComponent(Name.SubString(0,Name.Length()-4))))->Text.ToInt()+Var;
   }
   else if (String(Form1->FindComponent(Name.SubString(1,Name.Length()-4))->ClassName()) == "TComboBox") {
      Value = ((TComboBox*)(Form1->FindComponent(Name.SubString(0,Name.Length()-4))))->ItemIndex+Var;
   }
   if (TargetPage != -1 && Value != -1 && Value < GetDATFile(TargetPage)->GetOutputEntrycount()) {
      Editors->ActivePageIndex = TargetPage;
      ChangeTab->Execute();
      if (GetSortingStyle(TargetPage) == 2) {
         GetDATEntryList(TargetPage)->Selected = GetDATEntryList(TargetPage)->Items->Item[Value];
      }
      else if (GetSortingStyle(TargetPage) != 2) {
         GetDATEntryList(TargetPage)->Selected = GetDATEntryList(TargetPage)->Items->Item[LookEntry(Value,TargetPage)];
      }
   }
}
};
//---------------------------------------------------------------------------
/*
############################################################################
This is a versatile function that performs a jump to a particular entry ID
in the currently displayed entry listing. The target ID is read from the
JumpToId text box.
############################################################################
*/

void __fastcall TForm1::JumpToIDKeyDown(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
if (Key == VK_RETURN) {
   if (JumpToID->Text.ToInt() < GetDATEntryList(GetPage())->Items->Count && (JumpToID->Text.IsEmpty() == false) && (GetDATEntryList(GetPage())->Items->Count != 0) && ElGrandoListos->Enabled == true && JumpToID->Text.ToInt() >= 0) {
      JumpToID->Color = clBlack;
      if (GetSortingStyle(GetPage()) == 2) {
         GetDATEntryList(GetPage())->Selected = GetDATEntryList(GetPage())->Items->Item[JumpToID->Text.ToInt()];
      }
      else if (GetSortingStyle(GetPage()) != 2) {
         GetDATEntryList(GetPage())->Selected = GetDATEntryList(GetPage())->Items->Item[LookEntry(JumpToID->Text.ToInt(),GetPage())];
      }
      ChangeTab->Execute();
   }
   else {
     JumpToID->Color = clRed;
   }
}
};
//---------------------------------------------------------------------------
/*
############################################################################
This function puts 0 to a textbox control that the user left without any
value. A security countermeasure, if you want to think of it like that.

It is used by all textboxes in DatEdit.
############################################################################
*/
void __fastcall TForm1::ExitEditExecute(TObject *Sender)
{
if (((TEdit*) Sender)->Text.IsEmpty() == true) {
   ((TEdit*) Sender)->Text = 0;
}
};
//---------------------------------------------------------------------------
/*
############################################################################
This function is activated when the content of an interface component has
been changed by the user. It passes the changes over to the function
that applies these changes to the data stored in the memory, and rewrites
the value back in the control (via the ListChange routine) to prevent input
higher than a particular property can store. Compatible with the case of many
entries selected at once.

NOTE:The method of data collection is component-dependent,hence
the 3 if's.
NOTE2:The 'ValidValue" and 'EmptyValue' bool variables are used to determine
if a textbox content is valid (proper value or lack of any value) or
invalid (StrToIntDef fails and returns -1) so that appropriate rewriting
takes (or doesn't take) place.
NOTE3:If a textbox is left empty, it's property value is zeroed.
############################################################################
*/

void __fastcall TForm1::ChangeDataBoxExecute(TObject *Sender)
{
if (GetDATEntryList(GetPage())->Selected != NULL) {
   unsigned int value=0;
   bool Proceed=false,ValidValue=false,EmptyValue=false;

   if (String(Sender->ClassName()) == "TEdit") {
      if (((TEdit*)(Sender))->Text.IsEmpty() == false) {
         value = StrToIntDef (((TEdit*) Sender)->Text,-1) ;
         if (value != -1) {
            Proceed = true;
            ValidValue = true;
         }
         else {
            Proceed = false;
            ValidValue = false;
         }
      }
      else {
         value = 0;
         Proceed = true;
         ValidValue = true;
         EmptyValue = true;
      }
   }
   else if (String(Sender->ClassName()) == "TComboBox") {
      value = (unsigned int) ((TComboBox*) Sender)->ItemIndex;
      Proceed = true;
   }
   else if (String(Sender->ClassName()) == "TCheckBox") {
      value = (unsigned int) (((TCheckBox*) Sender)->Checked);
      Proceed = true;
   }
   if (Proceed == true && SkipMultiDraw == false) {
      for (unsigned int i=0;i<GetDATEntryList(GetPage())->SelectionCount;i++) {
          int NodeID = GetDATEntryList(GetPage())->Selections[i]->StateIndex;
          if (NodeID != -1) {
             ChangeEntryData(NodeID,GetPage(),value,Sender);
          }
      }
   }
   if ((SkipMultiDraw == false && Proceed == true && EmptyValue == false) || ValidValue == false) {
      DisplayEntryData(GetDATEntryList(GetPage())->Selected->StateIndex,Editors->ActivePageIndex);
   }
}
};
//---------------------------------------------------------------------------
/*
############################################################################
This function activates the routine responsible for the 'Copy Entry' action.
############################################################################
*/

void __fastcall TForm1::CopyExecute(TObject *Sender)
{
if (GetDATEntryList(GetPage())->Selected != NULL) {
   GetDATFile(GetPage())->CopyTempEntry(GetDATEntryList(GetPage())->Selected->StateIndex);
}
};
//---------------------------------------------------------------------------
/*
############################################################################
This function activates the routine responsible for the 'Paste Entry' action.
############################################################################
*/

void __fastcall TForm1::PasteExecute(TObject *Sender)
{
if (GetDATEntryList(GetPage())->Selected != NULL) {
   GetDATFile(GetPage())->PasteTempEntry(GetDATEntryList(GetPage())->Selected->StateIndex);
   ChangeTab->Execute();
}
};
//---------------------------------------------------------------------------
/*
############################################################################
This function activates the routine responsible for the 'Copy Tab' action.
############################################################################
*/

void __fastcall TForm1::CopyTabExecute(TObject *Sender)
{
if (GetDATEntryList(GetPage())->Selected != NULL) {
   GetDATFile(GetPage())->CopyTab(GetDATEntryList(GetPage())->Selected->StateIndex,GetSubPage());
}
};
//---------------------------------------------------------------------------
/*
############################################################################
This function activates the routine responsible for the 'Paste Tab' action.
############################################################################
*/

void __fastcall TForm1::PasteTabExecute(TObject *Sender)
{
if (GetDATEntryList(GetPage())->Selected != NULL) {
   GetDATFile(GetPage())->PasteTab(GetDATEntryList(GetPage())->Selected->StateIndex,GetSubPage());
   ChangeTab->Execute();
}
};
//---------------------------------------------------------------------------
/*
############################################################################
This function activates the routine responsible for the 'Paste Mixed' action.
############################################################################
*/

void __fastcall TForm1::PasteMixedExecute(TObject *Sender)
{
if (GetDATEntryList(GetPage())->Selected != NULL) {
   GetDATFile(GetPage())->PasteMix(GetDATEntryList(GetPage())->Selected->StateIndex);
   ChangeTab->Execute();
}
};
//---------------------------------------------------------------------------
/*
############################################################################
This handler is activated by a change in selection in the entry listing.
It controls the display of the appropriate data for the selected entry,
as well as runs the Backward-Reporting routine.

The "StateIndex" property, set at the moment of creation of a TTreeNode
object, is used as entry index.
############################################################################
*/

void __fastcall TForm1::ListChange(TObject *Sender, TTreeNode *Node)
{
if (GetDATEntryList(GetPage())->Selected != NULL) {
   TTreeNode *Node = GetDATEntryList(GetPage())->Selected;
   Node->Selected = true;
   if (Node->StateIndex != -1) {
      DisplayEntryData(Node->StateIndex,Editors->ActivePageIndex);
      if (Options.UseBackwardReporting == true && ((GetPage()>=1 && GetPage()<=8) || GetPage()==10)) {
         LoadUsedList(GetPage(),Node->StateIndex);
      }
      if (Options.UseBackwardReporting == false) {
         UsedList->Clear();
      }
   }
}
};
//---------------------------------------------------------------------------
/*
############################################################################
This routine controls what happens when one editor changes to another:
1-If not DAT file has been allocated for the new editor,loads the
default DAT file
2-Controls the ability for multiselection,depending on the sorting style
3-If the entry list for this editor is not yet loaded or is marked as
"to be reloaded", loads it
4-Shows/Hides the "Used By" area,depending on the editor
5-Displays the origin of the current DAT file in the status bar
6-Displays the data for the entry selected in the new editor
7-Brings to front the entry listing for the new editor
############################################################################
*/

void __fastcall TForm1::ChangeTabExecute(TObject *Sender)
{
SetPage(Editors->ActivePage->PageIndex);
if (GetPage() != 0) {
   SetSubPage(-1);
}
else {
   SetSubPage(UnitTabs->ActivePageIndex);
}  

if (GetDATFile(GetPage())->GetLoadState() == false) {
   CheckDATFile((GetProgPath())+"Default\\"+GetDATType(GetPage())+".dat");
}

if (GetSortingStyle(GetPage()) != 2) {
   GetDATEntryList(GetPage())->MultiSelect = false;
}
else if (GetSortingStyle(GetPage()) == 2) {
   GetDATEntryList(GetPage())->MultiSelect = true;
}
   
if (GetListReload(GetPage()) == true || GetDATEntryList(GetPage())->Items->Count == 0) {
   LoadEntryList(GetDATEntryList(GetPage()),GetPage());
   SetListReload(GetPage(),false);
}

if ((GetPage()>=1 && GetPage()<= 8) || GetPage() == 10) {
    LabelUsed->Visible = true;
    UsedList->Visible = true;
}
else {
    LabelUsed->Visible = false;
    UsedList->Visible = false;
}

if (GetPage() == 0) {
   UnitTabs->OnChange(UnitTabs);
}

StatusBar->Panels->Items[0]->Text = GetDATFile(GetPage())->GetDatName();
StatusBar->Update();

if (Form1->Visible == true) {
   GoodEvent = true;
   if (GetPage() != 0) {
      Editors->Pages[GetPage()]->OnShow(Editors->Pages[GetPage()]);
   }
   else {
      UnitTabs->Pages[GetSubPage()]->OnShow(UnitTabs->Pages[GetSubPage()]);
   }
   GoodEvent = false;
   for (int i=0;i<11;i++) {
       if (i != GetPage()) {
          GetDATEntryList(i)->Hide();
       }
       else if (i == GetPage()) {
          GetDATEntryList(i)->Show();
          GetDATEntryList(i)->BringToFront();
          GetDATEntryList(i)->SetFocus();
       }
   }
}

if (GetDATEntryList(GetPage())->Selected != NULL) {
   ListChange(GetDATEntryList(GetPage()),GetDATEntryList(GetPage())->Selected);
}
else {
   UsedList->Items->Clear();
}
};
//--------------------------------------------------------------------------
/*
############################################################################
This function updates the displayed data within the Units Editor subtabs
only.
############################################################################
*/
void __fastcall TForm1::UnitTabsChange(TObject *Sender)
{
SetSubPage(UnitTabs->ActivePageIndex);
if (GetDATEntryList(0)->Selected != NULL) {
   Form1->ListChange(GetDATEntryList(0),GetDATEntryList(0)->Selected);
}
};
//---------------------------------------------------------------------------
/*
############################################################################
Activated by a double-click on an element of the "Used by" list,
this routine is responsible for jumping to the target entry
in the target Editor.The target entry's ID is read from its caption.
############################################################################
*/

void __fastcall TForm1::UsedListDblClick(TObject *Sender)
{
   String SelectedItem = UsedList->Items->Strings[UsedList->ItemIndex];
   int Start = SelectedItem.Pos("[");
   int End = SelectedItem.Pos("]");
   char Type = SelectedItem[Start+1];
   String Value = SelectedItem.SubString(Start+2,End-Start-2);

   int TargetPageID;
   switch (Type) {
        case 'U':
        	TargetPageID = 0;
                break;
        case 'W':
        	TargetPageID = 1;
                break;
   	case 'F':
        	TargetPageID = 2;
                break;
        case 'S':
        	TargetPageID = 3;
                break;
        case 'I':
                TargetPageID = 4;
                break;
        case 'O':
        	TargetPageID = 10;
                break;
   }

   if (Editors->Pages[TargetPageID]->Enabled == true && (GetDATEntryList(TargetPageID))->Enabled == true) {
      if (GetSortingStyle(TargetPageID) == 2) {
         GetDATEntryList(TargetPageID)->Selected = GetDATEntryList(TargetPageID)->Items->Item[Value.ToInt()];
      }
      else if (GetSortingStyle(TargetPageID) != 2) {
         GetDATEntryList(TargetPageID)->Selected = GetDATEntryList(TargetPageID)->Items->Item[LookEntry(Value.ToInt(),TargetPageID)];
      }
      Editors->ActivePageIndex = TargetPageID;
      if (TargetPageID == 0) {
         if (GetPage() == 1 || GetPage() == 5) {
            UnitTabs->ActivePageIndex = 0;
         }
         else if (GetPage() == 7) {
            UnitTabs->ActivePageIndex = 2;
         }
         else if (GetPage() == 2 || GetPage() == 8) {
            UnitTabs->ActivePageIndex = 3;
         }
         else if (GetPage() == 10) {
            UnitTabs->ActivePageIndex = 5;
         }
         UnitTabs->OnChange(UnitTabs);
      }
      ChangeTab->Execute();
   }
   else {
    	MessageDlg("Jump to the target editor is impossible.", mtError, TMsgDlgButtons() << mbOK, 0);
   }
};
//---------------------------------------------------------------------------
/*
############################################################################
This routine controls which items from the 'Edit' menu are available.
It detects which editor is currently loaded, and whether an entry (or a tab)
has been previously Copied (clearly, activating the 'Paste' options)
############################################################################
*/

void __fastcall TForm1::EditMenuClick(TObject *Sender)
{
if (GetDATEntryList(GetPage())->SelectionCount == 1) {
Copy1->Enabled = true;
Paste1->Enabled = true;
CopyTab1->Enabled = true;
PasteTab1->Enabled = true;
PasteMixed1->Enabled = true;

if (GetPage() != 0) {
   CopyTab1->Enabled = false;
   PasteTab1->Enabled = false;
   PasteMixed1->Enabled = false;
}
if (GetDATEntryList(GetPage())->Selected == NULL) {
   Copy1->Enabled = false;
   Paste1->Enabled = false;
   CopyTab1->Enabled = false;
   PasteTab1->Enabled = false;
   PasteMixed1->Enabled = false;
}
if (GetTempDats(GetPage()) == false) {
   Paste1->Enabled = false;
   if (GetPage() == 0) {
      PasteMixed1->Enabled = false;
   }
}
if (GetTempTabs(GetSubPage()) == false) {
   PasteTab1->Enabled = false;
}

ClipCopy->Enabled = true;
ClipPaste->Enabled = false;
if (OpenClipboard(Application->Handle)) {
   void* ClipFileHandle = GlobalAlloc(NULL, sizeof(ClipDAT));
   ClipFileHandle = GetClipboardData(this->ClipFormat);
   if (ClipFileHandle != NULL && ((ClipDAT*)(ClipFileHandle))->DATType == GetPage()) {
      ClipPaste->Enabled = true;
   }
   CloseClipboard();
}
}
else {
   Copy1->Enabled = false;
   Paste1->Enabled = false;
   CopyTab1->Enabled = false;
   PasteTab1->Enabled = false;
   PasteMixed1->Enabled = false;
   ClipCopy->Enabled = false;
   ClipPaste->Enabled = false;
}
};
//---------------------------------------------------------------------------
/*
############################################################################
This routine detects if there are any items in the File History, and if so
displays a nice information about this fact =).
############################################################################
*/

void __fastcall TForm1::FileMenuClick(TObject *Sender)
{
if (MRUD->Count == 0) {
   TMenuItem *Dummy = new TMenuItem(Form1);
   Dummy->Caption = "No files in History";
   Dummy->Enabled = false;
   MRUD->Add(Dummy);
}
};
//---------------------------------------------------------------------------
/*
############################################################################
This function loads an appropriate elemenent from the File History list
after it has been clicked.
############################################################################
*/

void __fastcall TForm1::LoadHistoryItemExecute(TObject *Sender)
{
String FileName = ((TMenuItem*)(Sender))->Caption;
String FileExt = ExtractFileExt(FileName).LowerCase();

if (FileExt == "") {
   LoadDATDir(FileName);
}
else if (FileExists(FileName)) {
   if (FileExt == ".dat") {
      CheckDATFile(FileName);
   }
   else {
      void *MpqHandle;
      if (SFileOpenArchive(FileName.c_str(),0,0,&MpqHandle)) {
         CheckMPQFile(FileName);
      }
      SFileCloseArchive(MpqHandle);
   }
}
else {
   MessageDlg("Target file does not exist!", mtError, TMsgDlgButtons() << mbOK, 0);
   ((TMenuItem*)(Sender))->Parent->Delete(((TMenuItem*)(Sender))->MenuIndex);
}
};
//---------------------------------------------------------------------------
/*
############################################################################
This handler opens up the Options box.
############################################################################
*/
void __fastcall TForm1::OptionsMenuClick(TObject *Sender)
{
OptionsBox->ShowModal();
};
//---------------------------------------------------------------------------
/*
############################################################################
This handler opens up the "Compare DAT Files" box.
############################################################################
*/
void __fastcall TForm1::FileCompareMergeClick(TObject *Sender)
{
CompareFiles->ShowModal();
}
//---------------------------------------------------------------------------
/*
############################################################################
This handler clears the File History.
############################################################################
*/
void __fastcall TForm1::ClearHistoryExecute(TObject *Sender)
{
MRUD->Clear();
};
//---------------------------------------------------------------------------
/*
############################################################################
This function reads the core properties from the config file (DatEdit.ini):
History List, application window size, custom files paths,window state,
sorting styles and bookmarks.
############################################################################
*/

void __fastcall TForm1::ReadConfigExecute(TObject *Sender)
{
if (FileExists(GetProgPath()+"DatEdit.ini")) {
   TIniFile *ConfigIni = new TIniFile(GetProgPath()+"DatEdit.ini");

   if (ConfigIni->ReadInteger("Recently Used","History Items",0) == 0) {
      TMenuItem *Dummy = new TMenuItem(Form1);
      Dummy->Caption = "No files in History";
      Dummy->Enabled = false;
      MRUD->Add(Dummy);
   }
   else {
      for (int i=ConfigIni->ReadInteger("Recently Used","History Items",0);i>=1;i--) {
          TMenuItem *NewHistoryItem = new TMenuItem(Form1);
          NewHistoryItem->Caption = ConfigIni->ReadString("Recently Used","File"+String(i),"");
          NewHistoryItem->OnClick = LoadHistoryItemExecute;
          MRUD->Insert(0,NewHistoryItem);
      }
   }
   Form1->Width = ConfigIni->ReadInteger("UserSize","UserWidth",Form1->Width);
   Form1->Height = ConfigIni->ReadInteger("UserSize","UserHeight",Form1->Height);
   SetLastFolder(ConfigIni->ReadString("Last Opened","Folder",""));
/*
   TBLs[0].Load(ConfigIni->ReadString("Files","Stat_txt",GetProgPath()+"Default\\stat_txt.tbl"));
   TBLs[1].Load(ConfigIni->ReadString("Files","Images",GetProgPath()+"Default\\images.tbl"));
   TBLs[2].Load(ConfigIni->ReadString("Files","Portdata",GetProgPath()+"Default\\portdata.tbl"));
   TBLs[3].Load(ConfigIni->ReadString("Files","Sfxdata",GetProgPath()+"Default\\sfxdata.tbl"));
   TBLs[4].Load(ConfigIni->ReadString("Files","Mapdata",GetProgPath()+"Default\\mapdata.tbl"));
   Icons.Load(ConfigIni->ReadString("Files","Icons",GetProgPath()+"Default\\cmdicons.grp"));
*/
   Form1->WindowState = wsNormal;
   switch (ConfigIni->ReadInteger("Options","Window",0)) {
       case 0:
            Form1->WindowState = wsNormal;
            break;
       case 1:
            Form1->WindowState = wsMaximized;
            break;
   }

   for (int i=0;i<11;i++) {
       if (i == 0 || i == 1 || i == 5 || i == 6) {
          SetSortingStyle(i,ConfigIni->ReadInteger("Sorting",GetDataType(i)+" Editor",2));
       }
   }

   //Check for the Starcraft installation path in the config file.
   if (ConfigIni->ValueExists("Files","SC") && ConfigIni->ReadString("Files","SC","") != "" && DirectoryExists(ConfigIni->ReadString("Files","SC",""))) {
      SetSCPath(ConfigIni->ReadString("Files","SC",""));
      SetIsSC(true);
   }
   delete ConfigIni;
}
else {
   MessageDlg("The \"DatEdit.ini\" config file was not found. DatEdit will use the default options and generate a config file on exit.", mtInformation, TMsgDlgButtons() << mbOK, 0);
}


if (GetIsSC() == false) {
   //If SC was not found,check for the Starcraft installation path in the registry.
   TRegistry *Reg = new TRegistry();
   Reg->RootKey = HKEY_LOCAL_MACHINE;
   if (Reg->KeyExists("SOFTWARE\\Blizzard Entertainment\\Starcraft")) {
      Reg->OpenKey("SOFTWARE\\Blizzard Entertainment\\Starcraft", false);
      SetSCPath(Reg->ReadString("InstallPath"));
   }
   delete Reg;
   SetIsSC(DirectoryExists(GetSCPath()));

   //Prompt the user for manually locating the Starcraft installation.
   if (GetIsSC() == false) {
      String Path;
      if (MessageDlg("DatEdit could not find information about an installation of Starcraft in the config file and the registry. Would you like to find the StarCraft directory yourself?", mtInformation, TMsgDlgButtons() << mbYes << mbNo, 0) == 6) {
         SelectDirectory("Locate the Starcraft directory or press ESC to cancel","",Path);
         if (Path != "" && DirectoryExists(Path)) {
            SetIsSC(true);
            SetSCPath(Path);
         }
      }
   }

   if (GetIsSC() == false) {
      MessageDlg("DatEdit could not find an installation of Starcraft on this computer.GRP previews will be disabled.", mtInformation, TMsgDlgButtons() << mbOK, 0);
   }
}
//If Starcraft found - load and store the Starcraft MPQ handles.
if (GetIsSC() == true && GetSCPath() != "") {
   SCMPQHandles = new void* [3];
   void *MPQHandle;
   String MPQ[3] = {"Patch_rt.mpq","BrooDat.mpq","StarDat.mpq"};
   for (int i=0;i<3;i++) {
       if (FileExists(GetSCPath()+"\\"+MPQ[i])) {
          if (SFileOpenArchive(String(GetSCPath()+"\\"+MPQ[i]).c_str(),3-i,0,&MPQHandle)) {
             SetSCMPQHandles(i,MPQHandle);
          }
       }
   }
}
};
//---------------------------------------------------------------------------
/*
############################################################################
This functon saves the core properties to DatEdit.ini.
############################################################################
*/

void __fastcall TForm1::SaveConfigExecute(TObject *Sender)
{
TIniFile *ConfigIni = new TIniFile(GetProgPath()+"DatEdit.ini");

if (Form1->WindowState == wsMaximized) {
   ConfigIni->WriteInteger("UserSize","UserWidth",800);
   ConfigIni->WriteInteger("UserSize","UserHeight",580);
}
else {
   ConfigIni->WriteInteger("UserSize","UserWidth",Form1->Width);
   ConfigIni->WriteInteger("UserSize","UserHeight",Form1->Height);
}

for (int i=0;i<11;i++) {
    if (i == 0 || i == 1 || i == 5 || i == 6) {
       if (GetSortingStyle(i) == 4) {
          ConfigIni->WriteInteger("Sorting",GetDataType(i)+" Editor",2);
       }
       else {
          ConfigIni->WriteInteger("Sorting",GetDataType(i)+" Editor",GetSortingStyle(i));
       }
    }
}
ConfigIni->WriteString("Last Opened","Folder",GetLastFolder());
ConfigIni->WriteString("Files","SC",GetSCPath());


if (Form1->WindowState == wsNormal) {
   ConfigIni->WriteInteger("Options","Window",0);
}
else if (Form1->WindowState == wsMaximized) {
   ConfigIni->WriteInteger("Options","Window",1);
}

ConfigIni->EraseSection("Recently Used");
if (MRUD->Count == 0 || MRUD->Items[0]->Caption.Pos("No files in History") != 0) {
    ConfigIni->WriteInteger("Recently Used","History Items",0);
}
else {
    ConfigIni->WriteInteger("Recently Used","History Items",MRUD->Count);
    for (int i=0;i<MRUD->Count;i++) {
        if (MRUD->Items[i]->Caption == "") {
           continue;
        }
        ConfigIni->WriteString("Recently Used",String("File"+String(i+1)),MRUD->Items[i]->Caption);
    }
}
for (int i=0;i<11;i++) {
    ConfigIni->EraseSection(GetDATType(i)+" Bookmarks");
    for (int k=0;k<Bookmarks->Count;k++) {
        if (Bookmarks->Items[k]->Tag == i) {
           for (int j=0;j<Bookmarks->Items[k]->Count;j++) {
               ConfigIni->WriteString(GetDATType(i)+" Bookmarks",String("Item"+String(j+1)),Bookmarks->Items[k]->Items[j]->Caption);
           }
        }
    }
}          
delete ConfigIni;
};
//---------------------------------------------------------------------------
/*
############################################################################
This functon reads the config file (DatEdit.ini) for the many
Options-related properties: exit confirmation, backward reporting,
unit size preview display etc.
############################################################################
*/

void __fastcall TForm1::ReadConfigOptionsExecute(TObject *Sender)
{
   TIniFile *ConfigIni = new TIniFile(GetProgPath()+"DatEdit.ini");

   Options.StartEditor = ConfigIni->ReadInteger("Options","StartEditor",0);
   Options.ConfirmOnExit = ConfigIni->ReadBool("Options","ConfirmOnExit",true);
   Options.UseBackwardReporting = ConfigIni->ReadBool("Options","UseBackwardReporting",true);
   Options.ShowHints = ConfigIni->ReadBool("Options","ShowHints",true);
   Options.ShowSplash = ConfigIni->ReadBool("Options","ShowSplash",true);
   Options.UseCustomLabels = ConfigIni->ReadBool("Options","UseCustomLabels",false);
   Options.UnitSizePreviewType = ConfigIni->ReadInteger("Options","ShowUnitSizePreview",2);
   Options.ShowSelCirclePreview = ConfigIni->ReadBool("Options","CirclePreview",true);
   Options.UseOldOpenDirectory = ConfigIni->ReadBool("Options","UseOldOpenDirectory",false);
   Options.LoadGRPFromMPQ = ConfigIni->ReadBool("Options","LoadGRPFromMPQ",true);

   if (Form1->GetIsSC() == false) {
      Options.ShowSelCirclePreview = false;
      if (Options.UnitSizePreviewType == 2) {
         Options.UnitSizePreviewType = 1;
      }
   }


if (FileExists(ConfigIni->ReadString("Files","Icons",""))) {
   Icons.Load(ConfigIni->ReadString("Files","Icons",""));
}
else {
   if (ConfigIni->FileName == "") {
      MessageDlg(String(ConfigIni->ReadString("Files","Icons",""))+" was not found. Datedit will try to use the default file.", mtInformation, TMsgDlgButtons() << mbOK, 0);
   }
   Icons.Load(GetProgPath()+"Default\\cmdicons.grp");
}

for (int i=0;i<5;i++) {
    if (FileExists(ConfigIni->ReadString("Files",GetTBLType(i),""))) {
       TBLs[i].Load(ConfigIni->ReadString("Files",GetTBLType(i),""));
    }
    else {
       if (ConfigIni->FileName == "") {
          MessageDlg(String(ConfigIni->ReadString("Files",GetTBLType(i),""))+" was not found. Datedit will try to use the default file.", mtInformation, TMsgDlgButtons() << mbOK, 0);
       }
       TBLs[i].Load(GetProgPath()+"Default\\"+GetTBLType(i)+".tbl");
    }
}


   Options.ExternalGRPSource = ConfigIni->ReadString("Files","GRPMPQ","");
   if (Options.ExternalGRPSource != "" && FileExists(Options.ExternalGRPSource)) {
      void *MpqHandle;
      if (SFileOpenArchive(Options.ExternalGRPSource.c_str(),100,0,&MpqHandle) == true) {
         SetGRPMPQHandle(MpqHandle);
      }
   }

   if (ConfigIni->SectionExists("External Links")) {
      for (int i=0;ConfigIni->ReadString("External Links","Program"+String(i+1),"") != "";i++) {
          ExternalPrograms->Add(ConfigIni->ReadString("External Links","Program"+String(i+1),""));
      }
   }
delete ConfigIni;
};
//---------------------------------------------------------------------------
/*
############################################################################
This functon saves out the Options-related properties to DatEdit.ini.
############################################################################
*/

void __fastcall TForm1::SaveConfigOptionsExecute(TObject *Sender)
{
TIniFile *ConfigIni = new TIniFile(GetProgPath()+"DatEdit.ini");
ConfigIni->WriteInteger("Options","StartEditor",Options.StartEditor);
ConfigIni->WriteBool("Options","ConfirmOnExit",Options.ConfirmOnExit);
ConfigIni->WriteBool("Options","UseBackwardReporting",Options.UseBackwardReporting);
ConfigIni->WriteBool("Options","ShowHints",Options.ShowHints);
ConfigIni->WriteBool("Options","ShowSplash",Options.ShowSplash);
ConfigIni->WriteBool("Options","UseCustomLabels",Options.UseCustomLabels);
ConfigIni->WriteInteger("Options","ShowUnitSizePreview",Options.UnitSizePreviewType);
ConfigIni->WriteBool("Options","CirclePreview",Options.ShowSelCirclePreview);
ConfigIni->WriteBool("Options","UseOldOpenDirectory",Options.UseOldOpenDirectory);
ConfigIni->WriteBool("Options","LoadGRPFromMPQ",Options.LoadGRPFromMPQ);

for (int i=0;i<5;i++) {
    if (ExtractRelativePath(GetProgPath(),TBLs[i].FileName) == String("Default\\"+GetTBLType(i)+".tbl")) {
       ConfigIni->WriteString("Files",GetTBLType(i),ExtractRelativePath(GetProgPath(),TBLs[i].FileName));
    }
    else {
       ConfigIni->WriteString("Files",GetTBLType(i),TBLs[i].FileName);
    }
}
ConfigIni->WriteString("Files","Icons",ExtractRelativePath(GetProgPath(),Icons.FileName));
ConfigIni->WriteString("Files","GRPMPQ",Options.ExternalGRPSource);

ConfigIni->EraseSection("External Links");
if (ExternalPrograms->Count > 0) {
   for (int i=0;i<ExternalPrograms->Count;i++) {
       ConfigIni->WriteString("External Links","Program"+String(i+1),ExternalPrograms->Strings[i]);
   }
}
delete ConfigIni;
};
//---------------------------------------------------------------------------
/*
############################################################################
This functon controls which Sorting methods are available in the View menu
in which Editor.
It also loads the property names for the "Property Sort" method.
############################################################################
*/

void __fastcall TForm1::ViewMenuClick(TObject *Sender)
{
if ((GetPage() >= 2 && GetPage() <=4) || GetPage() >=7) {
    SortbyData->Enabled = false;
    SortbyData->Checked = false;
    SortbyOrigin->Enabled = false;
    SortbyOrigin->Checked = false;
}
else if (GetPage() == 5 || GetPage() == 6) {
    SortbyData->Enabled = true;
    SortbyOrigin->Enabled = true;
}
else if (GetPage() == 1) {
    SortbyOrigin->Enabled = true;
    SortbyData->Enabled = false;
    SortbyData->Checked = false;
}
else if (GetPage() == 0) {
    SortbyData->Enabled = true;
    SortbyOrigin->Enabled = true;
}
ViewMenu->Items[GetSortingStyle(GetPage())]->Checked = true;

if (SortbyProperty->Tag != GetPage()) {
   SortbyProperty->Clear();
   bool MenuBreak=false;
   for (int i=0;i<GetDATFile(GetPage())->GetVarcount();i++) {
       TMenuItem* Dummy = new TMenuItem(PropertySort);
       String DummyName = GetDATFormat(GetPage())->Values[String(i)+"Name"];
       Dummy->Caption = DummyName;
       Dummy->AutoCheck = true;
       Dummy->RadioItem = true;
       Dummy->ImageIndex = 0;
       Dummy->OnClick = PropertySortExecute;
       if (i*18 >= Screen->Height && MenuBreak==false) {
          Dummy->Break = mbBarBreak;
          MenuBreak = true;
       }
       if (Dummy->Caption.Pos(":") != 0) {
          TStringList *SubDummyNames = new TStringList();
          SubDummyNames->CommaText = DummyName.SubString(DummyName.Pos(":")+1,DummyName.Length()-DummyName.Pos(":"));
          for (int j=0;j<SubDummyNames->Count;j++) {
              TMenuItem* SubDummy = new TMenuItem(Dummy);
              SubDummy->Caption = SubDummyNames->Strings[j];
              SubDummy->RadioItem = true;
              SubDummy->AutoCheck = true;
              //The ImageIndex property is used to distinguish bitflag-type properties (SubDummy) from normal properties (Dummy)
              SubDummy->ImageIndex = 0xFFFF;
              SubDummy->OnClick = PropertySortExecute;
              Dummy->Add(SubDummy);
          }
          delete SubDummyNames;
          Dummy->Caption = DummyName.SubString(1,DummyName.Pos(":")-1);
          Dummy->AutoCheck = false;
          Dummy->RadioItem = false;
          Dummy->OnClick = NULL;
       }
       SortbyProperty->Add(Dummy);
   }
   SortbyProperty->Tag = GetPage();
}
};
//---------------------------------------------------------------------------
/*
############################################################################
This functon controls the sorting selection events - it also makes the
current Editor reload.
############################################################################
*/

void __fastcall TForm1::SetSortingExecute(TObject *Sender)
{
if (((TMenuItem*)(Sender))->MenuIndex != GetSortingStyle(GetPage())) {
   ((TMenuItem*)(Sender))->Checked = !((TMenuItem*)(Sender))->Checked;
   SetSortingStyle(GetPage(),((TMenuItem*)(Sender))->MenuIndex);
}
Form1->SetListReload(GetPage(),true);
ChangeTab->Execute();
};
//---------------------------------------------------------------------------
/*
############################################################################
This function activates the hint-loading routine. It is called from
the "OnEnter" event of the interface components, so it will only be
shown after specific controls receives focus.
############################################################################
*/
void __fastcall TForm1::LoadHintExecute(TObject *Sender)
{
if (Options.ShowHints == true) {
   InfoText->Text = Hints->Values[((TControl*)(Sender))->Name];
}
else {
   InfoText->Text = "";
}
};
//---------------------------------------------------------------------------
/*
############################################################################
Activated by the click on the "Search" button, this routine activates
the SearchText component's "OnKeyDown" handler, and thus indirectly
launches the list-searching function. Number 13 is the virtual key code
for the ENTER key, which is necessary in the call.
############################################################################
*/
void __fastcall TForm1::SearchButtonClick(TObject *Sender)
{
unsigned short ReturnVirtualKeyCode = 13;
SearchText->OnKeyDown(Sender,ReturnVirtualKeyCode,TShiftState() <<ssShift);
}
//---------------------------------------------------------------------------
/*
############################################################################
Activated by pressing the ENTER key in the search-text textbox or
(programmatically) by the click on the "Search" button, this routine
launches the list-searching function.
############################################################################
*/

void __fastcall TForm1::SearchTextKeyDown(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
if (Key == VK_RETURN && SearchText->Text.IsEmpty() == false) {
   bool InList=false;
   for (int i=0;i<=SearchText->Items->Count;i++) {
       if (SearchText->Items->Strings[i].AnsiCompareIC(SearchText->Text) == 0) {
           InList=true;
           break;
       }
   }
   if (InList == false) {
       SearchText->Items->Add(SearchText->Text);
   }
   SearchList->Execute();
}
};
//---------------------------------------------------------------------------
/*
############################################################################
The list-searching function. Simple yet effective. You may wonder
about the use of the "Tag" property near the end of it - it is used to
determine whether an entry has already been found in the list (value 0)
when the list-parsing loop finishes the search. If an entry has been
found - it will search the list again and find it. If there was no entry
found - it will exit the loop.
############################################################################
*/

void __fastcall TForm1::SearchListExecute(TObject *Sender)
{
signed int Index=0;
int Var;
Var = 1;

if (GetDATEntryList(GetPage())->Selected != NULL) {
   if (GetDATEntryList(GetPage())->Selected->AbsoluteIndex == GetDATEntryList(GetPage())->Items->Count-1) {
      Index = 0;
   }
   else
      Index = GetDATEntryList(GetPage())->Selected->AbsoluteIndex+1;
}
for (signed int i=Index;i<GetDATEntryList(GetPage())->Items->Count;i++) {
   if ((GetDATEntryList(GetPage())->Items->Item[i]->Text.LowerCase()).Pos(SearchText->Text.LowerCase()) != 0) {
       GetDATEntryList(GetPage())->Selected = GetDATEntryList(GetPage())->Items->Item[i];
       Var = 1;
       break;
   }
   if (i>=GetDATEntryList(GetPage())->Items->Count-1) {
       if (Var == 2) {
          break;
       }
       else if (Var != 2) {
          i=-1;
          Var = 2;
       }
   }
}
};
//---------------------------------------------------------------------------
/*
############################################################################
This functon reloads the editor with an appropriate default DAT.
############################################################################
*/

void __fastcall TForm1::ReloadDefaultExecute(TObject *Sender)
{
CheckDATFile(GetProgPath()+"Default\\"+GetDATType(GetPage())+".dat");
};
//---------------------------------------------------------------------------
/*
############################################################################
This routine controls which options are available in the right-click
popup menu.
############################################################################
*/

void __fastcall TForm1::PopupMenuPopup(TObject *Sender)
{
if (GetDATEntryList(GetPage())->Selected != NULL && GetDATEntryList(GetPage())->Selected->HasChildren == false && GetDATEntryList(GetPage())->SelectionCount == 1) {
   (GetDATEntryList(GetPage())->Selected)->Selected = true;

   ClipCopy2->Enabled = true;
   ClipPaste2->Enabled = false;
   if (OpenClipboard(Application->Handle)) {
      void* ClipFileHandle = GlobalAlloc(NULL, sizeof(ClipDAT));
      ClipFileHandle = GetClipboardData(this->ClipFormat);
      if (ClipFileHandle != NULL && ((ClipDAT*)(ClipFileHandle))->DATType == GetPage()) {
         ClipPaste2->Enabled = true;
      }
      CloseClipboard();
   }

   QuickBM->Enabled = true;   
   CopyEntry1->Enabled = true;
   PasteEntry1->Enabled = true;
   if (GetTempDats(GetPage()) == false) {
      PasteEntry1->Enabled = false;
   }
   ReloadEntry1->Enabled = true;

   if (GetDATEntryList(GetPage())->Selected->ImageIndex == 1 && GetDATEntryList(GetPage())->Selected->SelectedIndex == 1) {
      Bookmarkentry1->Enabled = false;
      Erasebookmark1->Visible = true;
      Erasebookmark1->Enabled = true;
   }
   else {
      Bookmarkentry1->Visible = true;
      Bookmarkentry1->Enabled = true;
      Erasebookmark1->Enabled = false;
   }
   QuickBM->Clear();
   QuickBM->Visible = false;
   for (int j=0;j<Bookmarks->Count;j++) {
       if (Bookmarks->Items[j]->Tag == GetPage()) {
          for (int i=0;i<Bookmarks->Items[j]->Count;i++) {
              TMenuItem *Dummy = new TMenuItem(PopupMenu);
              Dummy->Visible = true;
              Dummy->OnClick = BookmarkClickExecute;
              Dummy->AutoHotkeys = maManual;
              Dummy->Caption = (Bookmarks->Items[j]->Items[i]->Caption);
              QuickBM->Add(Dummy);
          }
       QuickBM->Visible = true;
       }
   }
}
else {
      CopyEntry1->Enabled = false;
      PasteEntry1->Enabled = false;
      ClipCopy2->Enabled = false;
      ClipPaste2->Enabled = false;
      ReloadEntry1->Enabled = false;
      Bookmarkentry1->Enabled = false;
      Erasebookmark1->Enabled = false;
      QuickBM->Enabled = false;
}
};
//---------------------------------------------------------------------------
/*
############################################################################
This functon clears all bookmarks.
############################################################################
*/

void __fastcall TForm1::ClearAllBookmarksExecute(TObject *Sender)
{
if (MessageDlg("Are you sure you want to clear all Bookmarks?", mtConfirmation, mbOKCancel, 0) == 1) {
   for (int i=0;i<Bookmarks->Count-4;i++) {
       if (Bookmarks->Items[i]->Tag != -1) {
          for (int j=0;j<GetDATFile(Bookmarks->Items[i]->Tag)->GetOutputEntrycount();j++) {
              GetDATEntryList(Bookmarks->Items[i]->Tag)->Items->Item[j]->ImageIndex = 0;
              GetDATEntryList(Bookmarks->Items[i]->Tag)->Items->Item[j]->SelectedIndex = 0;
          }
          Bookmarks->Delete(i);
          i--;
       }
   }
}
};
//---------------------------------------------------------------------------
/*
############################################################################
This routine clears bookmarks for the current editor only.
############################################################################
*/
void __fastcall TForm1::ClearBookmarksExecute(TObject *Sender)
{
for (int i=0;i<Bookmarks->Count-4;i++) {
    if (Bookmarks->Items[i]->Tag == GetPage()) {
       Bookmarks->Delete(i);
       break;
    }
}
for (int i=0;i<GetDATFile(GetPage())->GetOutputEntrycount();i++) {
    GetDATEntryList(GetPage())->Items->Item[i]->ImageIndex = 0;
    GetDATEntryList(GetPage())->Items->Item[i]->SelectedIndex = 0;
}
};
//---------------------------------------------------------------------------
/*
############################################################################
This functon adds a new bookmark based on the current selection.
############################################################################
*/

void __fastcall TForm1::BookmarkEntryExecute(TObject *Sender)
{
GetDATEntryList(GetPage())->Selected->ImageIndex = 1;
GetDATEntryList(GetPage())->Selected->SelectedIndex = 1;
TMenuItem *Dummy = new TMenuItem(Form1);
Dummy->Caption = GetDATEntryList(GetPage())->Selected->Text;
Dummy->OnClick = BookmarkClickExecute;
for (int i=0;i<=Bookmarks->Count-4;i++) {
    if (Bookmarks->Items[i]->Tag == GetPage()) {
       Bookmarks->Items[i]->Add(Dummy);
       break;
    }
    else if (i == Bookmarks->Count-4) {
       TMenuItem *NewBMList = new TMenuItem(Form1);
       NewBMList->Tag = GetPage();
       NewBMList->Caption = Editors->Pages[GetPage()]->Caption+" Editor";
       NewBMList->Add(Dummy);
       Bookmarks->Insert(Bookmarks->Count-4,NewBMList);
       break;
    }
}
};
//---------------------------------------------------------------------------
/*
############################################################################
This routine removes individual bookmarks from the list.
############################################################################
*/
void __fastcall TForm1::BookmarkEraseExecute(TObject *Sender)
{
GetDATEntryList(GetPage())->Selected->ImageIndex = 0;
GetDATEntryList(GetPage())->Selected->SelectedIndex = 0;
for (int i=0;i<=Bookmarks->Count-4;i++) {
    if (Bookmarks->Items[i]->Tag == GetPage()) {
       for (int j=0;j<Bookmarks->Items[i]->Count;j++) {
           if (GetBookmarkID(Bookmarks->Items[i]->Items[j]->Caption) == GetDATEntryList(GetPage())->Selected->StateIndex) {
              Bookmarks->Items[i]->Delete(j);
              if (Bookmarks->Items[i]->Count == 0) {
                 Bookmarks->Delete(i);
              }
           }
       }
       break;
    }
    break;
}
};
//---------------------------------------------------------------------------
/*
############################################################################
This routine loads up the appropriate entry after a bookmarks was clicked.
############################################################################
*/

void __fastcall TForm1::BookmarkClickExecute(TObject *Sender)
{
int DatTypeID;
if (((TMenuItem*)(Sender))->Parent->Caption != "Quick Bookmarks") {
   DatTypeID = ((TMenuItem*)(Sender))->Parent->Tag;
}
else {
   DatTypeID = GetPage();
}

int Value = GetBookmarkID(((TMenuItem*)(Sender))->Caption);
Editors->ActivePageIndex = DatTypeID;
if (GetSortingStyle(DatTypeID) == 2) {
    GetDATEntryList(DatTypeID)->Selected = GetDATEntryList(DatTypeID)->Items->Item[Value];
}
else if (GetSortingStyle(DatTypeID) != 2) {
    GetDATEntryList(DatTypeID)->Selected = GetDATEntryList(DatTypeID)->Items->Item[LookEntry(Value,DatTypeID)];
}
ChangeTab->Execute();
};
//---------------------------------------------------------------------------
/*
############################################################################
This routine reloads a particular entry's data from the default DAT file.
############################################################################
*/
void __fastcall TForm1::ReloadEntryExecute(TObject *Sender)
{
int EntryID = GetDATEntryList(GetPage())->Selected->StateIndex;
GetDATFile(GetPage())->ReloadEntryFromDefault(EntryID);
ChangeTab->Execute();
};
//---------------------------------------------------------------------------
/*
############################################################################
This routine, used in the Images Editor, checks for entries using the
same IscriptID or the same GRP file, and outputs the result into the
"Used by" box.
############################################################################
*/
void __fastcall TForm1::ImgReferenceExecute(TObject *Sender)
{
int TargetID,Modulo;
UsedList->Items->Clear();

if (Sender == ImgGRPRef) {
   TargetID = ImgGRP->Text.ToInt();
   Modulo = 0;
}
else if (Sender == ImgIscriptRef) {
   TargetID = ImgIscriptID->Text.ToInt();
   Modulo = 7;
}
for (int i=0;i<GetDATFile(4)->GetOutputEntrycount();i++) {
    if (GetDATFile(4)->GetData()[i*GetDATFile(4)->GetVarcount()+Modulo] == TargetID) {
       UsedList->Items->Add("[I"+String(i)+"] "+String(GetDATEntryNames(4)->Strings[i]));
    }
}
}
//---------------------------------------------------------------------------
/*
############################################################################
This function runs the appropriate routine for the items that are
dragged and dropped onto the program: either files or directories.
############################################################################
*/
void __fastcall TForm1::WmDropFiles(TWMDropFiles& Message)
{
char DropFiles[MAX_PATH];
HDROP hDrop = (HDROP)Message.Drop;
int numFiles = DragQueryFile(hDrop, -1, NULL, NULL);
for (int i=0;i < numFiles;i++) {
    DragQueryFile(hDrop, i, DropFiles, sizeof(DropFiles));
    if (DirectoryExists(DropFiles)) {
       LoadDATDir(DropFiles);
    }
    else if (FileExists(DropFiles)) {
       void *MpqHandle;
       if (SFileOpenArchive(DropFiles,0,0,&MpqHandle)) {
          AddHistoryItem(DropFiles);
          SetLastFolder(ExtractFileDir(DropFiles));
          CheckMPQFile(DropFiles);
       }
       else if (ExtractFileExt(DropFiles).LowerCase() == ".dat") {
          AddHistoryItem(DropFiles);
          SetLastFolder(ExtractFileDir(DropFiles));
          CheckDATFile(DropFiles);
       }
       else {
          MessageDlg(String("\""+String(DropFiles)+"\" is not a file that DatEdit can recognize or a dummy MPQ archive."), mtError, TMsgDlgButtons() << mbOK, 0);
       }
       SFileCloseArchive(MpqHandle);
    }
}
DragFinish(hDrop);
};
//---------------------------------------------------------------------------
/*
############################################################################
This routine handles the Up/Down arrow controls that are used with the
Time-related properties in Weapons,Upgrades and Tech Editors. It adds up
24 to the hex value (i.e. 1 sec on fastest), and if the value is equal to or
below 24, it goes by 1. It won't go below 0 and over 65535 (since the
time-related properties take 2-bytes of space.
############################################################################
*/
void __fastcall TForm1::UnitTimeSecUpDownChangingEx(TObject *Sender,
      bool &AllowChange, short NewValue, TUpDownDirection Direction)
{
TEdit *TargetEdit=NULL;
if (Sender == UnitTimeSecUpDown) {
   TargetEdit = UnitTime;
}
else if (Sender == UpgTimeSecUpDown) {
   TargetEdit = UpgTime;
}
else if (Sender == UpgFactorTimeSecUpDown) {
   TargetEdit = UpgFactorTime;
}
else if (Sender == TechTimeSecUpDown) {
   TargetEdit = TechTime;
}

if (TargetEdit != NULL) {
   if (Direction == updUp) {
      if (TargetEdit->Text.ToDouble()+24 < 65535) {
         if  (TargetEdit->Text.ToDouble() < 24) {
             TargetEdit->Text = TargetEdit->Text.ToDouble()+1;
         }
         else {
             TargetEdit->Text = TargetEdit->Text.ToDouble()+24;
         }
      }
      else {
         TargetEdit->Text = 65535;
      }
   }
   else if (Direction == updDown) {
      if (TargetEdit->Text.ToDouble()-24 > 0) {
         TargetEdit->Text = TargetEdit->Text.ToDouble()-24;
      }
      else if (TargetEdit->Text.ToDouble()-1 > 0) {
         TargetEdit->Text = TargetEdit->Text.ToDouble()-1;
      }
      else {
         TargetEdit->Text = 0;
      }
   }
}
};
//---------------------------------------------------------------------------
/*
############################################################################
This routine performs the Property Sort, based on the selected property.
It uses the QuickSort algo run over a custom SortTable class via a custom
sort_function.
############################################################################
*/
void __fastcall TForm1::PropertySortExecute(TObject *Sender)
{
SetSortingStyle(GetPage(),4);

SortTable *Vars = new SortTable [GetDATFile(GetPage())->GetOutputEntrycount()];
for (int i=0;i<GetDATFile(GetPage())->GetOutputEntrycount();i++) {
    Vars[i].ID = i;
    if (((TMenuItem*)(Sender))->ImageIndex == 0xFFFF) {
       Vars[i].Value = ~(bool)(int(Power(2,float(((TMenuItem*)(Sender))->MenuIndex)))&GetDATFile(GetPage())->GetData()[i*GetDATFile(GetPage())->GetVarcount()+((TMenuItem*)Sender)->Parent->MenuIndex]);
    }
    else {
       Vars[i].Value = GetDATFile(GetPage())->GetData()[i*GetDATFile(GetPage())->GetVarcount()+((TMenuItem*)Sender)->MenuIndex];
    }
}
qsort((void *)Vars,GetDATFile(GetPage())->GetOutputEntrycount(),8, sort_function);

for (int i=0;i+1<Form1->GetDATFile(GetPage())->GetOutputEntrycount();i++) {
    if (Vars[i].Value == Vars[i+1].Value && Vars[i].ID > Vars[i+1].ID) {
       int temp1 = Vars[i+1].ID;
       int temp2 = Vars[i+1].Value;
       Vars[i+1].ID = Vars[i].ID;
       Vars[i+1].Value = Vars[i].Value;
       Vars[i].ID = temp1;
       Vars[i].Value = temp2;
       i=-1;
    }
}

GetDATEntryList(GetPage())->Items->BeginUpdate();
GetDATEntryList(GetPage())->ShowRoot = false;
GetDATEntryList(GetPage())->ShowLines = false;
GetDATEntryList(GetPage())->ShowButtons = false;
GetDATEntryList(GetPage())->ClearSelection();
GetDATEntryList(GetPage())->Items->Clear();
TStringList *List = new TStringList;
if (Options.UseCustomLabels == false || (GetPage() != 0 && GetPage() != 1 && GetPage() != 5 && GetPage() != 6)) {
   List->AddStrings(GetDATEntryNames(GetPage()));
}
else if (Options.UseCustomLabels == true) {
     if (GetTBLIsMPQImport(0) == false) {
        ReadTBL(&Form1->TBLs[0], (TStrings*)List);
     }
     else {
        ReadTBL(&Form1->MpqTBLs[0], (TStrings*)List);
     }
}
String Name="";
for (int i=0;i<Form1->GetDATFile(GetPage())->GetOutputEntrycount();i++) {
    if (List->Strings[i].Pos("None") != 0 && Form1->Options.UseCustomLabels == false) {
       continue;
    }
    else {
       Name = "["+String(Vars[i].ID)+"] "+List->Strings[Vars[i].ID];
       TTreeNode* Dummy = GetDATEntryList(GetPage())->Items->AddChild(NULL, Name);
       Dummy->StateIndex = Vars[i].ID;
    }
}
delete List;
GetDATEntryList(GetPage())->Items->EndUpdate();   
};
//---------------------------------------------------------------------------
/*
############################################################################
This routine reads bookmarks from the config file. It is separate from
the main config-reading routine because of its size.
############################################################################
*/
void __fastcall TForm1::ReadBookmarksExecute(TObject *Sender)
{
TIniFile *ConfigIni = new TIniFile(GetProgPath()+"DatEdit.ini");
for (int i=0;i<11;i++) {
    for (int j=0;;j++) {
        String Text = ConfigIni->ReadString(String(GetDATType(i)+" Bookmarks"),"Item"+String(j+1),"X");
        if (Text == "X") {
           break;
        }
        else {
           TMenuItem *Dummy = new TMenuItem(Form1);
           Dummy->Caption = Text;
           Dummy->OnClick = BookmarkClickExecute;

           if (GetSortingStyle(i) == 2) {
              GetDATEntryList(i)->Items->Item[GetBookmarkID(Text)]->SelectedIndex=1;
              GetDATEntryList(i)->Items->Item[GetBookmarkID(Text)]->ImageIndex=1;
           }
           else if (GetSortingStyle(i) != 2) {
              GetDATEntryList(i)->Items->Item[LookEntry(GetBookmarkID(Text),i)]->SelectedIndex=1;
              GetDATEntryList(i)->Items->Item[LookEntry(GetBookmarkID(Text),i)]->ImageIndex=1;
           }



           for (int k=0;k<Bookmarks->Count;k++) {
               if (Bookmarks->Items[k]->Tag == i) {
                  Bookmarks->Items[k]->Add(Dummy);
                  break;
               }
               else if (k == Bookmarks->Count-1) {
                  TMenuItem *NewBMList = new TMenuItem(Form1);
                  NewBMList->Tag = i;
                  NewBMList->Caption = Editors->Pages[i]->Caption+" Editor";
                  NewBMList->Add(Dummy);
                  Bookmarks->Insert(Bookmarks->Count-4,NewBMList);
                  break;
               }
           }
        }
    }
}
delete ConfigIni;
};
//---------------------------------------------------------------------------
/*
############################################################################
This handler shows a FAQ Q&A in a message box.
############################################################################
*/
void __fastcall TForm1::FAQClickExecute(TObject *Sender)
{
MessageDlg(((TMenuItem*)(Sender))->Caption+"\n\n"+FAQ->Values["Answer"+String(((TMenuItem*)(Sender))->MenuIndex)], mtInformation, TMsgDlgButtons() << mbOK, 0);
};
//---------------------------------------------------------------------------
/*
############################################################################
This function loads the FAQ menu with items read from the "Data\FAQ.txt" file.
############################################################################
*/               
void __fastcall TForm1::LoadFAQExecute(TObject *Sender)
{
for (int i=0;;i++) {
    if (FAQ->Values["Question"+String(i)] != "") {
       TMenuItem *Dummy = new TMenuItem(Form1);
       Dummy->Caption = String(i+1)+" - "+FAQ->Values["Question"+String(i)];
       Dummy->OnClick = FAQClickExecute;
       FAQMenu->Add(Dummy);
    }
    else {
       if (i==0) {
          MessageDlg("The FAQ is empty. Consider reinstalling the \"Data/FAQ.txt\" file", mtInformation, TMsgDlgButtons() << mbOK, 0);
       }
       else {
          FAQMenu->Click();
       }
       break;
    }
}
};
//---------------------------------------------------------------------------
/*
############################################################################
A clone to the list searching routine, this one is activated when the
user presses a key while on the entry listing. The normal hotkeys doesn't
work because the entry names begin with the entry IDs, hence a custom
routine.
############################################################################
*/

void __fastcall TForm1::ListKeyPress(TObject *Sender, char &Key)
{   
signed int Index=0;
int Var = 1;
if (GetDATEntryList(GetPage())->Selected == NULL) {
   Index = 0;
}
else if (GetDATEntryList(GetPage())->Selected != NULL) {
   if (GetDATEntryList(GetPage())->Selected->AbsoluteIndex == GetDATEntryList(GetPage())->Items->Count-1) {
      Index = 0;
   }
   else {
      Index = GetDATEntryList(GetPage())->Selected->AbsoluteIndex+1;
   }
}
for (signed int i=Index;i<GetDATEntryList(GetPage())->Items->Count;i++) {
   if (String(GetDATEntryList(GetPage())->Items->Item[i]->Text.LowerCase()[String(GetDATEntryList(GetPage())->Items->Item[i]->Text).Pos("]")+2]) == String(Key).LowerCase()) {
       GetDATEntryList(GetPage())->Selected = GetDATEntryList(GetPage())->Items->Item[i];
       Var = 1;
       break;
   }
   if (i>=GetDATEntryList(GetPage())->Items->Count-1) {
       if (Var == 2) {
          break;
       }
       else if (Var != 2) {
          i=-1;
          Var = 2;
       }
   }
}
};
//---------------------------------------------------------------------------
/*
############################################################################
This handler moves the "Used by" text along with the splitter control.
############################################################################
*/
void __fastcall TForm1::InfoboxSplitterMoved(TObject *Sender)
{
LabelUsed->Left = ((TControl*)(Sender))->Left+3;        
}
//---------------------------------------------------------------------------
/*
############################################################################
This handler responds to changes in the Support Programs list.
It reflects the changes in the Support Programs menu and the Options
list.
############################################################################
*/
void __fastcall TForm1::ExternalProgramsChangeExecute(TObject *Sender)
{                    
ExternalProgMenu->Clear();
if (Application->FindComponent("OptionsBox") != NULL) {
   OptionsBox->ExternalProgList->Clear();
}      
if (ExternalPrograms->Count == 0) {
   TMenuItem *Dummy = new TMenuItem(Form1);
   Dummy->Caption = "Set External links under File->Options";
   Dummy->Enabled = false;
   ExternalProgMenu->Add(Dummy);
}
else if (ExternalPrograms->Count > 0) {
   if (Application->FindComponent("OptionsBox") != NULL && ExternalPrograms->Text != OptionsBox->ExternalProgList->Items->Text) {
      for (int i=0;i<ExternalPrograms->Count;i++) {
          TMenuItem* NewItem = new TMenuItem (Form1);
          NewItem->Caption = "["+String(i+1)+"]  "+ExtractFileName(ExternalPrograms->Strings[i]);
          NewItem->OnClick = LoadExternalProgramExecute;
          ExternalProgMenu->Add(NewItem);
          OptionsBox->ExternalProgList->AddItem("["+String(i+1)+"]  "+ExternalPrograms->Strings[i],NULL);
      }
   }
}
}
//---------------------------------------------------------------------------
/*
############################################################################
This routine launches a selected Support Program.
############################################################################
*/
void __fastcall TForm1::LoadExternalProgramExecute(TObject *Sender)
{
String ProgPath = ExternalPrograms->Strings[((TMenuItem*)(Sender))->MenuIndex];
if (FileExists(ProgPath)) {
   ShellExecute(Application->Handle,"open",ProgPath.c_str(),"",ExtractFilePath(ProgPath).c_str(),SW_SHOW);
}
else {
   MessageDlg("The selected file does not exist!", mtError, TMsgDlgButtons() <<mbOK, 0);
}
}
//---------------------------------------------------------------------------
/*
############################################################################
This handler jumps to the appropriate entry in the list after the "->"
button was pressed.
############################################################################
*/
void __fastcall TForm1::JumpToIDButtonClick(TObject *Sender)
{
if (JumpToID->Text.ToInt() < GetDATEntryList(GetPage())->Items->Count && (JumpToID->Text.IsEmpty() == false) && (GetDATEntryList(GetPage())->Items->Count != 0) && ElGrandoListos->Enabled == true && JumpToID->Text.ToInt() >= 0) {
   JumpToID->Color = clBlack;
   if (GetSortingStyle(GetPage()) == 2) {
      GetDATEntryList(GetPage())->Selected = GetDATEntryList(GetPage())->Items->Item[JumpToID->Text.ToInt()];
   }
   else if (GetSortingStyle(GetPage()) != 2) {
      GetDATEntryList(GetPage())->Selected = GetDATEntryList(GetPage())->Items->Item[LookEntry(JumpToID->Text.ToInt(),GetPage())];
   }
   ChangeTab->Execute();
}
else {
   JumpToID->Color = clRed;
}
};
//---------------------------------------------------------------------------
/*
############################################################################
This handler changes the "HP Bar Length" property when the up/down
control is used. Direct values from the TUDBtnType enum are used because
of some ambiguity that the Borland compiler doesn't like ;) 
############################################################################
*/
void __fastcall TForm1::SpriteHPBarboxUpDownClick(TObject *Sender,
      TUDBtnType Button)
{
if (Button == 0) {
   SpriteHPBar->Text = SpriteHPBar->Text.ToInt()+3;
}
else if (Button == 1) {
   SpriteHPBar->Text = SpriteHPBar->Text.ToInt()-3;
}
}
//---------------------------------------------------------------------------
/*
############################################################################
This handler repaints the HP Bar preview. 
############################################################################
*/
void __fastcall TForm1::HPBarPrevPaint(TObject *Sender)
{
DrawHPBar(GetDATFile(3)->GetData()[GetDATEntryList(3)->Selected->Index*GetDATFile(3)->GetVarcount()+1]);
}
//---------------------------------------------------------------------------
/*
############################################################################
This routine reads the property labeles from an external file (Data/Labels.txt)
and applies them to the appropriate interface controls using the contents
of the file, which directly matches the property names to interface
control names using the "Name=Value" scheme. 
############################################################################
*/
void __fastcall TForm1::ReadLabelsExecute(TObject *Sender)
{
TStringList *Labels = new TStringList;
Labels->LoadFromFile(GetProgPath()+"Data\\Labels.txt");
if (Labels->Count > 0) {
   TLabel* tmp;
   TCheckBox* tmp2;
   for (int i=0;i<Labels->Count;i++) {
       if (Labels->Names[i] != "" && Form1->FindComponent(Labels->Names[i])) {
          if (Form1->FindComponent("Label"+Labels->Names[i]) && String(((TObject*)(Form1->FindComponent("Label"+Labels->Names[i])))->ClassName()) == "TLabel") {
             tmp =((TLabel*)((TObject*)(Form1->FindComponent("Label"+Labels->Names[i]))));
             tmp->Caption = Labels->Values[Labels->Names[i]]+":";
             tmp->Top = ((TControl*)(Form1->FindComponent(Labels->Names[i])))->Top+3;
             tmp->Left = ((TControl*)(Form1->FindComponent(Labels->Names[i])))->Left-tmp->Width-1;
          }
          else if (String(((TObject*)(Form1->FindComponent(Labels->Names[i])))->ClassName()) == "TCheckBox") {
             tmp2 = ((TCheckBox*)((TObject*)(Form1->FindComponent(Labels->Names[i]))));
             tmp2->Caption = Labels->Values[Labels->Names[i]];
          }
       }
   }
   tmp = new TLabel(Form1);
   tmp2 = new TCheckBox(Form1);
   delete tmp,tmp2;
}
delete Labels;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ClipCopyClick(TObject *Sender)
{
if (GetDATEntryList(GetPage())->Selected != NULL) {
   if (OpenClipboard(Application->Handle)) {
      if (EmptyClipboard()) {
         void* ClipFileHandle = GlobalAlloc(NULL,sizeof(ClipDAT));
         ((ClipDAT*) ClipFileHandle)->DATType = GetPage();
         ((ClipDAT*) ClipFileHandle)->EntryID = GetDATEntryList(GetPage())->Selected->StateIndex;
         GetDATFile(GetPage())->CopyClipEntry((ClipDAT*) ClipFileHandle,GetDATEntryList(GetPage())->Selected->StateIndex);
         if (!SetClipboardData(this->ClipFormat, ClipFileHandle)) {
            MessageDlg("Failed to copy to the clipboard, copying aborted!", mtError, TMsgDlgButtons() <<mbOK, 0);
         }
      }
      else {
         MessageDlg("Failed to clear the clipboard, copying aborted!", mtError, TMsgDlgButtons() <<mbOK, 0);
      }
      CloseClipboard();
   }
   else {
      MessageDlg("Failed to access the clipboard, copying aborted!", mtError, TMsgDlgButtons() <<mbOK, 0);
   }
}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ClipPasteClick(TObject *Sender)
{
   if (OpenClipboard(Application->Handle)) {
      void* ClipFileHandle = GlobalAlloc(NULL,sizeof(ClipDAT));
      if (ClipFileHandle) {
         ClipFileHandle = GetClipboardData(this->ClipFormat);
         if (ClipFileHandle != NULL) {
            GetDATFile(GetPage())->PasteClipEntry((ClipDAT*)ClipFileHandle,GetDATEntryList(GetPage())->Selected->StateIndex);
            ChangeTab->Execute();
         }
         else {
            MessageDlg("Failed to find an object in the clipboard, pasting aborted!", mtError, TMsgDlgButtons() <<mbOK, 0);
         }
      }
      else {
         MessageDlg("Failed to find an object in the clipboard, pasting aborted!", mtError, TMsgDlgButtons() <<mbOK, 0);
      }
      CloseClipboard();
      GlobalFree(ClipFileHandle);
   }
   else {
      MessageDlg("Failed to access the clipboard, pasting aborted!", mtError, TMsgDlgButtons() <<mbOK, 0);
   }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::OrdHighlightClearClick(TObject *Sender)
{
OrdHighlight->Text = 65535;        
}
//---------------------------------------------------------------------------

