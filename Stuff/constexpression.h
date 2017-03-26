#pragma once

#include <iostream>

//TODO: https://arne-mertz.de/2017/03/constexpr-additions-c17/

inline constexpr int square(int x) //returns const expression
{
	return x*x;
}

inline void constexpression()
{
	int array[square(2)];
	for (int i = 0; i < 4; i++)
	{
		array[i] = i;
		std::cout << array[i] << " ";
	}
	std::cout << "\n";
}