//---------------------------------------------------------------------------
#pragma hdrstop
#include "Data.h"
#include "EntryData.h"
#include "LoadList.h"
#include "TBLParser.h"
#include "Options.h"
#include "ProgressForm.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
//------------------------------------------------------------------------------
/*
############################################################################
This routine handles various actions related to, and including, loading
a DAT file to a FileData-type structure.
############################################################################
*/
void CheckDATFile (String FileName) {
     if (FileExists(FileName)) {
        if (FileName.Pos('/') != 0) {
           for (int i=1;i<FileName.Length();i++) {
              if (FileName[i] == '/') {
                 FileName[i] = '\\';
              }
           }
        }
        TMemoryStream* WorkFile = new TMemoryStream();
        if (WorkFile != NULL) {
           WorkFile->LoadFromFile(FileName);
           for (int i=0;i<11;i++) {
               if (WorkFile->Size == Form1->GetDATFile(i)->GetFilesize()) {
                  Form1->GetDATFile(i)->SetDatName(FileName);
                  Form1->GetDATFile(i)->SetLoadState(true);
                  Form1->GetDATFile(i)->SetDefaultState(false);
                  if (ExtractFilePath(FileName) == Form1->GetProgPath()+"Default\\") {
                     Form1->GetDATFile(i)->SetDefaultState(true);
                  }
                  Form1->GetDATFile(i)->LoadData(WorkFile->Memory);
                  Form1->GetDATFile(i)->SetIsMPQImport(false);
                  Form1->Editors->ActivePageIndex=i;

                  //IN CASE THERE WAS AN MPQ-IMPORTED FILE PREVIOUSLY ASSOCIATED
                  //WITH THE EDITOR, REMOVE THE '=' TAGS FROM THE EDITOR'S TITLE 
                  if (Form1->Editors->Pages[i]->Caption.Pos("=") != 0) {
                     Form1->Editors->Pages[i]->Caption = Form1->Editors->Pages[i]->Caption.SubString(2,Form1->Editors->Pages[i]->Caption.Length()-2);
                  }
                  Form1->ChangeTab->Execute();
                  break;
               }
               else if (i==10){
                  MessageDlg(String("\""+FileName+"\" is not a valid DAT file that DatEdit can recognize."), mtError, TMsgDlgButtons() << mbOK, 0);
               }
           }
        }
        else {
           MessageDlg(String("\""+FileName+"\" cannot be opened."), mtError, TMsgDlgButtons() << mbOK, 0);
        }
        delete WorkFile;
    }
    else {
       MessageDlg("Target file does not exist!", mtError, TMsgDlgButtons() << mbOK, 0);
    }
};
//------------------------------------------------------------------------------
/*
############################################################################
This function opens a given MPQ file and checks if it contains
DatEdit-compatible content (first DAT files, and ONLY if these are
present:TBLs and icons). 
############################################################################
*/
bool CheckMPQFile (String MPQFileName) {
    bool FileWasFound=false;
    void *MpqHandle,*FileHandle;

    //Close a previously opened archive
    if (Form1->GetMPQHandle() != NULL) {
       SFileCloseArchive(Form1->GetMPQHandle());
    }

    //INITALIZE VARIABLES USED TO STORE IF FILES ARE FOUND
    bool DATs[11],TBLs[5],Icon;
    for (int i=0;i<11;i++) {
        if (i<5) {
           TBLs[i] = false;
        }
        DATs[i] = false;
    }
    Icon = false;
    Form1->SetMPQName("");

    if (SFileOpenArchive(MPQFileName.c_str(),1000,0,&MpqHandle)) {
    //FIRST PART:CHECK FOR DATEDIT-COMPATIBLE FILES
       int ExportCount=0;
       for (int i=0;i<5;i++) {
           if (i==0) {
              if (SFileOpenFileEx(MpqHandle,String("rez\\stat_txt.tbl").c_str(),NULL,&FileHandle)) {
                 TBLs[0] = true;
                 ExportCount++;
              }
           }
           else if (SFileOpenFileEx(MpqHandle,String("arr\\"+GetTBLType(i)+".tbl").c_str(),NULL,&FileHandle))  {
              TBLs[i] = true;
              ExportCount++;
           }
           SFileCloseFile(FileHandle);
       }
       if (SFileOpenFileEx(MpqHandle,String("unit\\cmdbtns\\cmdicons.grp").c_str(),NULL,&FileHandle)) {
          Icon = true;
          ExportCount++;
       }
       SFileCloseFile(FileHandle);
       for (int i=10;i>=0;i--) {
           DATs[i] = SFileOpenFileEx(MpqHandle,String("arr\\"+GetDATType(i)+".dat").c_str(),NULL,&FileHandle);
           SFileCloseFile(FileHandle);
           if (FileWasFound == false) {
              FileWasFound = DATs[i];
           }
           ExportCount++;
       }
       if (FileWasFound == true) {
       //SECOND PART: LOAD THE FOUND FILES TO THE MEMORY AND MARK
       //AS MPQ-IMPORTS
          void *FileBuffer;
          unsigned long BytesRead;
          int FileSize;

          ProgForm->Caption = "Importing Progress...";
          ProgForm->Show();

          String FoundInMPQ;
          Form1->SetMPQName(MPQFileName);

          for (int i=0;i<5;i++) {
              if (i == 0) {
                 if (TBLs[0] == true) {
                    if (SFileOpenFileEx(MpqHandle,String("rez\\stat_txt.tbl").c_str(),NULL,&FileHandle)) {
                       Form1->SetTBLIsMPQImport(0,true);
                       FileSize = SFileGetFileSize(FileHandle,NULL);
                       FileBuffer = new char [FileSize];
                       if (FileBuffer) {
                          if (SFileReadFile(FileHandle,FileBuffer,FileSize,&BytesRead,NULL)) {
                             Form1->MpqTBLs[0].LoadBuffer(FileBuffer,FileSize);
                             FoundInMPQ = FoundInMPQ+GetTBLType(0)+".tbl, ";

                             Form1->SetEditorReload(0,true);
                             Form1->SetEditorReload(1,true);
                             Form1->SetEditorReload(5,true);
                             Form1->SetEditorReload(6,true);
                             Form1->SetEditorReload(10,true);
                             ProgForm->ProgressBar->StepBy(50/ExportCount);
                          }
                       }
                    }
                 }
              }
              else {
                 if (TBLs[i] == true) {
                    if (SFileOpenFileEx(MpqHandle,String("arr\\"+GetTBLType(i)+".tbl").c_str(),NULL,&FileHandle)) {
                       Form1->SetTBLIsMPQImport(i,true);
                       FileSize = SFileGetFileSize(FileHandle,NULL);
                       FileBuffer = new char [FileSize];
                       if (FileBuffer) {
                          if (SFileReadFile(FileHandle,FileBuffer,FileSize,&BytesRead,NULL)) {
                             Form1->MpqTBLs[i].LoadBuffer(FileBuffer,FileSize);
                             FoundInMPQ = FoundInMPQ+GetTBLType(i)+".tbl, ";
                             switch (i) {
                                 case 1:
                                      Form1->SetEditorReload(4,true);
                                      break;
                                 case 2:
                                      Form1->SetEditorReload(8,true);
                                      break;
                                 case 3:
                                      Form1->SetEditorReload(7,true);
                                      break;
                                 case 4:
                                      Form1->SetEditorReload(9,true);
                                      break;
                             }
                             ProgForm->ProgressBar->StepBy(50/ExportCount);
                          }
                       }
                    }
                    SFileCloseFile(FileHandle);
                 }
              }
          }

          if (Icon == true) {
             if (SFileOpenFileEx(MpqHandle,String("unit\\cmdbtns\\cmdicons.grp").c_str(),NULL,&FileHandle)) {
                Form1->SetIconIsMPQImport(true);
                FileSize = SFileGetFileSize(FileHandle,NULL);
                FileBuffer = new char [FileSize];
                if (FileBuffer) {
                   if (SFileReadFile(FileHandle,FileBuffer,FileSize,&BytesRead,NULL)) {
                      Form1->MpqIcons.LoadBuffer(FileBuffer,FileSize);
                      FoundInMPQ = FoundInMPQ+"cmdicons.grp, ";
                      if (Form1->GetDATFile(1)->GetIsMPQImport() == true) {
                         Form1->SetEditorReload(1,true);
                      }
                      if (Form1->GetDATFile(5)->GetIsMPQImport() == true) {
                         Form1->SetEditorReload(5,true);
                      }
                      if (Form1->GetDATFile(6)->GetIsMPQImport() == true) {
                         Form1->SetEditorReload(6,true);
                      }
                      ProgForm->ProgressBar->StepBy(50/ExportCount);
                   }
                }
             }
             SFileCloseFile(FileHandle);
          }

          for (int i=10;i>=0;i--) {
              if (DATs[i] == true) {
                 if (SFileOpenFileEx(MpqHandle,String("arr\\"+GetDATType(i)+".dat").c_str(),NULL,&FileHandle)) {
                    Form1->GetDATFile(i)->SetIsMPQImport(true);
                    FileSize = SFileGetFileSize(FileHandle,NULL);
                    FileBuffer = new char [FileSize];
                    if (FileBuffer) {
                       if (SFileReadFile(FileHandle,FileBuffer,FileSize,&BytesRead,NULL)) {
                          if (FileSize == Form1->GetDATFile(i)->GetFilesize()) {
                             Form1->GetDATFile(i)->LoadData(FileBuffer);
                             Form1->GetDATFile(i)->SetDatName(String("#"+GetDATType(i)+".dat imported from: "+Form1->GetMPQName()+"#"));
                             FoundInMPQ = FoundInMPQ+GetDATType(i)+".dat, ";

                             Form1->Editors->Pages[i]->TabVisible = true;
                             Form1->Editors->Pages[i]->Enabled = true;
                             Form1->Editors->Pages[i]->Caption = "="+Form1->Editors->Pages[i]->Caption+"=";
                             ProgForm->ProgressBar->StepBy(50/ExportCount);
                          }
                          else {
                               MessageDlg(String("Tried to import "+GetDATType(i)+".dat from "+MPQFileName+",but the size of the file was incorrect."), mtError, TMsgDlgButtons() << mbOK, 0);
                          }
                       }
                    }
                 }
                 SFileCloseFile(FileHandle);
              }
          }                  
          if (Form1->Options.LoadGRPFromMPQ == false) {
             SFileCloseArchive(MpqHandle);
             Form1->SetMPQHandle(NULL);
          }
          else if (Form1->Options.LoadGRPFromMPQ == true) {
             Form1->SetMPQHandle(MpqHandle);
          }
          ProgForm->Hide();
          FoundInMPQ = FoundInMPQ.SubString(0,FoundInMPQ.Length()-2);
          MessageDlg(String("Imported the following files from "+MPQFileName+":\n"+FoundInMPQ), mtInformation, TMsgDlgButtons() << mbOK, 0);
       }
       else if (FileWasFound == false) {
          MessageDlg(String(MPQFileName+" does not contain any DAT files!"), mtError, TMsgDlgButtons() << mbOK, 0);
       }
    }
    else {
       SFileCloseArchive(MpqHandle);
       return 0;
    }
    Form1->ChangeTab->Execute();
    return 1;
};
//------------------------------------------------------------------------------
/*
############################################################################
This function exports a given file (DAT,TBL,or cmdicons.grp) or -if the
Size paramenter is non-zero- a data buffer into a given MPQ archive.
############################################################################
*/
void ExportToMpq (String MpqName,String FileName,void *Buffer,int Size) {
     void *MpqHandle;
     String MPQFileType = ExtractFileName(FileName).SubString(0,FileName.Pos("."));
     int OpenParam,AddParam;

     if (FileExists(MpqName)) {
          OpenParam = 0x5;
          AddParam = 0x00000201;
     }
     else if (!FileExists(MpqName)) {
          OpenParam = 0x1;
          AddParam = 0x00000200;
     }
     MpqHandle = MpqOpenArchiveForUpdate(MpqName.c_str(),OpenParam,1024);

//EXPORT THE DATA BUFFER TO THE MPQ ARCHIVE,ACCORDING TO THE FILENAME
     if (Size > 0) {
        if (FileName.Pos(".dat") != 0) {
           MpqAddFileFromBuffer(MpqHandle, Buffer, Size, String("arr\\"+MPQFileType+"dat").c_str(),AddParam);
        }
        else if (FileName.Pos(".tbl") != 0) {
             if (FileName.Pos("txt") != 0) {
                MpqAddFileFromBuffer(MpqHandle, Buffer, Size,String("rez\\"+MPQFileType).c_str(),AddParam);
             }
             else {
                MpqAddFileFromBuffer(MpqHandle, Buffer, Size,String("arr\\"+MPQFileType).c_str(),AddParam);
             }
        }
        else if (FileName.Pos("cmdicons") != 0) {
             MpqAddFileFromBuffer(MpqHandle, Buffer, Size,String("unit\\cmdbtns\\"+MPQFileType+"grp").c_str(),AddParam);
        }
     }
//DO THE SAME AS ABOVE,BUT FOR A REAL FILE.
     else if (Size == 0) {
          if (FileName.Pos(".dat") != 0) {
             MpqAddFileToArchive(MpqHandle, FileName.c_str(),String("arr\\"+MPQFileType+"dat").c_str(), AddParam);
          }
          else if (FileName.Pos(".tbl") != 0) {
               if (FileName.Pos("txt") != 0) {
                  MpqAddFileToArchive(MpqHandle, FileName.c_str(),String("rez\\"+MPQFileType).c_str(), AddParam);
               }
               else {
                  MpqAddFileToArchive(MpqHandle, FileName.c_str(),String("arr\\"+MPQFileType).c_str(), AddParam);
               }
          }
          else if (FileName.Pos("cmdicons") != 0) {
               MpqAddFileToArchive(MpqHandle, FileName.c_str(),String("unit\\cmdbtns\\cmdicons.grp").c_str(), AddParam);
          }
     }
     MpqCompactArchive(MpqHandle);
     MpqCloseUpdatedArchive(MpqHandle,0);
};

