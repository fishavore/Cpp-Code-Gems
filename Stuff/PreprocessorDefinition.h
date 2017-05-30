#pragma once

#include <iostream>
#include <string>
namespace PreprocessorDefinition
{
#ifdef _ONEWAYTODOIT
	inline void start()
	{
		std::cout << "Function written WITH preprocessor definition.\n";
		std::cout << "Properties -> c/c++ -> Preprocessor -> Preprocessor Definitions. \n";
	}
#else
	inline void start()
	{
		std::cout << "This function is written WITHOUT the preprocessor definition project settings.\n";
		std::cout << "Properties -> c/c++ -> Preprocessor -> Preprocessor Definitions. \n";
	}
#endif
}