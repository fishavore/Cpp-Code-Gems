#include "../includes/DLLExampleCode.h"

#include <string>
#include <iostream>

static MY_CALLBACK g_callback = nullptr;

void __cdecl GetCSharpText(char* str, int* strLength)
{
	//
	char strNameSharp[256];
	int strNameSharpLength = 256;
	int result = 0;
	if (nullptr != g_callback)
	{
		result = g_callback(&strNameSharp[0], strNameSharpLength);
	}

	std::string text = std::string(strNameSharp);

	if (*strLength < text.length() || str == nullptr)
	{
		return;
	}
	memset((void*)str, 0, (*strLength) * sizeof(char));
	strcpy_s(str, *strLength, text.c_str());
	*strLength = text.length();
}

void __cdecl GetCppText(char* str, int* strLength)
{
	std::string text = "This is called from within the DLL.\0";
	if (*strLength < text.length() || str == nullptr)
	{
		return;
	}
	memset((void*)str, 0, (*strLength) * sizeof(char));
	strcpy_s(str, *strLength,text.c_str());
	*strLength = text.length();
}

void __cdecl DLLPrint()
{
	std::cout << "This is printed from inside DLLExample.dll.\n";
}

void __cdecl SetCallback(MY_CALLBACK callback)
{
	g_callback = callback;
}