//------------------------------------------------------------------------------
/*
############################################################################
This function returns a specific DAT file name.Very versatile and very
often used.
############################################################################
*/
String GetDATType (int PageIndex) {
     String DATType;
     switch (PageIndex) {
            case 0:
                 DATType = "units";
		 break;
	    case 1:
                 DATType = "weapons";
		 break;
	    case 2:
                 DATType = "flingy";
		 break;
	    case 3:
                 DATType = "sprites";
		 break;
	    case 4:
                 DATType = "images";
		 break;
	    case 5:
                 DATType = "upgrades";
		 break;
	    case 6:
                 DATType = "techdata";
		 break;
	    case 7:
                 DATType = "sfxdata";
		 break;
	    case 8:
                 DATType = "portdata";
		 break;
	    case 9:
                 DATType = "mapdata";
		 break;
	    case 10:
                 DATType = "orders";
		 break;
     }
     return DATType;
};
//------------------------------------------------------------------------------
/*
############################################################################
This function returns an array of offsets to various units.dat properties
in the "Data" array, specific to a particular subtab of the Units Editor.
Used with the "Copy Tab" feature.
############################################################################
*/

int *GetTabMemoryOffs (int Tab) {

     int BasicTabOffs[23] = {6,7,8,17,18,19,20,23,24,25,26,27,45,46,47,49,50,51,52,53,54,55,57};
     int AdvTabOffs[6] = {1,2,3,10,22,48};
     int SoundTabOffs[7] = {29,30,31,32,33,34,35};
     int GfxTabOffs[11] = {0,4,5,9,38,39,40,41,42,43,44};
     int SETabOffs[6] = {11,36,37,49,56,58};
     int AITabOffs[7] = {12,13,14,15,16,21,28};

     int *TabMemoryOffs=NULL;
     switch (Tab) {
            case 0:
                 TabMemoryOffs = BasicTabOffs;
                 break;
            case 1:
                 TabMemoryOffs = AdvTabOffs;
                 break;
            case 2:
                 TabMemoryOffs = SoundTabOffs;
                 break;
            case 3:
                 TabMemoryOffs = GfxTabOffs;
                 break;
            case 4:
                 TabMemoryOffs = SETabOffs;
                 break;
            case 5:
                 TabMemoryOffs = AITabOffs;
                 break;
     }
     return TabMemoryOffs;
};
//------------------------------------------------------------------------------
/*
############################################################################
This function return a name of the type of the DAT entries that are used
in a specific editor.Used for category names of the base nodes when
creating entry listings.
############################################################################
*/

