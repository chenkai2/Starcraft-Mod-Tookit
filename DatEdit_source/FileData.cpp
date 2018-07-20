//---------------------------------------------------------------------------
#pragma hdrstop
#include "FileData.h"
#include "Main.h"
#include "Data.h"
#include "EntryData.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
//------------------------------------------------------------------------------

FileData::FileData () {
      this->InputEntrycount = 0;
      this->OutputEntrycount = 0;
      this->Varcount = 0;
      this->Filesize = 0;
      this->DATTypeID = 0;
      this->DatName = "";
      this->IsLoaded = false;
      this->IsDefault = false;
      this->IsMPQImport = false;
      this->FormatLoaded = false;
      this->Data = NULL;
      this->VarOffset = NULL;
      this->VarSize = NULL;
      this->VarStart = NULL;
      this->VarEnd = NULL;
      this->VarArray = NULL;
      this->VarArrayIndex = NULL;
      this->TempEntry = NULL;
      this->TempTab = NULL;
      this->TempMix = NULL;
};

FileData::FileData (FileData &File) {
      this->InputEntrycount = File.InputEntrycount;
      this->OutputEntrycount = File.OutputEntrycount;
      this->Varcount = File.Varcount;
      this->Filesize = File.Filesize;
      this->DATTypeID = File.DATTypeID;
      this->DatName = File.DatName;
      this->IsLoaded = File.IsLoaded;
      this->IsDefault = File.IsDefault;
      this->IsMPQImport = File.IsMPQImport;
      this->FormatLoaded = File.FormatLoaded;
      this->Data = File.Data;
      this->VarOffset = File.VarOffset;
      this->VarSize = File.VarSize;
      this->VarArray = File.VarArray;
      this->VarArrayIndex = File.VarArrayIndex;
      this->TempEntry = File.TempEntry;
      this->TempTab = File.TempTab;
      this->TempMix = File.TempMix;
};
                 /*
FileData::~FileData () {
      if (this->Data != NULL) {
         delete[] this->Data;
      }
      if (this->VarOffset != NULL) {
         delete[] this->VarOffset;
      }
      if (this->VarStart != NULL) {
         delete[] this->VarStart;
      }
      if (this->VarEnd != NULL) {
         delete[] this->VarEnd;
      }
      if (this->VarSize != NULL) {
         delete[] this->VarSize;
      }
      if (this->VarArray != NULL) {
         delete[] this->VarArray;
      }
      if (this->VarArrayIndex != NULL) {
         delete[] this->VarArrayIndex;
      }
      if (this->TempEntry != NULL) {
         delete[] this->TempEntry;
      }
      if (this->TempTab != NULL) {
         delete[] this->TempTab;
      }
      if (this->TempMix != NULL) {
         delete[] this->TempMix;
      }
};                 */

FileData FileData::operator = (FileData *File) {
      this->InputEntrycount = File->InputEntrycount;
      this->OutputEntrycount = File->OutputEntrycount;
      this->Varcount = File->Varcount;
      this->Filesize = File->Filesize;
      this->DATTypeID = File->DATTypeID;
      this->DatName = File->DatName;
      this->IsLoaded = File->IsLoaded;
      this->IsDefault = File->IsDefault;
      this->IsMPQImport = File->IsMPQImport;
      this->FormatLoaded = File->FormatLoaded;
      this->Data = File->Data;
      this->VarOffset = File->VarOffset;
      this->VarSize = File->VarSize;
      this->VarArray = File->VarArray;
      this->VarArrayIndex = File->VarArrayIndex;
      this->TempEntry = File->TempEntry;
      this->TempTab = File->TempTab;
      this->TempMix = File->TempMix;
      return *this;
};
//------------------------------------------------------------------------------
/*
############################################################################
This routines returns various members of the FileData class, that serves
as the storage class for DAT files. They're fairly self-explanatory
from their name.
############################################################################
*/
bool FileData::GetLoadState() {
     return this->IsLoaded;
};

void FileData::SetLoadState (bool Value) {
     this->IsLoaded = Value;
};
//------------------------------------------------------------------------------
int* FileData::GetData () {
     return this->Data;
};

int FileData::GetVarSize (int VarID) {
    return this->VarSize[VarID];
}
//------------------------------------------------------------------------------
int FileData::GetInputEntrycount () {
    return this->InputEntrycount;
};

