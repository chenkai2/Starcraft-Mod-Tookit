//---------------------------------------------------------------------------

#ifndef FileDataH
#define FileDataH
#include <ComCtrls.hpp>

//---------------------------------------------------------------------------
class ClipDAT {
public:
      int DATType, EntryID;
      int Data[59];

      operator ClipDAT *() {return this;}
      ClipDAT(int Type, int ID);
      ClipDAT();
};

ClipDAT::ClipDAT () {
      this->DATType = 0;
      this->EntryID = 0;
}

ClipDAT::ClipDAT (int Type, int ID) {
      this->DATType = Type;
      this->EntryID = ID;
}

//---------------------------------------------------------------------------

class FileData {
private:
      int InputEntrycount,OutputEntrycount;
      int DATTypeID,Varcount,Filesize;
      int *Data,*VarOffset,*VarSize,*VarStart,*VarEnd,*VarArray,*VarArrayIndex;
      int *TempEntry,*TempTab,*TempMix;
      String DatName;
      bool IsLoaded,IsDefault,IsMPQImport,FormatLoaded;
      
public:
      FileData();
      FileData(FileData &File);

      operator FileData *() {return this;}
      FileData operator = (FileData *File);

      String GetDatName();
      void SetDatName(String FileName);

      bool GetIsMPQImport();
      void SetIsMPQImport(bool Value);

      bool GetFormatLoaded();
      void SetFormatLoaded(bool Value);

      int GetInputEntrycount();
      void SetInputEntrycount(int Value);

      int GetOutputEntrycount();
      void SetOutputEntrycount(int Value);

      int GetVarcount();
      void SetVarcount(int Value);

      int GetFilesize();
      void SetFilesize(int Value);

      int GetDATTypeID();
      void SetDATTypeID(int Value);

      int* GetData();
      int GetVarSize(int VarID);

      bool GetLoadState();
      void SetLoadState(bool Value);

      bool GetDefaultState();
      void SetDefaultState(bool Value);

      void CopyClipEntry(ClipDAT* File,int EntryID);
      void PasteClipEntry(ClipDAT* Source, int EntryID);

      void CopyTempEntry(int EntryID);
      void PasteTempEntry(int EntryID);
      void CopyTab(int EntryID,int Tab);
      void PasteTab(int EntryID, int Tab);
      void PasteMix(int EntryID);

      void LoadFormat(TStringList* DATFormat);
      void ReloadEntryFromDefault(int EntryID);

      void LoadFile(String FileName);
      void LoadData(void* InputBuffer);
      void SaveData(String FileName);
      void* PrepareData();
      int GetOutputFilesize();
};

//---------------------------------------------------------------------------

#endif
