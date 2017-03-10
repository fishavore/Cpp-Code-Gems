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
	otherValue = val;
}

int Wheel::getOtherValue()
{
	return otherValue;
}
