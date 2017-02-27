#include "Rectangle.h"
#include "Square.h"

Rectangle::Rectangle()
{
	width = 1;
	height = 2;
}

Rectangle::~Rectangle()
{
}

void Rectangle::Print() const
{
	cout << width << " " << height << endl;
}

void Rectangle::SetSide(Square side)
{
	width = side.side;
	height = side.side;
}