String GetDataType (int PageIndex) {
    String DataType;
    switch (PageIndex) {
        case 0:
            DataType = "Units";
            break;
        case 1:
            DataType = "Weapons";
            break;
        case 5:
            DataType = "Upgrades";
            break;
        case 6:
            DataType = "Technologies";
            break;
    }
    return DataType;
};
//------------------------------------------------------------------------------
/*
############################################################################
This function returns the Race property for a particular entry from the
Weapons, Upgrades and Tech editors, to be used with the "Sort by Data" sorting
method.
############################################################################
*/

int GetSortData (int Index, int PageIndex) {
    int DataOrigin;
    int DataModulo;
    switch (PageIndex) {
           case 5:
                DataModulo = 9;
                break;
           case 6:
                DataModulo = 7;
                break;
    }
    DataOrigin = Form1->GetDATFile(PageIndex)->GetData()[Index*Form1->GetDATFile(PageIndex)->GetVarcount()+DataModulo];
    return DataOrigin;
};
//------------------------------------------------------------------------------
/*
############################################################################
This function return the Race/Supply value for a given units.dat entry,
for sorting purposes in the "Sort by Data" sorting method.
############################################################################
*/

int GetUnitsSortData (int Index) {
    int UnitsDataSort,UnitsDataSEGroup;
    UnitsDataSEGroup = Form1->GetDATFile(0)->GetData()[Index*Form1->GetDATFile(0)->GetVarcount()+49];
    UnitsDataSort = 3;
    if ((0x1&UnitsDataSEGroup) == 1) {
       UnitsDataSort = 0;
    }
    else if ((0x2&UnitsDataSEGroup)>>1 == 1) {
       UnitsDataSort = 1;
    }
    else if ((0x4&UnitsDataSEGroup)>>2 == 1) {
       UnitsDataSort = 2;
    }
    return UnitsDataSort;
};
//------------------------------------------------------------------------------
/*
############################################################################
This function returns a specific sorting value for a units.dat entry,
according to the given entry's DAT properties. This is the very core
of the "Sort by Data" sorting style. The 3 variables are DAT properties
that are AND-ed with the property masks used to determine the sorting
category for an entry. Consult EntryData.cpp for reference about those
particular property maskings.

Directory reference:
0-Ground Units
1-Air Units
2-Heroes
3-Buildings
4-Addons
5-Special Buildings
6-Special
7-Critters
8-Powerups
9-Resources
############################################################################
*/

