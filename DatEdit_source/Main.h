//---------------------------------------------------------------------------
#ifndef MainH
#define MainH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Menus.hpp>
#include <io.h>
#include <fcntl.h>
#include <stdio.h>
#include <math.h>
#include <shellapi.h>
#include <ActnList.hpp>
#include <StdActns.hpp>
#include <ComCtrls.hpp>
#include <Dialogs.hpp>
#include <StrUtils.hpp>
#include <ExtCtrls.hpp>
#include <AppEvnts.hpp>
#include <FileCtrl.hpp>
#include <IniFiles.hpp>
#include <Buttons.hpp>
#include <Registry.hpp>
#include <ValEdit.hpp>
#include <Math.hpp>
#include <ImgList.hpp>
#include <Graphics.hpp>
#include "FileData.h"
//---------------------------------------------------------------------------

class SortTable {
public:
      int ID;
      int Value;
};
  
int sort_function( const void *a, const void *b);
int sort_function( const void *a, const void *b)
{
   return(CompareValue(((SortTable*)(a))->Value,((SortTable*)(b))->Value));
}
//---------------------------------------------------------------------------

class CustomFile {
public:
      String FileName;
      void *Data;
      int Size;
      CustomFile ();
      void Load(String FileName);
      void LoadBuffer(void *Buffer,int Size);
      bool IsEqual(CustomFile File);
};

CustomFile::CustomFile () {
     this->Size = 0;
     this->FileName = "";
     this->Data = NULL;
};

void CustomFile::Load (String FileName) {
     this->FileName = FileName;
     int Handle = FileOpen(FileName, 0);
     if (Handle != -1) {
        this->Size = FileSeek(Handle,0,2);
        this->Data = new char [this->Size];
        FileSeek(Handle,0,0);
        if (FileRead(Handle,this->Data,this->Size) != this->Size) {
           MessageDlg(String("Failed to load "+this->FileName+". DatEdit may not work properly."), mtError, TMsgDlgButtons() << mbOK, 0);
        }
     }
     else {
        MessageDlg(String(this->FileName+" was not found. DatEdit may not work properly."), mtError, TMsgDlgButtons() << mbOK, 0);
     }
     FileClose(Handle);
};

bool CustomFile::IsEqual (CustomFile File) {
     if (this->FileName == File.FileName) {
        if (this->Size == File.Size) {
           if (this->Data == File.Data) {
              return 1;
           }
           else {
              return 0;
           }
        }
        else {
           return 0;
        }
     }
     else {
        return 0;
     }
};

void CustomFile::LoadBuffer (void *Buffer, int Size) {
     this->FileName = "Mpq import";
     this->Size = Size;
     this->Data = new char[this->Size];
     if (Buffer != NULL) {
        this->Data = (char*) Buffer;
     }
     else {
        MessageDlg(String("Failed to load "+this->FileName+". DatEdit may not work properly."), mtError, TMsgDlgButtons() << mbOK, 0);
     }
};
//---------------------------------------------------------------------------

class ProgramOptions {
public:
      int StartEditor,UnitSizePreviewType;
      bool ShowHints,ConfirmOnExit,ShowSplash,UseBackwardReporting,UseCustomLabels,ShowSelCirclePreview,UseOldOpenDirectory,LoadGRPFromMPQ;
      String ExternalGRPSource;
};
//---------------------------------------------------------------------------

