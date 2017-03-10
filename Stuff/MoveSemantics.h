#pragma once

#include <vector>

inline void process_copy(std::vector<int>& vec_) //bad
{
	//std::vector<int> vec(vec_);
	vec_.push_back(123);
}

inline void process_copy(std::vector<int> && vec) //good
{
	vec.push_back(456);
}