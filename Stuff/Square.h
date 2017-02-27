#pragma once

#include "Rectangle.h"

class Square
{
private:
	friend class Rectangle;
	int side, x, y, z;

public:
	Square(int a, int b);
	~Square();
	int ReturnX();


};
