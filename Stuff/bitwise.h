#pragma once
#include <iostream>

//AND &
//OR |
//XOR ^

namespace Bitwise
{

	inline void bitwiseBasic()
	{
		const int CAP = 10;
		int bitArr[CAP] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };

		for (int i = 0; i < CAP; i++)
		{
			std::cout << (bitArr[i] & 1) << " ";
		}
		std::cout << '\n';
		//outputs 0,1,0,1,0,1,0,1,0,1
		//00
		//01
		//AND => 00

		//01
		//01
		//AND => 01

		for (int i = 0; i < CAP; i++)
		{
			std::cout << (bitArr[i] & 2) << " ";
		}
		std::cout << '\n';
		//outputs 0, 0, 2, 2, 0, 0, 2, 2, 0, 0
		//00
		//10
		//AND => 00

		//01
		//10
		//AND => 00

		//10
		//10
		//AND => 10

		//11
		//10
		//AND => 10

		for (int i = 0; i < CAP; i++)
		{
			std::cout << (bitArr[i] & 3) << " ";
		}
		//outputs 0, 1, 2, 3, 0, 1, 2, 3, 0, 1
		//00
		//11
		//AND => 00

		//01
		//11
		//AND => 01

		//osv...

		std::cout << '\n';
	}

	inline void bitwiseOneBranch()
	{
		enum WeekDays
		{
			Monday = 1,
			Tuesday = 2,
			Wednesday = 4,
			Thursday = 8,
			Friday = 16,
			Saturday = 32,
			Sunday = 64
		}Day;



		//This way we can have one single branch where each
		//enum value represent 1 bit. Wednesday is: 0....0100
		if (Day & (Tuesday | Wednesday | Friday))
		{
			//a 32bit interger can hold 32 values and
			//in a 64bit system, we can hold 64bit.
		}

		//Compare this to using something as this:
		if (Day == Tuesday || Day == Wednesday || Day == Friday)
		{
			//this uses 3 branches rather than 1.
		}
	}

	inline void main()
	{
		bitwiseBasic();
	}
}