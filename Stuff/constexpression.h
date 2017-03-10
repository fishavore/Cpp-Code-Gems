#pragma once

#include <iostream>

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