int GetUnitsSortSubData (int Index) {
    int UnitsDataOrigin,UnitsDataAdv,UnitsDataSEGroup,UnitsDataSEAvail;
    UnitsDataSEGroup = Form1->GetDATFile(0)->GetData()[Index*Form1->GetDATFile(0)->GetVarcount()+49];
    UnitsDataAdv = Form1->GetDATFile(0)->GetData()[Index*Form1->GetDATFile(0)->GetVarcount()+22];
    UnitsDataSEAvail = Form1->GetDATFile(0)->GetData()[Index*Form1->GetDATFile(0)->GetVarcount()+58];

    UnitsDataOrigin = 6;
    if ((0x80&UnitsDataSEGroup)>>7 == 1) {
        if ((0x10&UnitsDataSEGroup)>>4 == 1) {
            UnitsDataOrigin = 5;
        }
        if ((0x800000&UnitsDataAdv)>>23 == 1 ||  (0x800&UnitsDataAdv)>>11 ==1) {
           UnitsDataOrigin = 8;
        }
        if ((0x2000&UnitsDataAdv)>>13 == 1) {
           UnitsDataOrigin = 9;
        }
        if ((0x8&UnitsDataSEGroup)>>3 == 1) {
           UnitsDataOrigin = 7;
        }
    }
    else if ((0x8&UnitsDataSEGroup)>>3 == 1) {
        UnitsDataOrigin = 0;
        if ((0x4&UnitsDataAdv)>>2 == 1) {
           UnitsDataOrigin = 1;
        }
        if ((0x40&UnitsDataAdv)>>6 == 1) {
           UnitsDataOrigin = 2;
        }
    }
    else if (0x1&UnitsDataAdv == 1 || (0x20&UnitsDataAdv)>>5 == 1 || (0x10&UnitsDataSEGroup)>>4 == 1 || (0x20&UnitsDataSEGroup)>>5 == 1) {
        UnitsDataOrigin = 5;
        if ((0x8&UnitsDataSEAvail)>>3 == 1) {
           UnitsDataOrigin = 3;
        }
        if ((0x2&UnitsDataAdv)>>1 == 1) {
           UnitsDataOrigin = 4;
        }
    }
    return UnitsDataOrigin;
};
//------------------------------------------------------------------------------
/*
############################################################################
This function returns a specific TBL file's name.It is used like this
only for my own convenience to easily iterate through the TBL names
and the indexing is completely arbitrary.
############################################################################
*/
String GetTBLType(int Index) {
String TBLType;
switch (Index) {
       case 0:
            TBLType = "stat_txt";
            break;
       case 1:
            TBLType = "images";
            break;
       case 2:
            TBLType = "portdata";
            break;
       case 3:
            TBLType = "sfxdata";
            break;
       case 4:
            TBLType = "mapdata";
            break;
}
return TBLType;
};
//------------------------------------------------------------------------------
/*
############################################################################
This routine returns the "Label" property for a given entry from the
Weapons,Upgrades or Tech Editor.It is used to load a proper entry's name
from a TBL file.
############################################################################
*/
int GetNameID (int DatType,int EntryID) {
int NameID=0;
switch (DatType) {
       case 1:
            NameID = Form1->GetDATFile(1)->GetData()[EntryID*Form1->GetDATFile(1)->GetVarcount()];
            break;
       case 5:
            NameID = Form1->GetDATFile(5)->GetData()[EntryID*Form1->GetDATFile(5)->GetVarcount()+8];
            break;
       case 6:
            NameID = Form1->GetDATFile(6)->GetData()[EntryID*Form1->GetDATFile(6)->GetVarcount()+6];
            break;
}
return NameID;
};
//------------------------------------------------------------------------------
/*
############################################################################
This routine simply returns the given value as unsigned, since only
positive values are used.
############################################################################
*/
unsigned int FixVarSize (int VarValue, int VarID, int PageIndex) {

int FixedVar=0;
if (Form1->GetDATFile(PageIndex)->GetVarSize(VarID) == 1) {
   FixedVar = (unsigned char) (VarValue);
}
else if (Form1->GetDATFile(PageIndex)->GetVarSize(VarID) == 2) {
   FixedVar = (unsigned short) (VarValue);
}
else if (Form1->GetDATFile(PageIndex)->GetVarSize(VarID) == 4) {
   FixedVar = (unsigned int) (VarValue);
}

return FixedVar;
};
//------------------------------------------------------------------------------
/*
############################################################################
This routine simply extracts a bookmark's index from its caption (it is
kept between the "[" and "]" characters.
############################################################################
*/

int GetBookmarkID (String BookmarkCaption) {
    return BookmarkCaption.SubString(2,BookmarkCaption.Pos("]")-BookmarkCaption.Pos("[")-1).ToInt();
}
