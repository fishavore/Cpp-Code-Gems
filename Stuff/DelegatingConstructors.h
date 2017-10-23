#pragma once

#include <iostream>

/*
	TLDR:
	Overloading constructors so they utilize other constructors to reduce code and what not.

*/

namespace DelegatingConstructors
{
	struct A {
	public:
		int max;
		int min;
		int middle;

		A(int my_max)
		{
			max = my_max > 0 ? my_max : 5; //executed first
		}
		A(int my_max, int my_min) : A(my_max)
		{
			min = my_min > 0 && my_min < max ? my_min : 1; //executed second
		}
		A(int my_max, int my_min, int my_middle) : A(my_max, my_min)
		{
			middle = my_middle < max && my_middle > min ? my_middle : 5; //executed third
		}
	};

	void start()
	{

		A c(3, 1, 2);
		std::cout << "Min: " << c.min << " Middle: " << c.middle << " Max: " << c.max << '\n'; //outputs: 1,2,3
	}
}