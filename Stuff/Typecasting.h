#pragma once

#include <iostream>
#include <string>

//TODO: reinterpret_cast

/*

The main reason is that classic C casts make no distinction between what we call static_cast<>(), 
reinterpret_cast<>(), const_cast<>(), and dynamic_cast<>(). These four things are completely different.

A static_cast<>() is usually safe. There is a valid conversion in the language, or an appropriate 
constructor that makes it possible. The only time it's a bit risky is when you cast down to an 
inherited class; you must make sure that the object is a actually the descendant that you claim it is, 
by means external to the language (like a flag in the object). A dynamic_cast<>() is safe as long as 
the result is checked (pointer) or a possible exception is taken into account (reference).

A reinterpret_cast<>() (or a const_cast<>()) on the other hand is always dangerous. You tell the 
compiler: "trust me: I know this doesn't look like a foo (this looks as if it isn't mutable), but it is".

Source: https://stackoverflow.com/a/103868/2359879

*/

namespace TypeCasting
{
	//Basic
	inline void basics()
	{
		float fVar = 15.5f;
		int iVar = 15;
		std::cout << "float casted as int: " << int(fVar) << '\n';
		std::cout << "int casted as float: " << float(iVar) << '\n';
	}

	////////////////////////////////////////////////////////////////////////////////////
	//explicitConversion

	class CDummy {
		float i, j;
	};

	class CAddition {
		int x, y;
	public:
		CAddition(int a, int b) { x = a; y = b; }
		int result()const { return x + y; }
		void setValue(int a, int b) { x = a; y = b; }
	};

	inline void explicitConversion()
	{
		CDummy d;
		CAddition * padd;
		padd = (CAddition*)&d;
		//padd->setValue(1, 1);
		std::cout << padd->result() << '\n';
	}

	////////////////////////////////////////////////////////////////////////////////////
	//Setup - static_cast

	struct A
	{
		int m = 0;
		void hello() const {
			std::cout << "Hello world, this is A!\n";
		}
	};
	struct B : A
	{
		void hello() const {
			std::cout << "Hello world, this is B!\n";
		}
	};

	// static_cast
	inline void staticCast()
	{
		B b;
		A& ar = b; //upcast via implicit conversion
		ar.hello();
		B& another_d = static_cast<B&>(ar); //downcast
		//B& dd = (B&)ar; works as well.
		another_d.hello();
	}

	////////////////////////////////////////////////////////////////////////////////////
	// Setup - dynamic_cast

	class Base
	{
		int aStuff = 1;
	public:
		Base() {}
		virtual ~Base() = 0 {}
		virtual void hello() const {
			std::cout << "Hello world, this is Base!\n";
		}
	};
	class ChildA : public Base
	{
		int bStuff = 2;
	public:
		ChildA() {}
		~ChildA() {}
		void hello() const {
			std::cout << "Hello, this is ChildA!\n";
		}
	};
	class ChildB : public Base
	{
		int cStuff = 3;
	public:
		ChildB() {}
		~ChildB() {}
		void hello() const {
			std::cout << "Hello, this is ChildB!\n";
		}
	};

	//dynamic_cast
	inline void dynamicCast()
	{
		Base* base[2];
		base[0] = new ChildA();
		base[1] = new ChildB();


		ChildA* childAPointer;
		ChildB* childBPointer;
		for (int i = 0; i < 2; i++)
		{
			childAPointer = dynamic_cast<ChildA*>(base[i]);
			childBPointer = dynamic_cast<ChildB*>(base[i]);

			if (childAPointer)
				childAPointer->hello();
			if (childBPointer)
				childBPointer->hello();
			
			childAPointer = nullptr;
			childBPointer = nullptr;
		}

		//cleanup
		for(int i=0; i<2; i++) { delete base[i]; }
	}

	////////////////////////////////////////////////////////////////////////////////////
	// reinterpret_cast

	inline void reinterpretCast()
	{
		//The reinterpret_cast operator changes one data type into another. It should be used to cast between incompatible pointer types. 
		//Source: http://advancedcppwithexamples.blogspot.se/2010/02/reinterpretcast-in-c.html

		int intVal = 22;
		float floatVal = 55.5555f;
		
		//
		//Wont work in this case because floating point format is different
		intVal = reinterpret_cast<int&>(floatVal);
		std::cout << "floatVal reinterpret_cast to intVal = " << intVal << '\n';

		intVal = static_cast<int>(floatVal); //Correct approach
		std::cout << "floatVal static_cast to intVal (correct) = " << intVal <<'\n';

		//Convert int to char
		char c;
		c = reinterpret_cast<char&>(intVal);
		std::cout << "intVal reinterpret_cast to char = " << intVal << '\n';

		//Dangerous to convert from char to int
		char intChar = '5';
		intVal = reinterpret_cast<int&>(intChar);
		std::cout << "Char reinterpret_cast to int" << intVal << '\n'; //outputs: -858993611
	}

	////////////////////////////////////////////////////////////////////////////////////
	// const_cast

	inline void constCast()
	{
		/*
		You are not allowed to const_cast variables that are actually const. 
		This results in undefined behavior. const_cast is used to remove the
		const-ness from references and pointers that ultimately refer to 
		something that is not const.

		Source: https://stackoverflow.com/a/19554871/2359879
		*/
		int i = 0;
		//const int i = 0; //not allowed.
		const int& ref = i;
		const int* ptr = &i;

		const_cast<int&>(ref) = 3;
		*const_cast<int*>(ptr) = 3;
	}

	////////////////////////////////////////////////////////////////////////////////////

	inline void start()
	{
		basics();
		explicitConversion();
		staticCast();
		dynamicCast();
		reinterpretCast();
		constCast();
	}
}