void FileData::SetInputEntrycount (int Value) {
     this->InputEntrycount = Value;
};

int FileData::GetOutputEntrycount () {
    return this->OutputEntrycount;
};

void FileData::SetOutputEntrycount (int Value) {
     this->OutputEntrycount = Value;
};
//------------------------------------------------------------------------------
int FileData::GetVarcount () {
    return this->Varcount;
};

void FileData::SetVarcount (int Value) {
     this->Varcount = Value;
};
//------------------------------------------------------------------------------

int FileData::GetFilesize () {
    return this->Filesize;
};
void FileData::SetFilesize (int Value) {
     this->Filesize = Value;
};
//------------------------------------------------------------------------------
int FileData::GetDATTypeID() {
    return this->DATTypeID;
};
void FileData::SetDATTypeID (int Value) {
     this->DATTypeID = Value;
};
//------------------------------------------------------------------------------
bool FileData::GetDefaultState () {
     return this->IsDefault;
};

void FileData::SetDefaultState (bool Value) {
     this->IsDefault = Value;
};
//------------------------------------------------------------------------------
bool FileData::GetIsMPQImport () {
     return this->IsMPQImport;
};

void FileData::SetIsMPQImport (bool Value) {
     this->IsMPQImport = Value;
};
//------------------------------------------------------------------------------
bool FileData::GetFormatLoaded () {
     return this->FormatLoaded;
};

void FileData::SetFormatLoaded (bool Value) {
     this->FormatLoaded = Value;
};
//------------------------------------------------------------------------------
String FileData::GetDatName () {
    return this->DatName;
};

void FileData::SetDatName (String FileName) {
     this->DatName = FileName;
};
//------------------------------------------------------------------------------

