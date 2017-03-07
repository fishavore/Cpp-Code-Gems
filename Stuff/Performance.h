#pragma once

inline float LookUpDoSomething(int i)
{
	static float list[] = { 1.1, 0.3, -2.0, 4.4, 2.5 };
	return list[i];
}

inline void LookupTable()
{
	//It is often preferable to make a lookup - table static.Example:
	// Example 7.1

	float value = LookUpDoSomething(0);

	//The advantage of using static here is that the list does not need to be initialized when the
	//function is called.The values are simply put there when the program is loaded into memory.
	//If the word static is removed from the above example, then all five values have to be put
	//into the list every time the function is called.This is done by copying the entire list from
	//static memory to stack memory.Copying constant data from static memory to the stack is a
	//waste of time in most cases, but it may be optimal in special cases where the data are used
	//many times in a loop where almost the entire level - 1 cache is used in a number of arrays
	//that you want to keep together on the stack.
}