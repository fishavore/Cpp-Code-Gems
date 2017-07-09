#pragma once

#include <iostream>

//Determining information of the compiler and its version and configuration.

//Sidenote: Property pages->Configuration properties-> C/C++ -> All options -> C++ Language Standard -> ISO C++ Latest Draft Standard (/std:c++latest) for the latest version of C++.
//The version below is directed towards the compiler software, not the actual language.

namespace CompilerVersion
{

//////////////////////////////////////////////////////////////////
	//Compiler
	void show_compiler()
	{
#if defined _MSC_VER
		std::cout << "Visual C++" << '\n';
#elif defined __clang__
		std::cout << "Clang" << '\n';
#elif defined __GNUG__
		std::cout << "GCC" << '\n';
#else
		std::cout << "Unknown compiler" << '\n';
#endif
	}


//////////////////////////////////////////////////////////////////

	//Compiler Version

	/*

		MSVC++ 14.1 _MSC_VER == 1911 (Visual Studio 2017)
		MSVC++ 14.1 _MSC_VER == 1910 (Visual Studio 2017)
		MSVC++ 14.0 _MSC_VER == 1900 (Visual Studio 2015)
		MSVC++ 12.0 _MSC_VER == 1800 (Visual Studio 2013)
		MSVC++ 11.0 _MSC_VER == 1700 (Visual Studio 2012)
		MSVC++ 10.0 _MSC_VER == 1600 (Visual Studio 2010)
		MSVC++ 9.0  _MSC_VER == 1500 (Visual Studio 2008)
		MSVC++ 8.0  _MSC_VER == 1400 (Visual Studio 2005)
		MSVC++ 7.1  _MSC_VER == 1310 (Visual Studio 2003)	
	
	*/

	void show_compiler_version()
	{
#if defined _MSC_VER

		std::cout <<
#if (_MSC_VER >= 1910)
			"Visual C++ 2017 or newer"
#else 
			"Visual C++ " << _MSC_FULL_VER
#endif
			<< '\n';

#elif defined __clang__

		std::cout <<
#if (__clang_major__ == 3) && (__clang_minor__ >= 9)
			"Clang 3.9 or newer"
#else
			"Clang " << __clang_version__
#endif
			<< '\n';

#elif defined __GNUG__

		std::cout <<
#if __GNUC__ >= 5 && __GNUC_MINOR__ > 0
			"GCC 5.0 or newer"
#else
			"GCC " << __VERSION__
#endif
			<< '\n';

#else
		std::cout << "Unknown compiler" << '\n';
#endif
	}

//////////////////////////////////////////////////////////////////

	void show_architecture()
	{
#if defined _MSC_VER

		std::cout <<
#if defined _M_X64
			"AMD64"
#elif defined _M_IX86
			"INTEL x86"
#elif defined _M_ARM
			"ARM"
#else
			"Unknown"
#endif
			<< '\n';

#elif defined __clang__ || __GNUG__

		std::cout <<
#if defined __amd64__
			"AMD64"
#elif defined __i386__
			"INTEL x86"
#elif defined __arm__
			"ARM"
#else
			"Unknown"
#endif
			<< '\n';

#else
#error Unknown compiler
#endif
	}

//////////////////////////////////////////////////////////////////

	void show_configuration()
	{
		std::cout <<
#ifdef _DEBUG
			"Debug"
#else
			"Release"
#endif
			<< '\n';
	}

//////////////////////////////////////////////////////////////////

	inline void start()
	{
		show_compiler();

		show_compiler_version();

		show_architecture();

		show_configuration();
	}
}