int FileData::GetOutputFilesize() {
     int Size=0;
     for (int i=0;i<this->Varcount;i++) {
         if (this->VarEnd[i] == this->InputEntrycount-1) {
            Size+=this->VarSize[i]*((this->OutputEntrycount-1)-this->VarStart[i]+1);
         }
         else {
            Size+=this->VarSize[i]*(this->VarEnd[i]-this->VarStart[i]+1);
         }
     }
     return Size;
};
//------------------------------------------------------------------------------
/*
############################################################################
This routine loads the hex format of a specific DAT file from the
a given format  file to the memory.
############################################################################
*/
void FileData::LoadFormat (TStringList *DATFormat) {

   this->InputEntrycount=StrToInt(DATFormat->Values["InputEntrycount"]);
   this->OutputEntrycount=StrToInt(DATFormat->Values["OutputEntrycount"]);
   this->Varcount = StrToInt(DATFormat->Values["Varcount"]);
   this->VarSize = new int [this->GetVarcount()];
   this->VarStart = new int [this->GetVarcount()];
   this->VarEnd = new int [this->GetVarcount()];
   this->VarOffset = new int [this->GetVarcount()];
   this->Data = new int [this->GetOutputEntrycount()*this->GetVarcount()];
   this->TempEntry = new int [this->GetVarcount()];

   if (this->GetDATTypeID() == 0) {
      this->TempTab = new int [this->GetVarcount()];
      this->TempMix = new int [this->GetVarcount()];
      this->VarArray = new int [this->GetVarcount()];
      this->VarArrayIndex = new int [this->GetVarcount()];
   }

   int Filesize=0;
   for (int i=0;i<this->GetVarcount();i++) {
       if (DATFormat->Values[String(i)+"VarStart"] != "") {
          this->VarStart[i]=StrToInt(DATFormat->Values[String(i)+"VarStart"]);
       }
       else {
          this->VarStart[i]=0;
       }
       
       if (DATFormat->Values[String(i)+"VarEnd"] != "") {
          this->VarEnd[i]=StrToInt(DATFormat->Values[String(i)+"VarEnd"]);
       }
       else {
          this->VarEnd[i]=this->GetOutputEntrycount()-1;
       }

       if (DATFormat->Values[String(i)+"VarArray"] != "") {
          this->VarArray[i]=StrToInt(DATFormat->Values[String(i)+"VarArray"]);
          this->VarArrayIndex[i]=StrToInt(DATFormat->Values[String(i)+"VarArrayIndex"]);
       }
       else if (this->GetDATTypeID() == 0) {
          this->VarArray[i]=1;
          this->VarArrayIndex[i]=0;
       }
       this->VarSize[i]=StrToInt(DATFormat->Values[String(i)+"Size"]);

       if (this->VarArray && this->VarArray[i] != 1 && this->VarArray[i-1] != 1 && this->VarArrayIndex[i] > this->VarArrayIndex[i-1]) {
          this->VarOffset[i]=this->VarOffset[i-1]+this->VarSize[i];
       }
       else {
          this->VarOffset[i]=Filesize;
       }
       Filesize+=this->VarSize[i]*(this->VarEnd[i]-this->VarStart[i]+1);
   }         
   this->SetFilesize(Filesize);
   this->SetFormatLoaded(true);
};
//------------------------------------------------------------------------------
/*
############################################################################
This routine performs all the necessary things and loads a given file to
a FileData structure.
############################################################################
*/
void FileData::LoadFile (String FileName) {
   TMemoryStream* WorkFile = new TMemoryStream();
   if (WorkFile != NULL) {
      WorkFile->LoadFromFile(FileName);
      for (int i=0;i<12;i++) {
          if (i==11){
             MessageDlg(String("\""+FileName+"\" is not a valid DAT file that DatEdit can recognize."), mtError, TMsgDlgButtons() << mbOK, 0);
             break;
          }
          if (WorkFile->Size == Form1->GetDATFile(i)->Filesize) {
             this->SetDatName(FileName);
             this->SetLoadState(true);
             this->SetDefaultState(false);
             if (ExtractFilePath(FileName) == Form1->GetProgPath()+"Default\\") {
                this->SetDefaultState(true);
             }
             this->LoadData(WorkFile->Memory);
             this->SetIsMPQImport(false);
             break;
          }
      }   
   }
   delete WorkFile;
};
//------------------------------------------------------------------------------
/*
############################################################################
This is the core of the whole program. This routine parses through
a DAT file according to a given format (see above) and stores the data
in the 'Data' array.
Important is, that differently to how the data is originaly organized
in the Starcraft DAT files, the 'Data' array is structured by-entry and not
by-property.
Basically, this means that while the DAT file are structured in the following way:
     "Property1 for entry1",
     "Property1 for entry2",
     ...
     "Property2 for entry1",
     "Property2 for entry2",
     etc...

the 'Data' array is constructed the other way round:
    "Property1 for entry1",
    "Property2 for entry1",
    ...
    "Property1 for entry2",
    "Property2 for entry2",
    etc...

2 "for" loops are used to achieve this purpose: the "j-loop" that
goes from 0 to the total number of entries in the DAT file, and the
"i-loop" that goes from 0 to the total number of Var's (read: properties)
in the DAT file.
############################################################################
*/

void FileData::LoadData (void* InputBuffer) {
     int Buffer=0;
     TMemoryStream *DatFile = new TMemoryStream();

     if (DatFile != NULL) {
        DatFile->SetSize(this->Filesize);
        DatFile->Seek(0,soFromBeginning);
        DatFile->Write(InputBuffer,this->Filesize);

        for (int j=0;j<this->OutputEntrycount;j++) {
             for (int i=0;i<this->Varcount;i++) {
                 if ((this->VarStart && j<VarStart[i]) || (this->VarEnd && j>VarEnd[i]) || j>=this->InputEntrycount) {
                    this->Data[(j*this->Varcount)+i] = 0;
                 }
                 else {
                    Buffer = 0;
                    if (this->VarArray) {
                       if (this->VarStart) {
                          DatFile->Seek(this->VarOffset[i]+this->VarSize[i]*this->VarArray[i]*(j-VarStart[i]),soFromBeginning);
                       }
                       else {
                          DatFile->Seek(this->VarOffset[i]+this->VarSize[i]*this->VarArray[i]*j,soFromBeginning);
                       }
                    }
                    else if (this->VarStart) {
                       DatFile->Seek(this->VarOffset[i]+this->VarSize[i]*(j-VarStart[i]),soFromBeginning);
                    }
                    else {
                       DatFile->Seek(this->VarOffset[i]+this->VarSize[i]*j,soFromBeginning);
                    }
                    DatFile->Read((void*)&Buffer,VarSize[i]);
                    this->Data[(j*this->Varcount)+i] = (Buffer);
                 }
             }
        }
     }
     delete DatFile;
};
//------------------------------------------------------------------------------
/*
############################################################################
This routine outputs a FileData object's data to a given file. The data
is preformatted (call to PrepareData()) so that it fits to the proper
DAT file structure.
############################################################################
*/

