#pragma once

#ifdef __cplusplus  
#define FORC extern "C" // only need to export C interface if used by C++ source code
#else
#define FORC 
#endif

#if defined DLL_EXPORT
#define DECLDIR __declspec(dllexport)
#else
#define DECLDIR __declspec(dllimport)
#endif

namespace DLLExampleCode
{
	FORC DECLDIR void Print();
	FORC DECLDIR void GetString(unsigned char* str, int size);
}