class TForm1 : public TForm
{
__published:
        TActionList *Actions;
        TFileExit *Exit;
        TAction *Open;
        TPageControl *Editors;
        TTabSheet *TechEdit;
        TGroupBox *TechCost;
        TLabel *LabelTechMinerals;
        TLabel *LabelTechVespene;
        TLabel *LabelTechTime;
        TLabel *LabelTechEnergy;
        TEdit *TechMinerals;
        TEdit *TechVespene;
        TEdit *TechTime;
        TEdit *TechEnergy;
        TGroupBox *TechProperties;
        TLabel *LabelRace;
        TLabel *LabelTechUnk;
        TEdit *TechUnk;
        TComboBox *TechRace;
        TCheckBox *TechUnused;
        TCheckBox *TechBW;
        TGroupBox *TechDisplay;
        TLabel *LabelTechIcon;
	TLabel *LabelTechLabel;
        TComboBox *TechIconList;
        TComboBox *TechLabelList;
        TTabSheet *FlingyEdit;
        TLabel *LabelFlingySprite;
        TLabel *LabelFlingySpeed;
        TLabel *LabelFlingyAcceleration;
        TLabel *LabelFlingyHaltDist;
        TLabel *LabelFlingyTurnRad;
        TLabel *LabelFlingyMoveControl;
        TEdit *FlingySprite;
        TEdit *FlingySpeed;
        TTabSheet *SpriteEdit;
        TTabSheet *ImageEdit;
        TTabSheet *SoundEdit;
        TTabSheet *PortEdit;
        TTabSheet *MapEdit;
        TTabSheet *UpgradeEdit;
        TTabSheet *OrderEdit;
        TTabSheet *WeapEdit;
        TTabSheet *UnitEdit;
        TEdit *SpriteImage;
        TLabel *LabelSpriteImage;
        TGroupBox *SpriteProperties;
        TCheckBox *SpriteUnk1;
        TCheckBox *SpriteVisible;
        TGroupBox *FlingyGenProp;
        TGroupBox *UpgBaseCost;
        TEdit *UpgMinerals;
        TEdit *UpgVespene;
        TEdit *UpgTime;
        TLabel *LabelUpgMinerals;
        TLabel *LabelUpgVespene;
        TLabel *LabelUpgTime;
        TGroupBox *UpgFactCost;
        TLabel *LabelUpgFactorMinerals;
        TLabel *LabelUpgFactorVespene;
        TLabel *LabelUpgFactorTime;
        TEdit *UpgFactorMinerals;
        TEdit *UpgFactorVespene;
	TEdit *UpgFactorTime;
        TGroupBox *UpgDisplay;
        TLabel *LabelUpgIcon;
        TLabel *LabelUpgLabel;
        TComboBox *UpgIconList;
        TComboBox *UpgLabelList;
        TGroupBox *UpgProp;
        TLabel *LabelUpgRace;
        TEdit *UpgRepeats;
        TEdit *UpgUnk;
        TLabel *LabelUpgRepeats;
        TCheckBox *UpgIsBW;
        TLabel *LabelUpgUnk;
        TGroupBox *ImgGenProp;
        TGroupBox *ImgAnim;
        TGroupBox *ImgDrawProp;
        TEdit *SoundUnk1;
        TEdit *SoundUnk2;
        TEdit *SoundUnk3;
        TLabel *LabelSoundUnk1;
        TLabel *LabelSoundUnk2;
        TLabel *LabelSoundUnk3;
        TLabel *LabelSoundUnk4;
        TGroupBox *SoundGenProp;
        TEdit *SoundUnk4;
        TGroupBox *PortDirProp;
        TEdit *PortFile;
        TEdit *PortSMKChange;
        TLabel *LabelPortFile;
        TLabel *LabelPortUnk1;
        TLabel *LabelPortSMK;
        TLabel *LabelMapFile;
        TGroupBox *MapData;
        TAction *ChangeTab;
        TComboBox *UpgRace;
        TAction *Save;
        TGroupBox *WeapDamageProperties;
        TGroupBox *WeapRange;
        TEdit *WeapRangeMin;
        TEdit *WeapDamageAmount;
        TEdit *WeapDamageBonus;
        TEdit *WeapDamageFactor;
        TEdit *WeapDamageCooldown;
        TLabel *LabelWeapDamageAmount;
        TLabel *LabelWeapDamageBonus;
        TLabel *LabelWeapDamageFactor;
        TLabel *LabelWeapDamageCooldown;
        TLabel *LabelWeapRangeMin;
        TLabel *LabelWeapRangeMax;
        TEdit *WeapRangeMax;
        TGroupBox *WeapSplashRads;
        TEdit *WeapSplashInner;
        TEdit *WeapSplashMed;
        TEdit *WeapSplashOuter;
        TLabel *LabelWeapSplashInner;
        TLabel *LabelWeapSplashMed;
        TLabel *LabelWeapSplashOuter;
        TComboBox *WeapDamageUpgrade;
        TLabel *LabelWeapDamageUpgrade;
        TComboBox *WeapDamageType;
        TComboBox *WeapDamageExplosion;
        TLabel *LabelWeapDamageType;
        TLabel *LabelWeapUnused;
        TLabel *LabelWeapDamageExplosion;
        TGroupBox *WeapGraphical;
        TComboBox *WeapGraphicsList;
        TLabel *LabelWeapGraphics;
        TEdit *WeapAttackAngle;
        TEdit *WeapLaunchSpin;
        TLabel *LabelWeapAttackAngle;
        TLabel *LabelWeapForwardOffset;
        TLabel *LabelWeapUpwardOffset;
        TLabel *LabelWeapLaunchSpin;
        TLabel *LabelWeapRemoveAfter;
        TLabel *LabelWeapBehaviour;
        TComboBox *WeapBehaviour;
        TEdit *MapFile;
        TLabel *LabelMapEq;
        TPageControl *UnitTabs;
        TTabSheet *UnitBasic;
        TTabSheet *UnitSound;
        TTabSheet *UnitAdv;
	TTabSheet *UnitGraphics;
        TTabSheet *UnitSE;
        TTabSheet *UnitAI;
        TButton *FlingySpriteJump;
        TButton *SpriteImageJump;
        TGroupBox *UnitWeapons;
        TComboBox *UnitWeaponGroundList;
        TComboBox *UnitWeaponAirList;
        TLabel *LabelUnitWeaponGround;
        TLabel *LabelUnitGroundMax;
        TLabel *LabelUnitAirMax;
        TLabel *LabelUniWeaponAir;
        TButton *UnitWeaponGroundJump;
        TButton *UnitWeaponAirJump;
        TEdit *UnitSupReq;
        TLabel *LabelUnitSupReq;
        TLabel *LabelUnitSpaceReq;
        TLabel *LabelUnitScoreBuild;
        TLabel *LabelUnitSupProv;
        TLabel *LabelUnitSpaceProv;
        TLabel *LabelUnitScoreDestroy;
        TGroupBox *WeapTarget;
        TAction *ChangeDataBox;
        TAction *ExitEdit;
        TPanel *ElGrandoListos;
	TCheckBox *WeapTarget001;
	TCheckBox *WeapTarget002;
	TCheckBox *WeapTarget004;
	TCheckBox *WeapTarget008;
	TCheckBox *WeapTarget010;
	TCheckBox *WeapTarget020;
	TCheckBox *WeapTarget040;
	TCheckBox *WeapTarget080;
        TCheckBox *WeapTarget100;
        TAction *JumpToDAT;
	TGroupBox *OrdFlags;
        TCheckBox *OrdWeapTarg;
	TCheckBox *OrdUnk2;
	TCheckBox *OrdUnk5;
        TCheckBox *OrdInterrupt;
	TCheckBox *OrdUnk9;
	TCheckBox *OrdUnk10;
	TCheckBox *OrdUnk11;
	TCheckBox *OrdUnk12;
	TCheckBox *OrdUnk7;
        TCheckBox *OrdQueue;
	TCheckBox *OrdUnk3;
	TCheckBox *OrdUnk4;
	TGroupBox *UnitAdvProp;
        TCheckBox *UnitAdvBuilding;
	TCheckBox *UnitAdvAddon;
        TCheckBox *UnitAdvFlyer;
	TCheckBox *UnitAdvWorker;
        TCheckBox *UnitAdvRegenerate;
	TCheckBox *UnitAdvHero;
	TCheckBox *UnitAdvFlyBuilding;
        TCheckBox *UnitAdvSubunit;
        TCheckBox *UnitAdvDetector;
        TCheckBox *UnitAdvRobotic;
        TCheckBox *UnitAdvResContainer;
        TCheckBox *UnitAdvResDepot;
        TCheckBox *UnitAdvSingleEntity;
	TCheckBox *UnitAdvTwoInEgg;
	TCheckBox *UnitAdvCloak;
	TCheckBox *UnitAdvAnimIdle;
        TCheckBox *UnitAdvReqPsi;
	TCheckBox *UnitAdvUnused;
        TCheckBox *UnitAdvReqCreep;
        TCheckBox *UnitAdvOrganic;
	TCheckBox *UnitAdvPickup;
	TCheckBox *UnitAdvPermaCloak;
	TCheckBox *UnitAdvSpellcaster;
	TCheckBox *UnitAdvBurrow;
        TCheckBox *UnitAdvIgnoreSupply;
	TCheckBox *UnitAdvOverlayMed;
	TCheckBox *UnitAdvOverlayLarge;
        TCheckBox *UnitAdvBattleReactions;
        TCheckBox *UnitAdvAutoAttack;
        TCheckBox *UnitAdvInvincible;
        TCheckBox *UnitAdvMechanical;
        TCheckBox *UnitAdvProducesUnits;
	TGroupBox *UnitSounds;
	TGroupBox *UnitAIActions;
	TComboBox *UnitAICompIdle;
	TComboBox *UnitAIHumanIdle;
	TComboBox *UnitAIRightClick;
	TLabel *LabelUnitAICompIdle;
	TLabel *LabelUnitAIHumanIdle;
	TLabel *LabelUnitAIAttackUnit;
	TLabel *LabelUnitAIAttackMove;
	TLabel *LabelUnitAIReturn;
	TLabel *LabelUnitAIRightClick;
	TGroupBox *UnitSEFlags;
	TGroupBox *UnitSEGroupFlags;
	TGroupBox *UnitSpriteProp;
        TComboBox *UnitGfxList;
	TLabel *LabelUnitGfx;
        TLabel *LabelUnitConstruction;
        TComboBox *UnitConstructionList;
	TGroupBox *UnitSEStringProp;
        TCheckBox *UnitSENonNeutral;
        TCheckBox *UnitSEUnitHero;
        TCheckBox *UnitSEListing;
	TCheckBox *UnitSEBriefing;
        TCheckBox *UnitSEPlayerSet;
	TCheckBox *UnitSEAllRaces;
        TCheckBox *UnitSEDoodadState;
        TCheckBox *UnitSENonLoc;
	TCheckBox *UnitSEGroupMen;
	TCheckBox *UnitSEGroupNeutral;
	TCheckBox *UnitSEGroupInd;
	TCheckBox *UnitSEGroupFactory;
	TCheckBox *UnitSEGroupBuilding;
	TCheckBox *UnitSEBW;
        TCheckBox *UnitSELoc;
	TLabel *LabelUnitSublabel;
	TLabel *LabelUnitMapString;
	TEdit *UnitSndReady;
	TLabel *LabelUnitSndReady;
        TEdit *UnitSndYesStart;
	TLabel *LabelUnitSndYesStart;
	TLabel *LabelUnitSndYesEnd;
	TLabel *LabelUnitSndWhatStart;
	TLabel *LabelUnitSndWhatEnd;
        TEdit *UnitSndYesEnd;
	TLabel *LabelUnitSndAnnStart;
	TLabel *LabelUnitSndAnnEnd;
        TComboBox *UnitPortraitList;
        TLabel *LabelUnitPortrait;
        TLabel *LabelUnitElevationLevel;
        TComboBox *UnitElevationLevelList;
	TComboBox *UnitAIReturn;
	TComboBox *UnitAIAttackUnit;
	TComboBox *UnitAIAttackMove;
	TEdit *UnitSndWhatStart;
	TGroupBox *UnitSEPlaceBox;
	TEdit *UnitSEPlaceHeight;
	TLabel *LabelUnitSEPlaceHeight;
	TEdit *UnitSEPlaceWidth;
	TLabel *LabelUnitSEPlaceWidth;
        TGroupBox *UnitAddonPos;
        TLabel *LabelUnitAddPosX;
        TLabel *LabelUnitAddPosY;
        TEdit *UnitAddPosX;
        TEdit *UnitAddPosY;
        TEdit *UnitDirection;
        TLabel *LabelUnitDirection;
        TEdit *UnitAIInternal;
        TLabel *LabelUnitAIInternal;
        TOpenDialog *OpenDialog;
        TSaveDialog *FileSaveDialog;
        TAction *SaveAs;
        TPanel *EditorsPanel;
        TGroupBox *InfoBox;
        TMemo *InfoText;
        TStatusBar *StatusBar;
        TLabel *LabelUsed;
        TGroupBox *WeapDisplay;
        TLabel *LabelWeapLabel;
        TLabel *LabelWeapError;
        TComboBox *WeapLabel;
        TComboBox *WeapError;
        TAction *OpenDir;
        TSaveDialog *ExportSaveDialog;
        TAction *FileExport;
        TAction *Copy;
        TAction *Paste;
        TEdit *UnitSupProv;
        TEdit *UnitScoreBuild;
        TEdit *UnitSpaceReq;
        TEdit *UnitSpaceProv;
        TGroupBox *SoundFileProp;
        TLabel *LabelSoundFile;
        TEdit *SoundFile;
        TLabel *LabelSoundDir;
        TAction *CopyTab;
        TAction *PasteTab;
        TEdit *UnitRank;
        TLabel *LabelUnitSublabel2;
        TListBox *UsedList;
        TButton *WeapDamageUpgradeJump;
        TGroupBox *UnitVitals;
        TLabel *LabelUnitArmorUpgrade;
        TLabel *LabelUnitHP;
        TLabel *LabelUnitSP;
        TLabel *LabelUnitArmor;
        TCheckBox *UnitShieldEnable;
        TButton *UnitPortraitJump;
        TButton *UnitConstructionJump;
        TButton *UnitGfxJump;
        TPanel *TechIconPrevBox;
        TPanel *TechIconPrevBG;
        TPanel *UpgIconPrevBox;
        TLabel *LabelWeapIcon;
        TPanel *WeapIconPrevBox;
        TPanel *WeapIconPrevBG;
        TComboBox *WeapIconList;
        TGroupBox *UnitCost;
        TCheckBox *UnitIsBW;
        TLabel *LabelUnitTime;
        TLabel *LabelUnitVespene;
        TLabel *LabelUnitMinerals;
        TEdit *UnitMinerals;
        TEdit *UnitVespene;
        TEdit *UnitTime;
        TAction *PasteMixed;
        TAction *LoadHistoryItem;
        TPanel *UpgIconPrevBG;
        TImage *TechIconPrev;
        TImage *UpgIconPrev;
        TImage *WeapIconPrev;
        TAction *ReadConfig;
        TAction *SaveConfig;
        TAction *ClearHistory;
        TAction *ReadConfigOptions;
        TAction *SaveConfigOptions;
        TLabel *LabelPortEq;
        TGroupBox *PortGenProp;
        TAction *SetSorting;
        TGroupBox *ImgFile;
        TComboBox *SpriteImageList;
        TLabel *LabelSpriteDir;
        TComboBox *FlingySpriteList;
        TLabel *LabelFlingyDir;
        TEdit *UnitMapString;
        TAction *LoadHint;
        TAction *SearchList;
        TGroupBox *UnitSpace;
        TGroupBox *UnitSupply;
        TGroupBox *UnitScore;
        TEdit *UnitScoreDestroy;
        TAction *ReloadDefault;
        TEdit *PortUnk1;
        TButton *UnitSndReadyJump;
        TButton *UnitSndYesStartJump;
        TButton *UnitSndYesEndJump;
        TButton *UnitSndWhatStartJump;
        TButton *UnitSndWhatEndJump;
        TButton *UnitSndAnnStartJump;
        TButton *UnitSndAnnEndJump;
        TEdit *WeapOffsetForward;
        TEdit *WeapOffsetUpward;
        TButton *UnitAICompIdleJump;
        TButton *UnitAIHumanIdleJump;
        TButton *UnitAIReturnJump;
        TButton *UnitAIAttackUnitJump;
        TButton *UnitAIAttackMoveJump;
        TCheckBox *UnitSEGroupProtoss;
        TCheckBox *UnitSEGroupTerran;
        TCheckBox *UnitSEGroupZerg;
        TCheckBox *UnitSupReq05;
        TCheckBox *UnitSupProv05;
        TEdit *FlingyAcceleration;
        TEdit *FlingyHaltDist;
        TEdit *FlingyTurnRad;
        TComboBox *FlingyMoveControl;
        TGroupBox *UnitDims;
        TLabel *LabelUnitDimLeft;
        TLabel *LabelUnitDimRight;
        TLabel *LabelUnitDimUp;
        TLabel *LabelUnitDimDown;
        TEdit *UnitDimLeft;
        TEdit *UnitDimRight;
        TEdit *UnitDimUp;
        TEdit *UnitDimDown;
        TGroupBox *UnitVariousProperties;
        TCheckBox *UnitMov01;
        TCheckBox *UnitMov02;
        TCheckBox *UnitMov08;
        TCheckBox *UnitMov04;
        TCheckBox *UnitMov20;
        TCheckBox *UnitMov10;
        TCheckBox *UnitMov80;
        TCheckBox *UnitMov40;
        TShape *SizeRect;
        TComboBox *MapFileList;
        TComboBox *PortFileList;
        TComboBox *SoundFileList;
        TComboBox *UnitSndReadyList;
        TComboBox *UnitSndYesStartList;
        TComboBox *UnitSndYesEndList;
        TComboBox *UnitSndWhatStartList;
        TComboBox *UnitSndWhatEndList;
        TComboBox *UnitSndAnnStartList;
        TLabel *LabelEqUnits6;
        TLabel *LabelEqUnits5;
        TLabel *LabelEqUnits4;
        TLabel *LabelEqUnits3;
        TLabel *LabelEqUnits2;
        TLabel *LabelEqUnits1;
        TEdit *UnitSndWhatEnd;
        TEdit *UnitSndAnnStart;
        TEdit *UnitSndAnnEnd;
        TComboBox *UnitSndAnnEndList;
        TLabel *LabelEqUnits7;
        TAction *ClearAllBookmarks;
        TAction *BookmarkClick;
        TAction *BookmarkEntry;
        TPopupMenu *PopupMenu;
        TMenuItem *QuickBM;
        TMenuItem *N8;
        TMenuItem *CopyEntry1;
        TMenuItem *PasteEntry1;
        TMenuItem *Bookmarkentry1;
        TAction *ClearBookmarks;
        TComboBox *WeapUnused;
        TMenuItem *N13;
        TMenuItem *ReloadEntry1;
        TAction *ReloadEntry;
        TMainMenu *MainMenu;
        TMenuItem *FileMenu;
        TMenuItem *OpenFile;
        TMenuItem *OpenDirectory;
        TMenuItem *MRUD;
        TMenuItem *N10;
        TMenuItem *OptionsMenu;
        TMenuItem *LoadDefault;
        TMenuItem *N1;
        TMenuItem *FileSave;
        TMenuItem *FileSaveAs;
        TMenuItem *N2;
        TMenuItem *Exit1;
        TMenuItem *EditMenu;
        TMenuItem *Copy1;
        TMenuItem *Paste1;
        TMenuItem *N5;
        TMenuItem *CopyTab1;
        TMenuItem *PasteTab1;
        TMenuItem *N6;
        TMenuItem *PasteMixed1;
        TMenuItem *ViewMenu;
        TMenuItem *SortbyData;
        TMenuItem *SortbyOrigin;
        TMenuItem *N7;
        TMenuItem *SortbyID;
        TMenuItem *Bookmarks;
        TMenuItem *N9;
        TMenuItem *ClearCurrentBookmarks1;
        TMenuItem *N12;
        TMenuItem *ClearBookmarks1;
        TMenuItem *AboutMenu;
        TMenuItem *DoodadsInfo1;
        TMenuItem *N3;
        TMenuItem *Credits;
        TMenuItem *AboutDatEdit;
        TMenuItem *N14;
        TLabel *LabelUnitUnk1;
        TEdit *UnitUnk1;
        TEdit *FlingyUnused;
        TLabel *LabelFlingyUnused;
        TEdit *UnitWeaponGround;
        TEdit *UnitWeaponAir;
        TEdit *UnitGroundMax;
        TEdit *UnitAirMax;
        TLabel *LabelEqUnits8;
        TLabel *LabelEqUnits9;
        TEdit *WeapGraphics;
        TLabel *LabelEqWeapons1;
        TLabel *LabelEqWeapons2;
        TEdit *WeapIcon;
        TEdit *UpgIcon;
        TLabel *LabelEqUpg1;
        TEdit *UpgLabel;
        TLabel *LabelEqUpg2;
        TLabel *LabelTechEq1;
        TLabel *LabelTechEq2;
        TEdit *TechLabel;
        TEdit *TechIcon;
        TComboBox *UnitRankList;
        TAction *ImgReference;
        TGroupBox *OrdProp;
        TLabel *LabelOrdLabel;
        TLabel *LabelOrdObscured;
        TLabel *LabelOrdAnimation;
        TComboBox *OrdLabel;
        TComboBox *OrdObscured;
        TComboBox *OrdAnimation;
        TLabel *LabelOrdTargeting;
        TComboBox *OrdTargeting;
        TLabel *LabelOrdEnergy;
        TComboBox *OrdEnergy;
        TButton *OrdEnergyJump;
        TButton *OrdTargetingJump;
        TLabel *LabelOrdHighlight;
        TEdit *OrdHighlight;
        TLabel *OrdEq1;
        TComboBox *OrdHighlightList;
        TPanel *OrdHighlistPrevBox;
        TPanel *OrdHighlightBG;
        TImage *OrdHighlightPrev;
        TLabel *LabelOrdUnk13;
        TEdit *OrdUnk13;
        TCheckBox *UnitSE0x0400;
        TCheckBox *UnitSE0x0800;
        TCheckBox *UnitSE0x1000;
        TCheckBox *UnitSE0x2000;
        TCheckBox *UnitSE0x4000;
        TCheckBox *UnitSE0x8000;
        TEdit *UnitTimeSec;
        TLabel *LabelEqUnits10;
        TLabel *LabelSecUnits;
        TImage *SizeGRPPrev;
        TShape *SizeRefPoint;
        TUpDown *UnitTimeSecUpDown;
        TLabel *LabelEqUpg3;
        TEdit *UpgTimeSec;
        TUpDown *UpgTimeSecUpDown;
        TLabel *LabelSecUpg;
        TLabel *LabelEqUpg4;
        TEdit *UpgFactorTimeSec;
        TUpDown *UpgFactorTimeSecUpDown;
        TLabel *LabelSecUpg2;
        TLabel *LabelEqTech3;
        TEdit *TechTimeSec;
        TUpDown *TechTimeSecUpDown;
        TLabel *LabelSecTech;
        TPanel *UnitDimView;
        TImage *CirclePrev;
        TLabel *LabelSizePreview;
        TEdit *UnitGfx;
        TLabel *LabelEqUnits12;
        TLabel *LabelEqUnits13;
        TEdit *UnitConstruction;
        TLabel *LabelEqUnits15;
        TEdit *UnitPortrait;
        TEdit *UnitElevationLevel;
        TLabel *LabelEqUnits16;
        TPanel *SearchPanel;
        TButton *SearchButton;
        TComboBox *SearchText;
        TLabel *JumpToIDLabel;
        TEdit *JumpToID;
        TMenuItem *SortbyProperty;
        TAction *PropertySort;
        TSplitter *Splitter;
        TMenuItem *FileCompareMerge;
        TMenuItem *N4;
        TImageList *BookmarkImage;
        TAction *ReadBookmarks;
        TEdit *UnitHP;
        TEdit *UnitSP;
        TEdit *UnitArmor;
        TComboBox *UnitArmorUpgrade;
        TEdit *WeapRemoveAfter;
        TButton *WeapGraphicsJump;
        TLabel *LabelImgOL1;
        TEdit *ImgOL1;
        TLabel *LabelEqImg3;
        TComboBox *ImgOL1List;
        TLabel *LabelImgOL2;
        TEdit *ImgOL2;
        TLabel *LabelImgOL3;
        TEdit *ImgOL3;
        TLabel *LabelImgOL4;
        TEdit *ImgOL4;
        TEdit *ImgOL5;
        TLabel *LabelImgOL5;
        TLabel *LabelShieldOL;
        TEdit *ImgShield;
        TComboBox *ImgShieldOL;
        TLabel *LabelEqImg8;
        TLabel *LabelEqImg7;
        TLabel *LabelEqImg6;
        TLabel *LabelEqImg5;
        TLabel *LabelEqImg4;
        TComboBox *ImgOL2List;
        TComboBox *ImgOL3List;
        TComboBox *ImgOL4List;
        TComboBox *ImgOL5List;
        TComboBox *ImgShieldList;
        TCheckBox *ImgDrawCloaked;
        TCheckBox *ImgGfxTurns;
        TCheckBox *ImgClickable;
        TCheckBox *ImgUseFullIscript;
        TLabel *LabelImgDrawFunction;
        TLabel *LabelImgRemap;
        TEdit *ImgRemap;
        TEdit *ImgDrawFunction;
        TLabel *LabelEqImg9;
        TLabel *LabelEqImg10;
        TComboBox *ImgRemapList;
        TComboBox *ImgDrawFunctionList;
        TEdit *ImgIscriptID;
        TEdit *ImgGRP;
        TLabel *LabelImgGRP;
        TLabel *LabelImgIscriptID;
        TLabel *LabelEqImg2;
        TLabel *LabelEqImg1;
        TComboBox *ImgGRPList;
        TComboBox *ImgIscriptIDList;
        TButton *ImgIscriptRef;
        TButton *ImgGRPRef;
        TMenuItem *FileExportButton;
        TMenuItem *FAQMenu;
        TAction *FAQClick;
        TAction *LoadFAQ;
        TGroupBox *UnitOther;
        TLabel *LabelUnitSize;
        TLabel *LabelUnitSight;
        TLabel *LabelUnitTAR;
        TComboBox *UnitSize;
        TEdit *UnitSight;
        TEdit *UnitTAR;
        TTabControl *InfoTab;
        TSplitter *InfoboxSplitter;
        TLabel *LabelUnitSub1;
        TComboBox *UnitSub1;
        TComboBox *UnitSub2;
        TLabel *LabelUnitSub2;
        TLabel *LabelUnitInfestation;
        TEdit *UnitInfestation;
        TLabel *LabelEqUnits14;
        TComboBox *UnitInfestationList;
        TButton *UnitInfestationJump;
        TMenuItem *ExternalProgMenu;
        TAction *ExternalProgramsChange;
        TAction *LoadExternalProgram;
        TMenuItem *Erasebookmark1;
        TAction *BookmarkErase;
        TPanel *CircleView;
        TEdit *SpriteCircleOff;
        TLabel *LabelSpriteCircleOff;
        TLabel *Label1;
        TEdit *SpriteHPBarbox;
        TUpDown *SpriteHPBarboxUpDown;
        TLabel *LabelSpriteSelCircle;
        TEdit *SpriteSelCircle;
        TLabel *LabelCircleDir;
        TComboBox *SpriteSelCircleList;
        TButton *SpriteSelCircleJump;
        TEdit *SpriteHPBar;
        TLabel *LabelSpriteHPBar;
        TLabel *LabelSpritePrev;
        TLabel *Label2;
        TButton *JumpToIDButton;
        TPanel *HPBarPrevPanel;
        TImage *CircleUnitPrev;
        TPaintBox *HPBarPrev;
        TAction *ReadLabels;
        TMenuItem *ClipPaste;
        TMenuItem *N11;
        TMenuItem *ClipCopy;
        TMenuItem *ClipCopy2;
        TMenuItem *ClipPaste2;
        TMenuItem *N15;
        TButton *OrdHighlightClear;