void FileData::SaveData (String FileName) {
     TFileStream *DatFile = new TFileStream(FileName,fmCreate);
     DatFile->WriteBuffer(this->PrepareData(),this->GetOutputFilesize());
     delete DatFile;
};
//------------------------------------------------------------------------------
/*
############################################################################
This routine is similar to the file-loading routine,but it operates in
the opposite way: it takes the data from the 'Data' array (which is a
uniform integer array) and reorganizes it to the original Starcraft
DAT structure.
############################################################################
*/

void* FileData::PrepareData () {
     int Buffer=0;
     TMemoryStream *DatFile = new TMemoryStream();
     for (int i=0;i<this->Varcount;i++) {
         for (int j=0;j<this->OutputEntrycount;j++) {
             if ((this->VarStart && j<VarStart[i]) || (this->VarEnd && j>VarEnd[i])) {
                continue;
             }
             else {
                Buffer = this->Data[j*this->Varcount+i];
                if (this->VarArray) {
                   if (this->VarStart) {
                      DatFile->Seek(this->VarOffset[i]+this->VarSize[i]*this->VarArray[i]*(j-VarStart[i]),soFromBeginning);
                   }
                   else {
                      DatFile->Seek(this->VarOffset[i]+this->VarSize[i]*this->VarArray[i]*j,soFromBeginning);
                   }
                }
                else if (this->VarStart) {
                   DatFile->Seek(this->VarOffset[i]+this->VarSize[i]*(j-VarStart[i]),soFromBeginning);
                }
                else {
                   DatFile->Seek(this->VarOffset[i]+this->VarSize[i]*j,soFromBeginning);
                }
                DatFile->Write((void*)&Buffer, this->VarSize[i]);
             }
         }
     }
     return DatFile->Memory;
};
//------------------------------------------------------------------------------

void FileData::CopyClipEntry(ClipDAT* Target,int EntryID) {
     for (int i=0;i<this->GetVarcount();i++) {
         Target->Data[i] = this->Data[EntryID*this->GetVarcount()+i];
     }
};

void FileData::PasteClipEntry (ClipDAT* Source, int EntryID) {
     for (int i=0;i<this->GetVarcount();i++) {
         this->Data[EntryID*this->GetVarcount()+i] = Source->Data[i];
     }
};

//------------------------------------------------------------------------------
/*
############################################################################
The following functions control the 3 different ways the Copy/Paste may
work in DatEdit. Note that there are 3 different arrays that store the
data, each for a different method: Copying entire entries, copying only
one tab and the mixed option.
############################################################################
*/
void FileData::CopyTempEntry (int EntryID) {
     for (int i=0;i<this->GetVarcount();i++) {
         this->TempEntry[i] = this->Data[EntryID*this->GetVarcount()+i];
         if (this->GetDATTypeID() == 0) {
            this->TempMix[i] = this->Data[EntryID*this->GetVarcount()+i];
         }
     }
     Form1->SetTempDats(this->GetDATTypeID(), true);
};
//------------------------------------------------------------------------------

void FileData::PasteTempEntry (int EntryID) {
     for (int i=0;i<this->GetVarcount();i++) {
         this->Data[EntryID*this->GetVarcount()+i] = this->TempEntry[i];
     }
};
//------------------------------------------------------------------------------
/*
############################################################################
A few words of explanation here: the special custom code for the Data
property '45' is there because the property is split into two tabs:
'Basic' and 'StarEdit'. The code only copies the part of the value
belonging to the currently used tab, leaving the rest unchanged.
############################################################################
*/

