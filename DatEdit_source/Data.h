#include <io.h>
#include <fcntl.h>
#include <StrUtils.hpp>
#include "Main.h"
#include "LoadList.h"
#include "SFmpqapi.h"

//---------------------------------------------------------------------------
#ifndef DataH
#define DataH
//---------------------------------------------------------------------------
void CheckDATFile (String FileName);
bool CheckMPQFile (String MPQFileName);
void ExportToMpq (String MpqName,String FileName,void *Buffer,int Size);
unsigned int FixVarSize (int VarValue, int VarID, int PageIndex);
//---------------------------------------------------------------------------
int GetSortData (int Index, int PageIndex);
int GetUnitsSortData (int Index);
int GetUnitsSortSubData (int Index);
int GetNameID (int DatType,int EntryID);
int GetBookmarkID (String BookmarkCaption);
int* GetTabMemoryOffs (int Tab);
String GetDATType (int PageIndex);
String GetDataType (int PageIndex);
String GetTBLType (int Index);
//---------------------------------------------------------------------------
#endif
