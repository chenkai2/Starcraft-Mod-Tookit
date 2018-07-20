//---------------------------------------------------------------------------
#pragma hdrstop

#include "TForm1.h"
#include "Main.h"
#include "grpapi.h"
#include "Data.h"
#include <FileCtrl.hpp>
//---------------------------------------------------------------------------
#pragma package(smart_init)
//---------------------------------------------------------------------------
/*
############################################################################
This routine initializes many internal variables that are later used
throughout the program, and sets some useful properties like the program's
location and version, or presence of a Starcraft installation.
############################################################################
*/
void TForm1::InitializeValues() {
     //INITIALIZATION FOR THE MAIN FORM'S VARIABLES
     ListReload = new bool[11];
     EditorReload = new bool[11];
     TempDats = new bool[11];
     DatExport = new bool[11];
     TabSortingStyle = new int[11];
     for (int i=0;i<11;i++) {
         SetListReload(i,false);
         SetEditorReload(i,true);
         SetTempDats(i,false);
         SetDatExport(i,false);
         SetSortingStyle(i,2);

         DATEntryNames[i] = new TStringList;
         DATFormat[i] = new TStringList;

         DATEntryList[i] = new TTreeView(Form1->ElGrandoListos);
         DATEntryList[i]->Parent = Form1->ElGrandoListos;
         DATEntryList[i]->Align = alClient;
         DATEntryList[i]->AutoExpand = false;
         DATEntryList[i]->Color = clBlack;
         DATEntryList[i]->DragMode = dmAutomatic;
         DATEntryList[i]->Enabled = true;
         DATEntryList[i]->HideSelection = false;
         DATEntryList[i]->Hint = "El Grando list of thangs...";
         DATEntryList[i]->Images = BookmarkImage;
         DATEntryList[i]->MultiSelect = true;
         DATEntryList[i]->MultiSelectStyle = TMultiSelectStyle() << msShiftSelect <<msControlSelect;
         DATEntryList[i]->ParentFont = true;
         DATEntryList[i]->ParentShowHint = false;
         DATEntryList[i]->ReadOnly = true;
         DATEntryList[i]->RowSelect = true;
         DATEntryList[i]->RightClickSelect = true;
         DATEntryList[i]->ShowButtons = false;
         DATEntryList[i]->ShowHint = true;
         DATEntryList[i]->ShowLines = false;
         DATEntryList[i]->ShowRoot = false;
         DATEntryList[i]->TabStop = true;
         DATEntryList[i]->ToolTips = false;
         DATEntryList[i]->Visible = true;
         DATEntryList[i]->OnChange = ListChange;
         DATEntryList[i]->OnKeyPress = ListKeyPress;
     }

     TempTabs = new bool[6];
     for (int i=0;i<6;i++) {
         SetTempTabs(i, false);
     }

     TBLExport = new bool[5];
     TBLIsMPQImport = new bool[5];
     for (int i=0;i<5;i++) {
         SetTBLIsMPQImport(i,false);
         SetTBLExport(i,false);
     }

     SetSCPath("");
     SetVer("");
     SetLastFolder("");
     SetMPQName("");
     SetPage(-1);
     SetSubPage(-1);
     SetIsSC(false);
     SetIconExport(false);
     SetIconIsMPQImport(false);
     SetSEExport(false);

     SetGRPMPQHandle(NULL);

     Hints = new TStringList;
     Origins = new TStringList;
     FAQ = new TStringList;
     ExternalPrograms = new TStringList;
     ExternalPrograms->OnChange = ExternalProgramsChangeExecute;

     //STORE THE PROGRAM'S PATH
     SetProgPath(ExtractFilePath(Application->ExeName));

     //REGISTER THE CLIPBOARD FORMAT
     this->ClipFormat = RegisterClipboardFormat("ClipDAT");
     
     //SET PROGRAM'S VERSION AND THE PROGRAM MAIN WINDOW CAPTION
     //AND APPLICATION'S TITLE
     SetVer("1.5d");
     Form1->Caption = "DatEdit v"+GetVer();
     Application->Title = "DatEdit v"+GetVer();
};
//------------------------------------------------------------------------------
/*
############################################################################
This routine adds a new history item. First it checks for the presence of
the "No files in History" string, and if found, deletes it.
It then checks if the item is already on the list, and adds it later only
if it is not yet there. If there are more than 10 items in the history list,
the last one is removed, to keep the number of history items
to a reasonable count of 10.
############################################################################
*/
void TForm1::AddHistoryItem(String ItemName) {
    if (Form1->MRUD->Items[0]->Caption.Pos("No files in History") != 0) {
       Form1->MRUD->Delete(0);
    }
    bool IsHistory=false;
    for (int i=0;i<Form1->MRUD->Count;i++) {
        if (Form1->MRUD->Items[i]->Caption == ItemName) {
           IsHistory = true;
           break;
        }
    }
    if (IsHistory == false) {
        TMenuItem *HistoryItem = new TMenuItem(Form1);
        HistoryItem->Caption = ItemName;
        HistoryItem->OnClick = Form1->LoadHistoryItemExecute;
        Form1->MRUD->Insert(0,HistoryItem);
        if (Form1->MRUD->Count > 10) {
            Form1->MRUD->Items[10]->Free();
        }
    }
};
//------------------------------------------------------------------------------
/*
############################################################################
The following routines control access to TForm1 class member variables.
I use them like global variables, but with an organized access.
The meaning of these variables is obvious, and can be guessed by their
names already.
############################################################################
*/

bool TForm1::GetDatExport (int Index) {
     return Form1->DatExport[Index];
};

void TForm1::SetDatExport (int Index, bool Value) {
     Form1->DatExport[Index] = Value;
};
//------------------------------------------------------------------------------

