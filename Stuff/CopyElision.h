#pragma once

#include <iostream>
#include <string>
#include <vector>

//Source: https://stackoverflow.com/a/12953129/2359879

/*

Copy elision is an optimization implemented by most compilers to prevent extra 
(potentially expensive) copies in certain situations. It makes returning by value 
or pass-by-value feasible in practice (restrictions apply).

*/

namespace CopyElision
{
	struct C {
		C() { std::cout << "Constructor.\n"; }
		C(const C&) { std::cout << "Copy constructor.\n"; }
	};

	C f() {
		return C();
	}

	inline void start()
	{
		std::cout << "Inside CopyElision.\n";
		C obj = f();

		/*
		
		Depending on the compiler and settings the following outputs are all valid:
		//
		Hello World!
		A copy was made.
		A copy was made.
		//
		Hello World!
		A copy was made.
		//
		Inside CopyElision.\n
		\\

		What this means:
		copy elision can be applied even if copying/moving the object has side-effects.

		This also means fewer objects can be created, so you also can't rely on a specific 
		number of destructors being called. You shouldn't have critical logic inside 
		copy/move-constructors or destructors, as you can't rely on them being called.

		If a call to a copy or move constructor is elided, that constructor must still 
		exist and must be accessible. This ensures that copy elision does not allow 
		copying objects which are not normally copyable, e.g. because they have a private 
		or deleted copy/move constructor.
		*/
	}
}