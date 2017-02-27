#pragma once

#include <iostream>
#include <string>
using namespace std;


//Friends 
class Square;

class Rectangle
{
public:
	Rectangle();
	~Rectangle();
	void Print()const;
	void SetSide(Square side);

private:
	int width, height;

};
