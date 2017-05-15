#pragma once
#include<iostream>
namespace DebugRelease
{
	inline void start()
	{
		using namespace std;
#if _DEBUG
		cout << "Debug\n";
#endif
#if NDEBUG
		cout << "Release\n";
#endif
	}
}