void FileData::CopyTab (int EntryID,int Tab) {
     for (int i=0,k=0;i<this->GetVarcount();i++) {
         if (i==GetTabMemoryOffs(Tab)[k]) {
            if (i==49) {
               unsigned char temp[3];
               temp[0] = this->Data[EntryID*this->GetVarcount()+49];
               temp[1] = this->TempTab[49];
               temp[2] = this->TempMix[49];

               switch (Tab) {
                      case 0:
                           temp[0] = temp[0]*32;
                           temp[0] = temp[0]/32;
                           for (int i=1;i<3;i++) {
                               temp[i] = temp[i]/8;
                               temp[i] = temp[i]*8;
                           }
                           break;
                      case 4:
                           temp[0] = temp[0]/8;
                           temp[0] = temp[0]*8;
                           for (int i=1;i<3;i++) {
                               temp[i] = temp[i]*32;
                               temp[i] = temp[i]/32;
                           }
                           break;
               }
               this->TempTab[49] = temp[0]+temp[1];
               this->TempMix[49] = temp[0]+temp[2];
            }
            else {
               this->TempTab[i] = this->Data[EntryID*this->GetVarcount()+GetTabMemoryOffs(Tab)[k]];
               this->TempMix[i] = this->Data[EntryID*this->GetVarcount()+GetTabMemoryOffs(Tab)[k]];
            }
            k++;
         }
     }
     Form1->SetTempTabs(Form1->GetSubPage(),true);
};
//------------------------------------------------------------------------------
void FileData::PasteTab (int EntryID,int Tab) {
     for (int i=0,k=0;i<this->GetVarcount();i++) {
         if (i==GetTabMemoryOffs(Tab)[k]) {
            if (i==49) {
               unsigned char temp[2];
               temp[0] = this->TempTab[49];
               temp[1] = this->Data[EntryID*this->GetVarcount()+49];

               switch (Tab) {
                      case 0:
                           temp[0] = temp[0]*32;
                           temp[0] = temp[0]/32;
                           temp[1] = temp[1]/8;
                           temp[1] = temp[1]*8;
                           break;
                      case 4:
                           temp[0] = temp[0]/8;
                           temp[0] = temp[0]*8;
                           temp[1] = temp[1]*32;
                           temp[1] = temp[1]/32;
                           break;
               }
               this->Data[EntryID*this->GetVarcount()+49] = temp[0]+temp[1];
            }
            else {
               this->Data[EntryID*this->GetVarcount()+GetTabMemoryOffs(Tab)[k]] = this->TempTab[i];
            }
            k++;
         }
     }
};
//------------------------------------------------------------------------------
void FileData::PasteMix (int EntryID) {
     for (int i=0;i<this->GetVarcount();i++) {
         this->Data[EntryID*this->GetVarcount()+i] = this->TempMix[i];
     }
};
//------------------------------------------------------------------------------
/*
############################################################################
Reload a specific entry from default. The loading function is the same as
in the LoadData function, just that the 'j' variable (entry index) is set
to a specific entry ID value instead of going through all of them.
############################################################################
*/
void FileData::ReloadEntryFromDefault (int EntryID) {
     int Buffer=0;
     TMemoryStream *DatFile = new TMemoryStream();
     DatFile->LoadFromFile(String(Form1->GetProgPath()+"Default//"+GetDATType(this->GetDATTypeID())+".dat"));
     int j = EntryID;
     for (int i=0;i<this->Varcount;i++) {
         if ((this->VarStart && j<VarStart[i]) || (this->VarEnd && j>VarEnd[i])) {
            this->Data[(j*this->Varcount)+i] = 0;
         }
         else {
            Buffer = 0;
            if (this->VarArray) {
               if (this->VarStart) {
                  DatFile->Seek(this->VarOffset[i]+this->VarSize[i]*this->VarArray[i]*(j-VarStart[i]),soFromBeginning);
               }
               else {
                  DatFile->Seek(this->VarOffset[i]+this->VarSize[i]*this->VarArray[i]*j,soFromBeginning);
               }
            }
            else if (this->VarStart) {
                DatFile->Seek(this->VarOffset[i]+this->VarSize[i]*(j-VarStart[i]),soFromBeginning);
            }
            else {
                DatFile->Seek(this->VarOffset[i]+this->VarSize[i]*j,soFromBeginning);
            }
            DatFile->Read((void*)&Buffer,VarSize[i]);
            this->Data[(j*this->Varcount)+i] = (Buffer);
         }
     }
     delete DatFile;
};
//------------------------------------------------------------------------------


