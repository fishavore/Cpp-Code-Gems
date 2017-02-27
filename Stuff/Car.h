#pragma once

#include <iostream>
#include <string>
using namespace std;

class Car
{
public:
	Car();
	~Car();
	void Print();
	virtual void Brand() = 0;

private:

};
