#pragma once

#ifdef DLL_SERVERCORE_EXPORTS
#define _SERVERCORE_DECLSPEC __declspec(dllexport)
#define EXPIMP_TEMPLATE
#else
#define _SERVERCORE_DECLSPEC __declspec(dllimport)
#define EXPIMP_TEMPLATE extern
#endif


// = 0x0600 for VISTA level from sdkddkver.h
#define _WIN32_WINNT _WIN32_WINNT_LONGHORN 
#define WINVER       _WIN32_WINNT_LONGHORN 


// Always compiler using Unicode.
#ifndef UNICODE
    #define UNICODE
#endif

// When using Unicode Windows functions, use Unicode C-Runtime functions too.
#ifdef UNICODE
    #ifndef _UNICODE
        #define _UNICODE
    #endif
#endif

#ifndef WIN32_LEAN_AND_MEAN
# define WIN32_LEAN_AND_MEAN
#endif

////////////// Allow code to compile cleanly at warning level 4 ///////////////
#pragma warning(push, 3)
#include <Windows.h>
#pragma warning(pop) 
#pragma warning(push, 4)
#include <CommCtrl.h>
#include <process.h>
#include <strsafe.h>
#include <crtdbg.h>

#include <string>
#include <iostream>

#include <set>
#include <list>
#include <vector>
#include <queue>
#include <unordered_map>
#include <unordered_set>


/* nonstandard extension 'single line comment' was used */
#pragma warning(disable:4001)

// unreferenced formal parameter
#pragma warning(disable:4100)

// Note: Creating precompiled header 
#pragma warning(disable:4699)

// function not inlined
#pragma warning(disable:4710)

// unreferenced inline function has been removed
#pragma warning(disable:4514)

// assignment operator could not be generated
#pragma warning(disable:4512)

// conversion from 'LONGLONG' to 'ULONGLONG', signed/unsigned mismatch
#pragma warning(disable:4245)

// 'type cast' : conversion from 'LONG' to 'HINSTANCE' of greater size
#pragma warning(disable:4312)

// 'argument' : conversion from 'LPARAM' to 'LONG', possible loss of data
#pragma warning(disable:4244)

// 'wsprintf': name was marked as #pragma deprecated
#pragma warning(disable:4995)

// unary minus operator applied to unsigned type, result still unsigned
#pragma warning(disable:4146)

// 'argument' : conversion from 'size_t' to 'int', possible loss of data
#pragma warning(disable:4267)

// nonstandard extension used : nameless struct/union
#pragma warning(disable:4201)

/*
When the compiler sees a line like this:
   #pragma chMSG(Fix this later)

it outputs a line like this:

  c:\CD\CmnHdr.h(82):Fix this later

You can easily jump directly to this line and examine the surrounding code.
*/

#define chSTR2(x) #x
#define chSTR(x)  chSTR2(x)
#define chMSG(desc) message(__FILE__ "(" chSTR(__LINE__) "):" #desc)

#define chINRANGE(low, Num, High) (((low) <= (Num)) && ((Num) <= (High)))
#define chSIZEOFSTRING(psz)   ((lstrlen(psz) + 1) * sizeof(TCHAR))

////////////////// DebugBreak Improvement for x86 platforms ///////////////////


#ifdef _X86_
    #define DebugBreak()    _asm { int 3 }
#endif


inline void chMB(PCSTR szMsg) {
    char szTitle[MAX_PATH];
    GetModuleFileNameA(NULL, szTitle, _countof(szTitle));
    MessageBoxA(GetActiveWindow(), szMsg, szTitle, MB_OK);
}


inline void chFAIL(PSTR szMsg) {
    chMB(szMsg);
    DebugBreak();
}

inline void chASSERTFAIL(LPCSTR file, int line, PCSTR expr) {
    char sz[2 * MAX_PATH];
    wsprintfA(sz, "File %s, line %d : %s", file, line, expr);
    chFAIL(sz);
}


#ifdef _DEBUG
#define chASSERT(x) if (!(x)) chASSERTFAIL(__FILE__, __LINE__, #x)
#else
#define chASSERT(x)
#endif


#ifdef _DEBUG
#define chVERIFY(x) chASSERT(x)
#else
#define chVERIFY(x) (x)
#endif


#pragma comment(linker, "/nodefaultlib:oldnames.lib")
