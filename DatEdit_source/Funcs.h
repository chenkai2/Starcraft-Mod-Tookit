//---------------------------------------------------------------------------

#ifndef FuncsH
#define FuncsH

#include "QDPlugin.h"
#include <vector>

using namespace std;

bool ReadWholeFile(char * szFileName, LPVOID * lpData, DWORD * lpSize);
LPVOID LoadResource(LPCSTR szResName, LPCSTR szType, LPDWORD lpSize);
//---------------------------------------------------------------------------
#endif
