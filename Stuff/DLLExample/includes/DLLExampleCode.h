#pragma once

#ifdef __cplusplus  
#define FORC extern "C" // only need to export C interface if used by C++ source code
#else
#define FORC 
#endif

#define DLLExport _declspec(dllexport)

FORC DLLExport int __cdecl GetValue();

FORC DLLExport void __cdecl GetText(char* str, int strLength);

FORC DLLExport void __cdecl DLLPrint();