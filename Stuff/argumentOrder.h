#pragma once

#include <iostream>

namespace Other
{
	namespace ArgumentOrder
	{
		inline void argumentOrder()
		{
			///////////////////////////////////////////
			//setup for example
			auto returnFunc = []() -> bool
			{
				std::cout << "First comparison. \n";
				return true;
			};
			auto returnFunc2 = []() -> bool
			{
				std::cout << "Second comparison. \n";
				return true;
			};
			auto returnFunc3 = []() -> bool
			{
				std::cout << "Third comparison.\n";
				return true;
			};
			///////////////////////////////////////////
			//Example:
			///////////////////////////////////////////

			if (returnFunc() && returnFunc2() && returnFunc3())
			{
				std::cout << "Arguments are read from left to right. \n";
			}

			//This means that depending on which operator you use. Say &&, you want
			//to have the function that will return false most likely first.
			//Another way of looking at it is to have the most expensive function
			//last (to the right).

			//////////////////////////////////////////////////////////////////////
			//setup 2
			auto func = []() -> int
			{
				std::cout << "First func. \n";
				return 1;
			};
			auto func2 = []() -> int
			{
				std::cout << "Second func. \n";
				return 2;
			};
			////////////////////////////////////////////////////////////////////////
			//Example 2
			std::cout << "Functions are read from left to right as well. \n";
			int d = func() + func2();
		}

		inline void assignmentOrder()
		{
			int a, b, c;
			a = b = c = 5;
			cout << a << " " << b << " " << c << "\n";

			a = 1;
			b = 2;
			c = 3;

			a = b = c;
			cout << "Assignment operators works from right to left. " << a << "\n";
		}

		inline void main()
		{
			argumentOrder();
			assignmentOrder();
		}
	}
}