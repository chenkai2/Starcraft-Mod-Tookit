#include <io.h>
#include <StrUtils.hpp>
#include "Main.h"
//---------------------------------------------------------------------------

#ifndef LoadListH
#define LoadListH
//---------------------------------------------------------------------------
int LookEntry (int TargetID,int TargetPage);
void LoadList (TComboBox* Target,String List,bool IncludeID);
void LoadTBLList (TComboBox* Target,String TBLType);
void SetMenu (TComboBox* Target, unsigned long ItemID);
void SetMenu (TComboBox* Target, TImage* TargetPreview,int ItemID);
//---------------------------------------------------------------------------
void LoadEntryList (TTreeView* TargetList,int DATType);
//---------------------------------------------------------------------------
void LoadDATDir (String Directory);
void LoadUsedList (int PageIndex,int NodeID);
//---------------------------------------------------------------------------
#endif
