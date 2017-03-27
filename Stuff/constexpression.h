#pragma once

#include <iostream>

//Useless other examples that you could do... Const expr feels like it's designed for
//the use of Templates. Basically, when you are unsure of the type on the input value
//you can still perform task optimally.
// https://arne-mertz.de/2017/03/constexpr-additions-c17/

inline constexpr int square(int x) //returns const expression
{
	return x*x;
}

inline void constexpression()
{
	int array[square(2)];
	for (int i = 0; i < 4; i++)
	{
		array[i] = i;
		std::cout << array[i] << " ";
	}
	std::cout << "\n";
}

inline void constexpressionIf()
{
	struct A
	{
		int aVal;
		A() {};
		A(int input) : aVal(input) {};
		int getVal()const { return aVal; }
	};

	struct B : A
	{
		int bVal;
		B(int input) : bVal(input) {};
		int getVal()const { return bVal; }
	};

	struct C : A
	{
		int cVal;
		C(int input) : cVal(input) {};
		int getVal()const { return cVal; }
	};


	A* base[2];
	base[0] = new B(2);
	base[1] = new C(3);


	delete base[0];
	delete base[1];
}