bool TForm1::GetTempDats (int PageIndex) {
     return Form1->TempDats[PageIndex];
};

void TForm1::SetTempDats (int PageIndex, bool Value) {
     Form1->TempDats[PageIndex] = Value;
};
//------------------------------------------------------------------------------

bool TForm1::GetTempTabs (int PageIndex) {
     return Form1->TempTabs[PageIndex];
};

void TForm1::SetTempTabs (int Index, bool Value) {
     Form1->TempTabs[Index] = Value;
};
//------------------------------------------------------------------------------

String TForm1::GetVer () {
     return Form1->Ver;
};

void TForm1::SetVer (String Version) {
     Form1->Ver = Version;
};
//------------------------------------------------------------------------------

bool TForm1::GetIsSC() {
     return Form1->IsSC;
};

void TForm1::SetIsSC(bool Value) {
     Form1->IsSC = Value;
};
//------------------------------------------------------------------------------

bool TForm1::GetSEExport() {
     return Form1->SEExport;
};

void TForm1::SetSEExport (bool Value) {
     Form1->SEExport = Value;
};
//------------------------------------------------------------------------------
int TForm1::GetPage() {
     return Form1->Page;
};

void TForm1::SetPage(int PageIndex) {
     Form1->Page = PageIndex;
};
//------------------------------------------------------------------------------

int TForm1::GetSubPage() {
     return Form1->SubPage;
}

void TForm1::SetSubPage(int SubPageIndex) {
     Form1->SubPage = SubPageIndex;
}
//------------------------------------------------------------------------------

int TForm1::GetSortingStyle (int PageIndex) {
     return Form1->TabSortingStyle[PageIndex];
};

void TForm1::SetSortingStyle (int PageIndex, int SortingStyle) {
     Form1->TabSortingStyle[PageIndex] = SortingStyle;
};
//------------------------------------------------------------------------------

bool TForm1::GetListReload (int PageIndex) {
     return Form1->ListReload[PageIndex];
};

void TForm1::SetListReload (int PageIndex, bool Value) {
     Form1->ListReload[PageIndex] = Value;
};
//------------------------------------------------------------------------------

bool TForm1::GetEditorReload (int PageIndex) {
     return Form1->EditorReload[PageIndex];
};

void TForm1::SetEditorReload (int PageIndex, bool Value) {
     Form1->EditorReload[PageIndex] = Value;
};
//------------------------------------------------------------------------------

String TForm1::GetLastFolder () {
     return Form1->LastFolder;
};

void TForm1::SetLastFolder (String Folder) {
     Form1->LastFolder = Folder;
};
//------------------------------------------------------------------------------

String TForm1::GetMPQName () {
     return Form1->MPQName;
};

void TForm1::SetMPQName (String MPQName) {
     Form1->MPQName = MPQName;
};
//------------------------------------------------------------------------------

bool TForm1::GetTBLIsMPQImport (int Index) {
     return Form1->TBLIsMPQImport[Index];
};

void TForm1::SetTBLIsMPQImport (int Index,bool Value) {
     Form1->TBLIsMPQImport[Index] = Value;
};
//------------------------------------------------------------------------------

bool TForm1::GetIconIsMPQImport () {
     return Form1->IconIsMPQImport;
};

void TForm1::SetIconIsMPQImport (bool Value) {
     Form1->IconIsMPQImport = Value;
};

//------------------------------------------------------------------------------
bool TForm1::GetTBLExport (int Index) {
     return Form1->TBLExport[Index];
};

void TForm1::SetTBLExport (int Index,bool Value) {
     Form1->TBLExport[Index] = Value;
};


bool TForm1::GetIconExport () {
     return Form1->IconExport;
};

void TForm1::SetIconExport (bool Value) {
     Form1->IconExport = Value;
};

//------------------------------------------------------------------------------
String TForm1::GetProgPath () {
     return Form1->ProgPath;
};

void TForm1::SetProgPath (String ProgPath) {
     Form1->ProgPath = ProgPath;
};
//------------------------------------------------------------------------------

String TForm1::GetSCPath () {
     return Form1->SCPath;
};

void TForm1::SetSCPath (String SCPath) {
     Form1->SCPath = SCPath;
};
//------------------------------------------------------------------------------

void* TForm1::GetSCMPQHandles(int HandleID) {
     return Form1->SCMPQHandles[HandleID];
};

void TForm1::SetSCMPQHandles (int HandleID, void* Handle) {
     Form1->SCMPQHandles[HandleID] = Handle;
};
//------------------------------------------------------------------------------

void* TForm1::GetMPQHandle() {
     return Form1->MPQHandle;
};

void TForm1::SetMPQHandle (void* Handle) {
     Form1->MPQHandle = Handle;
};
//------------------------------------------------------------------------------

void* TForm1::GetGRPMPQHandle() {
     return Form1->GRPMPQHandle;
};

void TForm1::SetGRPMPQHandle (void* Handle) {
     Form1->GRPMPQHandle = Handle;
};
//------------------------------------------------------------------------------

TStringList* TForm1::GetDATEntryNames (int Index) {
     return Form1->DATEntryNames[Index];
};
//------------------------------------------------------------------------------

TStringList* TForm1::GetDATFormat (int Index) {
     return Form1->DATFormat[Index];
};
//------------------------------------------------------------------------------

TTreeView* TForm1::GetDATEntryList (int Index) {
     return Form1->DATEntryList[Index];
};
//------------------------------------------------------------------------------

FileData* TForm1::GetDATFile (int Index) {
     return &Form1->DATFile[Index];    
}
//------------------------------------------------------------------------------


