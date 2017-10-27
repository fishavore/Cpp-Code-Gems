#pragma once

#include <iostream>

namespace Macro
{
	void start()
	{
		/*
			The #define preprocessor directive creates symbolic constants.
			The symbolic constant is called a macro.
			When we use define for a constant, the preprocessor produces a C program where the defined constant is searched
			and matching tokens are replaced with the given expression.
		*/

		//Define a macro:
#define VALUE 100
		std::cout << "Using macro value: " << VALUE << '\n'; // Using macro value: 100
		//Undefine a macro:
#undef VALUE
		//std::cout << "Using macro value: " << VALUE << '\n'; // Value will complain as it is undefined.

	}
}


/*



1) The macros can take function like arguments, the arguments are not checked for data type.
For example, the following macro INCREMENT(x) can be used for x of any data type.

#include <stdio.h>
#define INCREMENT(x) ++x
int main()
{
char *ptr = "AmritSrivastava";
int x = 10;
printf("%s  ", INCREMENT(ptr));
printf("%d", INCREMENT(x));
return 0;
}

2) The macro arguments are not evaluated before macro expansion. For example consider the following program

#include <stdio.h>
#define MULTIPLY(a, b) a*b
int main()
{
// The macro is expended as 2 + 3 * 3 + 5, not as 5*8
printf("%d", MULTIPLY(2+3, 3+5));
return 0;
}
// Output: 16

3) The tokens passed to macros can be concatenated using operator ## called Token-Pasting operator.

#include <stdio.h>
#define merge(a, b) a##b
int main()
{
printf("%d ", merge(12, 34));
}
// Output: 1234

4) A token passed to macro can be converted to a sting literal by using # before it.

#include <stdio.h>
#define get(a) #a
int main()
{
// AmritSrivastava is changed to "AmritSrivastava"
printf("%s", get(AmritSrivastava));
}
// Output: AmritSrivastava

5) The macros can be written in multiple lines using ‘\’. The last line doesn’t need to have ‘\’.

#include <stdio.h>
#define PRINT(i, limit) while (i < limit) \
{ \
printf("AmritSrivastava "); \
i++; \
}
int main()
{
int i = 0;
PRINT(i, 3);
return 0;
}
// Output: AmritSrivsatava  AmritSrivsatava  AmritSrivsatava

*/