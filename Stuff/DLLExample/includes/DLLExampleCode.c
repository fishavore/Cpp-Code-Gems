#pragma once

#include "../source/DLLExampleCode.h"

extern "C" { // only need to export C interface if used by C++ source code


#if defined DLL_EXPORT
#define DECLDIR __declspec(dllexport)
#else
#define DECLDIR __declspec(dllimport)
#endif

	MainClass* m_instance;

	DECLDIR void Init()
	{
		m_instance = new MainClass();
	}

	DECLDIR void Print()
	{
		m_instance->Print();
	}

	DECLDIR void GetString(unsigned char* str, int size)
	{
		m_instance->GetString(str, size);
	}

	DECLDIR void Dispose()
	{
		delete m_instance;
	}
}