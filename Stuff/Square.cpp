#include "Square.h"


Square::Square(int _side, int b) : side(_side), x(b)
{
}

Square::~Square()
{
}

int Square::ReturnX()
{
	return x;
}