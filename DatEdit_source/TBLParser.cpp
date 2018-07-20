//---------------------------------------------------------------------------
#pragma hdrstop
#include "TBLParser.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
//---------------------------------------------------------------------------
/*
############################################################################
This routine parses -if it is not empty- the TBL file passed to it
in the TBLData parameter, and outputs it, properly formatted (by the
call to ConvertTBLStrings) to the TStrings* component passed as OutputStrings.

This function is an adapted (and slightly optimized) code received
from DiscipleOfAdun;
############################################################################
*/
void ReadTBL (CustomFile *TBLData, TStrings* OutputStrings)
{
if (TBLData->Size != 0) {
   OutputStrings->Clear();
   if (Form1->GetPage() == 1 || Form1->GetPage() == 4 || Form1->GetPage() == 5 || Form1->GetPage() == 6 || Form1->GetPage() == 7 || Form1->GetPage() == 8 || Form1->GetPage() == 10 || (TBLData->IsEqual(Form1->TBLs[1]))) {
      OutputStrings->Add("None");
   }
   char* TBLString = new char[256];
   for (int i = 0; i < *(WORD*) ((char*)(TBLData->Data)); i++) {
       WORD* Loc = (WORD*)(DWORD)((char*)(TBLData->Data))+i+1;
       int StrLen=0;

       if (i == *(WORD*)((char*)(TBLData->Data))-1) {
          StrLen = TBLData->Size - *(Loc);
       }
       else {
          StrLen = *(Loc+1) - *(Loc);
       }
       memcpy(TBLString, (void*)((unsigned int)((char*)(TBLData->Data)) + *Loc), StrLen);
       ConvertTBLString(TBLString, StrLen);
       OutputStrings->Add(TBLString);
   }
   delete TBLString;
}
else {
     MessageDlg(String("Failed to load "+TBLData->FileName+"."), mtError, TMsgDlgButtons() << mbOK, 0);
}
};
//------------------------------------------------------------------------------
/*
############################################################################
This function formats a given string 'string' of length 'len' using the 
"<X>" tag format. Code received from DiscipleOfAdun, modified by me.
############################################################################
*/

void ConvertTBLString(char *string, int &len)
{
char tmp[256] = "";
int tmplength = len;
for (int count = 0; count < len; count++) {
    if (string[count] < 0x20) {
       char tmp2[10] = "0";
       strcat(tmp, "<");
       ltoa( string[count], tmp2, 10);
       strcat(tmp, tmp2);
       strcat(tmp, ">");
       tmplength += 2;
    }
    else {
       char tmp2[10];
       tmp2[0] = string[count];
       tmp2[1] = '\0';
       strcat(tmp, tmp2);
    }

}
strcpy((char*)string, tmp);
len = tmplength;
};
//------------------------------------------------------------------------------