	void __fastcall AboutClick(TObject *Sender);
	void __fastcall OpenExecute(TObject *Sender);
	void __fastcall OpenDialogCanClose(TObject *Sender,
	  bool &CanClose);
	void __fastcall SaveExecute(TObject *Sender);
	void __fastcall JumpToIDKeyDown(TObject *Sender, WORD &Key,
	  TShiftState Shift);
	void __fastcall ChangeTabExecute(TObject *Sender);
	void __fastcall WeapEditShow(TObject *Sender);
	void __fastcall FlingyEditShow(TObject *Sender);
	void __fastcall SpriteEditShow(TObject *Sender);
	void __fastcall ImageEditShow(TObject *Sender);
	void __fastcall UpgradeEditShow(TObject *Sender);
	void __fastcall TechEditShow(TObject *Sender);
	void __fastcall MapEditShow(TObject *Sender);
	void __fastcall OrderEditShow(TObject *Sender);
        void __fastcall ChangeDataBoxExecute(TObject *Sender);
	void __fastcall ExitEditExecute(TObject *Sender);
	void __fastcall JumpToDATExecute(TObject *Sender);
        void __fastcall CreditsClick(TObject *Sender);
        void __fastcall SaveAsExecute(TObject *Sender);
        void __fastcall FileSaveDialogCanClose(TObject *Sender,
          bool &CanClose);
        void __fastcall FormCreate(TObject *Sender);
        void __fastcall FormCloseQuery(TObject *Sender, bool &CanClose);
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
        void __fastcall UsedListDblClick(TObject *Sender);
        void __fastcall OpenDirExecute(TObject *Sender);
        void __fastcall ExportSaveDialogCanClose(TObject *Sender, bool &CanClose);
        void __fastcall FileExportExecute(TObject *Sender);
        void __fastcall EditMenuClick(TObject *Sender);
        void __fastcall CopyExecute(TObject *Sender);
        void __fastcall PasteExecute(TObject *Sender);
        void __fastcall DoodadsInfo1Click(TObject *Sender);
        void __fastcall SoundEditShow(TObject *Sender);
        void __fastcall ListChange(TObject *Sender, TTreeNode *Node);
        void __fastcall CopyTabExecute(TObject *Sender);
        void __fastcall PasteTabExecute(TObject *Sender);
        void __fastcall PasteMixedExecute(TObject *Sender);
        void __fastcall FileMenuClick(TObject *Sender);
        void __fastcall LoadHistoryItemExecute(TObject *Sender);
        void __fastcall UnitTabsChange(TObject *Sender);
        void __fastcall UnitBasicShow(TObject *Sender);
        void __fastcall UnitGraphicsShow(TObject *Sender);
        void __fastcall UnitSEShow(TObject *Sender);
        void __fastcall UnitAIShow(TObject *Sender);
        void __fastcall ReadConfigExecute(TObject *Sender);
        void __fastcall SaveConfigExecute(TObject *Sender);
        void __fastcall OptionsMenuClick(TObject *Sender);
        void __fastcall ClearHistoryExecute(TObject *Sender);
        void __fastcall ReadConfigOptionsExecute(TObject *Sender);
        void __fastcall SaveConfigOptionsExecute(TObject *Sender);
        void __fastcall ViewMenuClick(TObject *Sender);
        void __fastcall SetSortingExecute(TObject *Sender);
        void __fastcall PortEditShow(TObject *Sender);
        void __fastcall LoadHintExecute(TObject *Sender);
        void __fastcall SearchTextKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
        void __fastcall SearchListExecute(TObject *Sender);
        void __fastcall ReloadDefaultExecute(TObject *Sender);
        void __fastcall UnitAdvShow(TObject *Sender);
        void __fastcall UnitSoundShow(TObject *Sender);
        void __fastcall ClearAllBookmarksExecute(TObject *Sender);
        void __fastcall BookmarkClickExecute(TObject *Sender);
        void __fastcall BookmarkEntryExecute(TObject *Sender);
        void __fastcall PopupMenuPopup(TObject *Sender);
        void __fastcall ClearBookmarksExecute(TObject *Sender);
        void __fastcall ReloadEntryExecute(TObject *Sender);
        void __fastcall ImgReferenceExecute(TObject *Sender);
        void __fastcall FormShow(TObject *Sender);
        void __fastcall UnitTimeSecUpDownChangingEx(TObject *Sender,
          bool &AllowChange, short NewValue, TUpDownDirection Direction);
        void __fastcall SearchButtonClick(TObject *Sender);
        void __fastcall PropertySortExecute(TObject *Sender);
        void __fastcall FileCompareMergeClick(TObject *Sender);
        void __fastcall ReadBookmarksExecute(TObject *Sender);
        void __fastcall FAQClickExecute(TObject *Sender);
        void __fastcall LoadFAQExecute(TObject *Sender);
        void __fastcall ListKeyPress(TObject *Sender, char &Key);
        void __fastcall InfoboxSplitterMoved(TObject *Sender);
        void __fastcall ExternalProgramsChangeExecute(TObject *Sender);
        void __fastcall LoadExternalProgramExecute(TObject *Sender);
        void __fastcall BookmarkEraseExecute(TObject *Sender);
        void __fastcall JumpToIDButtonClick(TObject *Sender);
        void __fastcall SpriteHPBarboxUpDownClick(TObject *Sender,
          TUDBtnType Button);
        void __fastcall HPBarPrevPaint(TObject *Sender);
        void __fastcall ReadLabelsExecute(TObject *Sender);
        void __fastcall ClipCopyClick(TObject *Sender);
        void __fastcall ClipPasteClick(TObject *Sender);
        void __fastcall OrdHighlightClearClick(TObject *Sender);
//---------------------------------------------------------------------------
private:
        unsigned int ClipFormat;
        int Page, SubPage;
        int *TabSortingStyle;
        bool IconExport,IconIsMPQImport,IsSC,SEExport;
        bool *ListReload,*EditorReload;
        bool *TempTabs,*TempDats,*DatExport,*TBLExport,*TBLIsMPQImport;

