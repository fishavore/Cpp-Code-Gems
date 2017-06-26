#pragma once

#include <iostream>
#include <vector>

//more info at http://www.cprogramming.com/c++11/rvalue-references-and-move-semantics-in-c++11.html

namespace RValueReference
{
	inline void process_copy(std::vector<int>& vec_) //bad
	{
		//std::vector<int> vec(vec_);
		vec_.push_back(123);
	}

	inline void process_copy(std::vector<int> && vec) //good
	{
		vec.push_back(456);
		
		//The reason of why this is good is that we reduce the amount of copying.
		//The memory is handled more effectively. Read link for further details.
	}

	void foo(int&& a)
	{
		//Some magical code...
	}

	inline void start()
	{
		int&& i = 42;
		int j = 42;
		//int&& k = j; // wont compile as j isn't a rvalue. it's a lvalue.

		std::vector<int> fillThisVar, fillThisVar2;
		process_copy(fillThisVar); //clumsy
		process_copy(std::move(fillThisVar2)); //ok
		std::cout << "rvalue: " << fillThisVar[0] << " " << fillThisVar2[0] << '\n';

		//
		int b = 5;
		//foo(b); //Error. An rValue reference cannot be pointed to a iValue.
		foo(5); //Compiles with no error.
		foo(b + 3); //Compiles with no error.

	   // int&& c = b; //Error. An rValue reference cannot be pointed to a iValue.
		int&& d = 5; //Compiles with no error.
	}
}