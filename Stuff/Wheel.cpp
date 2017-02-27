#include "Wheel.h"


Wheel::Wheel()
{
}

Wheel::~Wheel()
{
}



void Wheel::Brand()
{
	cout << "Hjul." << endl;
}

void Wheel::setValue(const int val)
{
	otherValue = val - 1;
}

int Wheel::getOtherValue()
{
	return otherValue;
}
