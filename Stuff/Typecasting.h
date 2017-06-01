#pragma once

#include <iostream>
#include <string>

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
	//Setup

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

	////////////////////////////////////////////////////////////////////////////////////
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
	// reinterpret_cast
	
	////////////////////////////////////////////////////////////////////////////////////
	// dynamic_cast


	////////////////////////////////////////////////////////////////////////////////////
	// const_cast

	////////////////////////////////////////////////////////////////////////////////////

	inline void start()
	{
		basics();
		explicitConversion();
		staticCast();
	}
}