        String ProgPath,SCPath;
        String Ver,LastFolder,MPQName;
        TStringList *DATEntryNames[11],*DATFormat[11];
        TTreeView *DATEntryList[11];
        FileData DATFile[11];

        void **SCMPQHandles,*MPQHandle,*GRPMPQHandle;
        void __fastcall WmDropFiles(TWMDropFiles& Message);
//---------------------------------------------------------------------------
public:
        CustomFile Icons,MpqIcons,TBLs[5],MpqTBLs[5];
        ProgramOptions Options;
        TStringList *Hints,*Origins,*FAQ,*ExternalPrograms;
//---------------------------------------------------------------------------
        __fastcall TForm1(TComponent* Owner);
        void InitializeValues();
        void AddHistoryItem(String ItemName);
        

        void SetVer(String Version);
        String GetVer ();

        void SetDatExport(int Index, bool Value);
        bool GetDatExport(int Index);

        void SetIsSC (bool Value);
        bool GetIsSC();

        void SetSEExport (bool Value);
        bool GetSEExport();

        void SetPage(int PageIndex);
        int GetPage();

        void SetSubPage(int SubPageIndex);
        int GetSubPage();

        bool GetTempDats(int PageIndex);
        void SetTempDats(int PageIndex, bool Value);

        bool GetTempTabs(int PageIndex);
        void SetTempTabs(int Index, bool Value);

