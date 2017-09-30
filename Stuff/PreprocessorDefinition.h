#pragma once

#include <iostream>
#include <string>
namespace PreprocessorDefinition
{
#ifndef PROJECT_NAME
#define PROJECT_NAME
#endif

#ifdef _ONEWAYTODOIT
	inline void start()
	{
		// Properties -> c/c++ -> Preprocessor -> Preprocessor Definitions.
		std::cout << "Function written WITH preprocessor definition.\n";
		
		//Writing the actual name of the project in visual studios inside the code. Check Preprocessor Definitions
		//for "All configurations". It says: PROJECT_NAME="$(ProjectName)";
		std::cout << PROJECT_NAME << '\n';
	}
#else
	inline void start()
	{
		// Properties -> c/c++ -> Preprocessor -> Preprocessor Definitions.
		std::cout << "This function is written WITHOUT the preprocessor definition project settings.\n";
	}
#endif
}