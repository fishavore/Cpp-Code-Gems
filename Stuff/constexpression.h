#pragma once

#include <iostream>

//Useless other examples that you could do... Const expr feels like it's designed for
//the use of Templates. Basically, when you are unsure of the type on the input value
//you can still perform task optimally.
// https://arne-mertz.de/2017/03/constexpr-additions-c17/

namespace ConstExpression
{
	inline constexpr int square(int x) //returns const expression
	{
		return x*x;
	}

	inline void main()
	{
		int array[square(2)];
		for (int i = 0; i < 4; i++)
		{
			array[i] = i;
			std::cout << array[i] << " ";
		}
		std::cout << '\n';
	}
}