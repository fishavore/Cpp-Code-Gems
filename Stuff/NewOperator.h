#pragma once

#include <iostream>
#include <string>

// more info on : http://en.cppreference.com/w/cpp/memory/new/operator_new
//TODO: New operator, overloading new etc.

namespace NewOperator
{
	class A
	{
	private:
		int intVar;
	public:
		A()
		{
			intVar = 1;
		}
		~A() {};
		int getVar()const { return intVar; };
	};

	inline void withOrWithoutParanthesis()
	{
		A* paranthesis = new A();
		A* noParanthesis = new A;

		cout << "Paranthesis: " << paranthesis->getVar() << '\n';
		cout << "No Paranthesis: " << noParanthesis->getVar() << '\n';

		/*
		If used on a struct/class with a user-defined constructor, there is no difference. 
		If called on a trivial struct/class (e.g. struct Thing { int i; };) then new Thing; 
		is like malloc(sizeof(Thing)); whereas new Thing(); is like calloc(sizeof(Thing)); 
		- it gets zero initialized.		
		*/
	}

	inline void start()
	{
		using namespace std;
		withOrWithoutParanthesis();
	}
}