        int GetSortingStyle(int PageIndex);
        void SetSortingStyle(int PageIndex, int Value);

        bool GetListReload(int PageIndex);
        void SetListReload(int PageIndex, bool Value);

        bool GetEditorReload(int PageIndex);
        void SetEditorReload(int PageInsex, bool Value);

        void SetTBLExport(int Index,bool Value);
        bool GetTBLExport(int Index);

        void SetIconExport(bool MPQIconsState);
        bool GetIconExport();
        
        void SetLastFolder(String Folder);
        String GetLastFolder();

        void SetMPQName(String MPQName);
        String GetMPQName();

        void SetProgPath(String ProgPath);
        String GetProgPath();

        void SetSCPath(String SCPath);
        String GetSCPath();

        void SetTBLIsMPQImport(int Index,bool Value);
        bool GetTBLIsMPQImport(int Index);

        void SetIconIsMPQImport(bool Value);
        bool GetIconIsMPQImport();

        void SetSCMPQHandles(int HandleID, void* Handle);
        void* GetSCMPQHandles(int HandleID);

        void SetMPQHandle(void* Handle);
        void* GetMPQHandle();

        void SetGRPMPQHandle(void* Handle);
        void* GetGRPMPQHandle();

        TStringList* GetDATEntryNames(int Index);
        TStringList* GetDATFormat(int Index);
        TTreeView* GetDATEntryList(int Index);
        FileData* GetDATFile(int Index);

        BEGIN_MESSAGE_MAP
           MESSAGE_HANDLER(WM_DROPFILES, TWMDropFiles, WmDropFiles)
        END_MESSAGE_MAP(TForm)
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
