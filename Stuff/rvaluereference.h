#pragma once

#include <iostream>
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

inline void rvaluereference()
{
	int&& i = 42;
	int j = 42;
	//int&& k = j; // wont compile as j isn't a rvalue. it's a lvalue.

	std::vector<int> fillThisVar, fillThisVar2;
	process_copy(fillThisVar); //clumsy
	process_copy(std::move(fillThisVar2)); //ok
	std::cout << "rvalue: " << fillThisVar[0] << " " << fillThisVar2[0] << "\n";
}