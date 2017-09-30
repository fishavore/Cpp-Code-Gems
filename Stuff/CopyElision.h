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

/*
	Author note: I encountered this issue in a rather unexpectedly once. I was tasked to fix a bug which previously had
	a strange implementation of the copy constructor. I started investigating and found that if implementated correctly
	the copy constructor got called	without being directly called by me. It got called by a priorityqueue comparison method. 
	This had major issues as this additional call was uninitialized.
	Think about that for a seconds. This means that pointers are not "nullptr" that can be checked or be checked against
	objects. You can easily crash and as it is compiler based error, you might not be aware of the issue. If you or your
	company use a build computer with different compilers, that build might be the only one with the error.
	TLDR: Be careful of copy constructors.
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
		Inside CopyElision.
		Copy constructor.
		Copy constructor.
		//
		Inside CopyElision.
		Copy constructor.
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