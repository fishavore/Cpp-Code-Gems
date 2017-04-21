#pragma once

#include <array>
#include <iostream>

namespace StdArray
{
	inline void main()
	{
		const int CAP = 5;
		std::array<int, CAP> nummer;
		for (int i = 0; i < CAP; i++)
		{
			nummer[i] = i + 1;
		}
		for (auto i : nummer)
		{
			std::cout << i << "\n";
		}
	}
}