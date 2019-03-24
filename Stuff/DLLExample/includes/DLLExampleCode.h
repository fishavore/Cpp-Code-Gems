#pragma once

#define DLLExport _declspec(dllexport)

extern "C" DLLExport void __cdecl GetCSharpText(char* str, int* strLength);

extern "C" DLLExport void __cdecl GetCppText(char* str, int* strLength);

extern "C" DLLExport void __cdecl DLLPrint();

//Detta är en kommunikationsfunktion till C#. Cpp -> C#.
typedef int(__stdcall *MY_CALLBACK)(char* str, int length); //Likadan som i C# (delegate).
extern "C" DLLExport void __cdecl SetCallback(MY_CALLBACK callback);