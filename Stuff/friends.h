#pragma once

#include "Rectangle.h"
#include "Square.h"
#include <iostream>


namespace Friends
{
	inline void start()
	{
		class Rectangle rect;
		rect.Print();
		Square square = Square(5, 99);
		std::cout << "Friends: " << square.ReturnX() << endl;
		rect.SetSide(square);
		rect.Print();
	}
}