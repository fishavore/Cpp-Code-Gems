#include "../includes/DLLExampleCode.h"

#include <string>

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