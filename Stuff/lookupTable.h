#pragma once


#include <iostream>
#include <string>

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



inline void lookupTable()
{
	int n = 5;
	std::string val;
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
	std::cout << val << "\n";


	//The actual lookup table.
	//Notice double const as to both the value and the pointer is const.
	const std::string const stringArray[7] = { "Look", "up", "table", "LUL", "OMFG", "So nice", "Not switchstatements tho" };
	if (n < 6)
	{
		std::cout << stringArray[n] << "\n";
	}
}