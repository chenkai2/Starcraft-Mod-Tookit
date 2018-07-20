#include "Main.h"
//---------------------------------------------------------------------------

#ifndef EntryDataH
#define EntryDataH
//---------------------------------------------------------------------------
void DrawUnitSize(int EntryID,int ViewLeft,int ViewUp,int ViewRight,int ViewDown);
void DrawIcon(int IconIndex,TImage *TargetPreview);
void DrawSelCircle(int EntryID,int CircleID,int CircleOff);
void DrawHPBar(int HPBarLength); 

void DisplayEntryData (int EntryID,int PageIndex);
void ChangeEntryData (int EntryID,int PageIndex,unsigned int value,TObject* Target);
//---------------------------------------------------------------------------
#endif

