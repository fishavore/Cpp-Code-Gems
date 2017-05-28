#pragma once

#include <iostream>
#include <string>

//TODO: Example 2.

/*
if you are unsure of the type you are sending in for a function you can generalize it with
a typename function. It fits perfectly when you have types/classes that works similarily.
You may have 10 classes that all have ->work(). So, whenever that specific class is used,
you use a general typename function rather than overloading for each method.
*/

namespace TypenameOperator
{
	//Setup
	class A
	{
		int var;
	public:
		A() { var = 5; };
		void work() { var++; };
		int getVar() { return var; }
	};

	//Example 1.
	template<typename TheType>
	void print(TheType var)
	{
		std::cout << "Inside typename function: " << var << '\n';
	}

	////////////////////////////////////////////////////
	//Example 2.

	/*
	template<typename TheType>
	void func(TheType var)
	{
		if (std::type_info)
		{
			typename TheType::A variable; // works!
			variable = var;

			variable.work();
			std::cout << "Inside typename function: " << variable.getVar() << '\n';
		}
	}
	*/

	////////////////////////////////////////////////////

	inline void start()
	{
		//Example 1:
		print<int>(5);
		print<std::string>("Hello");
	}
}