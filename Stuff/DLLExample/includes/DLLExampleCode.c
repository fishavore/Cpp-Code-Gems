#pragma once

#include "../source/DLLExampleCode.h"

extern "C" { // only need to export C interface if used by C++ source code


#if defined DLL_EXPORT
#define DECLDIR __declspec(dllexport)
#else
#define DECLDIR __declspec(dllimport)
#endif

	MainClass* m_instance;

	DECLDIR void __stdcall Init()
	{
		m_instance = new MainClass();
	}

	DECLDIR void __stdcall Print()
	{
		m_instance->Print();
	}

	DECLDIR void __stdcall GetString(unsigned char* str, int size)
	{
		m_instance->GetString(str, size);
	}

	DECLDIR void __stdcall Dispose()
	{
		delete m_instance;
	}
}