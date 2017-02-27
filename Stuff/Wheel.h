#pragma once

#include "Car.h"


class Wheel : public Car
{
public:
	Wheel();
	~Wheel();
	void Brand();

	void setValue(const int val);
	int getOtherValue();

private:
	int value;
	int otherValue;
};
