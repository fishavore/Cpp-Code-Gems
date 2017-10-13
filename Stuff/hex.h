#pragma once

#include <sstream>
#include <string>

namespace Algorithms
{
	std::string hex(int input)
	{
		std::stringstream ss;
		ss << std::hex << input; // int decimal_value
		std::string res(ss.str());
		return res;
	}

	int unhex(std::string input)
	{
		int decimal_value;
		std::stringstream ss;
		ss << input; // std::string hex_value
		ss >> std::hex >> decimal_value; //int decimal_value
		return decimal_value;
	}
}