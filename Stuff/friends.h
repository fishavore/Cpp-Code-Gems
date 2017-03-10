#pragma once

#include "Rectangle.h"
#include "Square.h"
#include <iostream>

inline void friends()
{
	Rectangle rect;
	rect.Print();
	Square square = Square(5, 99);
	std::cout << "Friends: " << square.ReturnX() << endl;
	rect.SetSide(square);
	rect.Print();
}