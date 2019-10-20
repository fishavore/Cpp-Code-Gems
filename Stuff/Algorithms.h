#pragma once
#include "hex.h"
#include <iostream>

namespace Algorithms
{
	void hexConversion()
	{
		std::cout << "32 in hex: " << Algorithms::hex(32) << '\n';
		std::cout << "A5 in decimal: " << Algorithms::unhex("A5") << '\n';
	}

	void start()
	{
		hexConversion();
	}
}
