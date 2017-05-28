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

	/*
	
	Malloc:
	TLDR: Do not use.
	https://stackoverflow.com/a/184540
	
	
	The new keyword is the C++ way of doing it, and it will ensure that your type will have 
	their constructor called. The new keyword is also more type safe whereas malloc is not 
	typesafe at all.

	The only way I could think that would be beneficial to use malloc would be if you needed 
	to change the size of your buffer of data. The new keyword does not have an analogous 
	way like realloc. The realloc function might be able to extend the size of a chunk of 
	memory for you more efficiently.

	It is worth mentioning that you cannot mix new/free and malloc/delete.

	*/

	inline void start()
	{
		using namespace std;
		withOrWithoutParanthesis();
	}
}