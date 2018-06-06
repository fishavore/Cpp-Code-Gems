#include "../includes/DLLExampleCode.h"

#include <string>
#include <iostream>

int __cdecl GetValue()
{
	return 5;
}

void __cdecl GetText(char* str, int strLength)
{
	std::string text = "This is called from within the DLL.\0";
	if (strLength < text.length() || str == nullptr)
	{
		return;
	}
	
	strcpy_s(str, strLength,text.c_str());
}

void __cdecl DLLPrint()
{
	std::cout << "This is printed from inside DLLExample.dll.\n";
}