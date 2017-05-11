#pragma once

//lambda funcs
#include <iostream>
#include <algorithm>
#include <vector>

//One guy claimed that lambda functions is good to maintain
//functional programming due to limiting function into restricted size.
//The function, to my understanding is inlining a lot, rather than
//creating entirely new functions. Better in performance? I dunno.
//Does it feel better to use? Perhaps in combination of algorithms.
//Declaring the lambda before a for-loop, to use it inside might be cool tho.

namespace Lambda
{
	inline void lambdaHelloWord()
	{
		//basic
		auto func = []() { std::cout << "Hello world\n"; };
		func();
	}

	inline void lambdaBasicExample()
	{
		auto func = []()
		{
			for (int i = 0; i < 3; i++)
			{
				cout << i + 1 << " ";
			}
			cout << '\n';
		};
		cout << "lets say 123: \n";
		func();
	}

	inline void lambdaPassParameter()
	{
		//return value
		auto timesTwo = [](int value) -> int { return value * 2; };
		cout << "4 : " << timesTwo(2) << '\n';
		//pass value and function
		int five = 5;

		//auto timesTwo would actually be: void (*timesTwo)(int) as a function parameter.
		auto func = [](int five, auto timesTwo)
		{
			cout << timesTwo(five) << '\n';
		};

		func(five, timesTwo);
	}

	inline void lambdaSTL()
	{
		//do this
		vector<int>	vec;
		vec.push_back(1);
		vec.push_back(2);

		for_each(vec.begin(), vec.end(), [](int val) { cout << val; });
		cout << '\n';

		//instead of this
		//vector<int> v;
		//v.push_back(1);
		//v.push_back(2);
		//
		//for (auto itr = v.begin(), end = v.end(); itr != end; itr++)
		//{
		//	cout << *itr;
		//}
	}

	inline void start()
	{
		lambdaHelloWord();
		lambdaBasicExample();
		lambdaPassParameter();
	}
}