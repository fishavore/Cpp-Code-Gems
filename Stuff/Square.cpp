#include "Square.h"


Square::Square(int _side, int b) : side(_side), x(b)
{
	//this->side = _side;
}

Square::~Square()
{
}

int Square::ReturnX()
{
	return x;
}