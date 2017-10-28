#pragma once

#include <iostream>




namespace Macro
{
	void theBasics()
	{
		//A macro is not the same as a preprocessor definition.
		//A macro pretty much try to switch out the content with the name
		{
			//Define a macro:
#define VALUE 100
			std::cout << "Using macro value: " << VALUE << '\n'; // Using macro value: 100
			//Undefine a macro:
#undef VALUE
			//std::cout << "Using macro value: " << VALUE << '\n'; // Value will complain as it is undefined.
		}
		//

		//Macros are not type safe.
		{
#define INCREMENT(x) ++x
			char *ptr = "ASDF";
			printf("%s \n", INCREMENT(ptr)); //outputs SDF
			int x = 5;
			printf("%d \n", INCREMENT(x)); //outputs 6
#undef INCREMENT
		}
	}

	void theAdvanced()
	{
		//The macro arguments are not evaluated before macro expansion.
		{
#define MULTIPLYBAD(a, b) a*b
#define MULTIPLYGOOD(a, b)

			// The macro is expanded as 2 + 3 * 3 + 5, not as 5*8
			printf("Bad: %d \n", MULTIPLYBAD(2 + 3, 3 + 5)); //outputs 16 not 40.
#undef MULTIPLYBAD
		}

		//The tokens passed to macros can be concatenated using operator ## called Token-Pasting operator.
		//Concatenated means you join strings together. Snow and ball would become Snowball. :)
		{
#define merge(a, b) a##b
			printf("%d \n", merge(12, 34)); //outputs 1234.
#undef merge
		}

		//A token passed to macro can be converted to a string literal by using # before it.
		{
#define VARISNOWASTRING(a) #a
			printf("%s \n", VARISNOWASTRING(ASDF)); //outputs: ASDF
#undef VARISNOWASTRING
		}

		//Macro can be written in multiple lines using '\'
		{
#define	MULTIPLELINEMACRO(x)\
{\
	printf("%s You cant debug this.\n", x);\
}
			MULTIPLELINEMACRO("Hey! "); //outputs Hey! Remember, you cant debug this.
#undef MULTIPLELINEMACRO
		}
	}

	void theBad()
	{
		//1. You can not debug macros.

		//2. Macro expansion can lead to strange side effects.
		//Example:
		{
#define SQUARE(x) ((x) * (x))
			int x1 = 5;
			int x2 = 5;
			int x3 = 5;
			std::cout << "SQUARE(x1): " << SQUARE(x1) << '\n'; //5*5 ouputs: 25
			std::cout << "SQUARE(++x2): " << SQUARE(++x2) << '\n'; //What actually happens: ++x2 -> 6. -> (++6)*(++6) -> 7*7 -> outputs: 49  /// What the fuck?
			std::cout << "SQUARE(x3++): " << SQUARE(x3++) << '\n'; //(5++) * (5++) outputs: 25 /// What the fuck?
#undef SQUARE
		}

		//3. Macros have no "namespace", so if you have a macro that clashes with a name used elsewhere, you get macro replacements where you didn't want it, 
		//and this usually leads to strange error messages.
		
		//4. Macros may affect things you don't realize.
		{
#define someMacroFunc() x = 0

			int x = 5;
			someMacroFunc();
			std::cout << x << '\n'; //ouputs 0
		}
	}

	void start()
	{
		theBasics();
		theAdvanced();
		theBad();
	}
}