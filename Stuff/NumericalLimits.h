#pragma once

#include <iostream>

#ifdef min
#undef min
#endif
#ifdef max
#undef max
#endif

#include <limits>

//This file broke a little due to a macro.

/*

Numerical limits in STD allows you to check boundaries and other things of base types. 

source: https://github.com/PacktPublishing/Modern-Cpp-Programming-Cookbook/blob/master/Chapter02/recipe_2_02.h
*/

namespace NumericalLimits
{
	template <typename T>
	void print_type_properties()
	{
		std::cout
			<< "min=" << std::numeric_limits<T>::min() << '\n'
			<< "max=" << std::numeric_limits<T>::max() << '\n'
			<< "bits=" << std::numeric_limits<T>::digits << '\n'
			<< "decdigits=" << std::numeric_limits<T>::digits10 << '\n'
			<< "integral=" << std::numeric_limits<T>::is_integer << '\n'
			<< "signed=" << std::numeric_limits<T>::is_signed << '\n'
			<< "exact=" << std::numeric_limits<T>::is_exact << '\n'
			<< "infinity=" << std::numeric_limits<T>::has_infinity << '\n';
	}

	//////////////////////////////////////////////////////
	//Example purpose

	int minimum(int const * const start, int const * const end)
	{
		int minval = INT_MAX;
		for (int const * p = start; p != end; ++p)
		{
			if (*p < minval)
				minval = *p;
		}
		return minval;
	}

	template<typename T, typename I>
	T minimum(I const start, I const end)
	{
		T minval = std::numeric_limits<T>::max();
		for (auto i = start; i < end; ++i)
		{
			if (*i < minval)
				minval = *i;
		}
		return minval;
	}

	///////////////////////////////////////////////////////

	inline void start()
	{
		print_type_properties<unsigned short>();
		print_type_properties<double>();
		print_type_properties<int>();

		//print_type_properties<A>(); //custom class do not work
	}
}