#pragma once

#include <tuple>
#include <iostream>

namespace Tuples
{
	inline void start()
	{
		auto playerProfile = std::make_tuple(5, "Candy", 1.23);
		std::cout <<
			"Int: "			<< std::get<0>(playerProfile) << " " <<
			"const char*: " << std::get<1>(playerProfile) << " " <<
			"double: "		<< std::get<2>(playerProfile) << '\n';
	}
}