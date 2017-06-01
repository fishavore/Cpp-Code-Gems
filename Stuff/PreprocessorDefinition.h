#pragma once

#include <iostream>
#include <string>
namespace PreprocessorDefinition
{
#ifdef _ONEWAYTODOIT
	inline void start()
	{
		std::cout << "Function written WITH preprocessor definition.\n";
		// Properties -> c/c++ -> Preprocessor -> Preprocessor Definitions.
	}
#else
	inline void start()
	{
		std::cout << "This function is written WITHOUT the preprocessor definition project settings.\n";
		// Properties -> c/c++ -> Preprocessor -> Preprocessor Definitions.
	}
#endif
}