#pragma once


#include <iostream>
#include <string>

/*

Author note:
My own tests shows a different result. It might not actually be faster but instead slower.
Make your own tests in order to verify the speed up!


*/



/*

Look up tables can be used in various ways but the point of a lookup table is reducing
computation time to just look up the value. The most simple case would be:

float a; int b;
a = (b == 0) ? 1.0f : 2.5f;

could be changed to:

float a; int b;
const float OneOrTwo5[2] = {1.0f, 2.5f};
a = OneOrTwo5[b & 1];

Why? Well, the branch prediction may cause a lot of misses. But lookupTable() shows a rather more
genious idea of using it.

*/

namespace LookupTable
{

	inline void main()
	{
		int n = 5;
		std::string val;

		//Not a look up table. This is a switch statement.
		switch (n)
		{
		case 0:
			val = "Look";
			break;
		case 1:
			val = "up";
			break;
		case 2:
			val = "table";
			break;;
		case 3:
			val = "LUL";
			break;
		case 4:
			val = "OMFG";
			break;
		case 5:
			val = "So nice";
			break;
		case 6:
			val = "Not switch statements tho";
			break;
		default:
			val = "error";
			break;
		}
		std::cout << val << '\n';


		//The lookup table. Just a simple const array bruh.
		static const std::string stringArray[7] = { "Look", "up", "table", "LUL", "OMFG", "So nice", "Not switchstatements tho" };
		if (n < 6)
		{
			std::cout << stringArray[n] << '\n';
		}

		//The advantage of using static here is that the list(stringArray) does not need to be initialized when the
		//function is called.The values are simply put there when the program is loaded into memory.
		//If the word static is removed from the above example, then all five values have to be put
		//into the list every time the function is called.
		//This is done by copying the entire list from
		//static memory to stack memory.Copying constant data from static memory to the stack is a
		//waste of time in most cases, but it may be optimal in special cases where the data are used
		//many times in a loop where almost the entire level - 1 cache is used in a number of arrays
		//that you want to keep together on the stack.
	}
}