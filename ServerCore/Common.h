#pragma once

#ifdef DLL_SERVERCORE_EXPORTS
#define _SERVERCORE_DECLSPEC __declspec(dllexport)
#else
#define _SERVERCORE_DECLSPEC __declspec(dllimport)
#endif

#ifndef WIN32_LEAN_AND_MEAN
# define WIN32_LEAN_AND_MEAN
#endif

#include <Windows.h>

#include <iostream>
#include <string>
