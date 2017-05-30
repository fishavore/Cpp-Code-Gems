#pragma once

#include <iostream>
#include <string>
namespace PreprocessorDefinition
{
#ifdef _ONEWAYTODOIT
	inline void start()
	{
		std::cout << "Function written by preprocessor definition.\n";
		std::cout << "Properties -> c/c++ -> Preprocessor -> Preprocessor Definitions. \n";
	}
#else
	inline void start()
	{
		std::cout << "This function is written when the preprocessor definition is removed in project settings.\n";
		std::cout << "Properties -> c/c++ -> Preprocessor -> Preprocessor Definitions. \n";
	}
#endif
}