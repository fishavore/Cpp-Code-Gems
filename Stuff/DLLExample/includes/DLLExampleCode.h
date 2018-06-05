#pragma once

#define DLLExport _declspec(dllexport)

extern "C" DLLExport int __cdecl GetValue();

extern "C" DLLExport void __cdecl GetText(char* str, int strLength);