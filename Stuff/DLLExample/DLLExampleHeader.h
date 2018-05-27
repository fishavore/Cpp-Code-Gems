#pragma once

#ifdef __cplusplus  
extern "C" {  // only need to export C interface if used by C++ source code
#endif 

#if defined DLL_EXPORT
#define DECLDIR __declspec(dllexport)
#else
#define DECLDIR __declspec(dllimport)
#endif

namespace DLLExampleHeader
{

}

#ifdef __cplusplus  
}
#endif 