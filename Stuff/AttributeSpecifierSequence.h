#pragma once


//TODO: Much of this stuff is not actually working yet in VS2017.

/*
[[noreturn]]
[[carries_dependency]]

C++14:
[[deprecated]]
[[deprecated("reason")]]

C++17:
[[fallthrough]]
[[nodiscard]]
[[maybe_unused]]

*/

namespace AttributeSpecifierSequence
{
	//Soon implemented in Visual studio 2017.
	//[[nodiscard]] int get_value1()
	//{
	//	return 42;
	//}

	inline void start()
	{
		// warning: ignoring return value of function declared with 'nodiscard' attribute
		//get_value1();
	}
}