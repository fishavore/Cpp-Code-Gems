#pragma once

#include <iostream>

/*

Basic short summary: 
enum is essentially just an int.

enum class is an int but is treated as its own type. enum class Owl is the type Owl.

*/


//source http://stackoverflow.com/a/18335862/2359879

namespace EnumEnumclass
{
	enum Color { red, green, blue };                    // plain enum 
	enum Card { red_card, green_card, yellow_card };    // another plain enum 
	enum class Animal { dog, deer, cat, bird, human };  // enum class
	enum class Mammal { kangaroo, deer, human };        // another enum class

	inline void start()
	{
		using namespace std;

		//Regular enums:
		// examples of bad use of plain enums:
		Color color = Color::red;
		Card card = Card::green_card;

		int num = color;    // no problem

		if (color == Card::red_card) // no problem (bad)
			cout << "bad\n";

		if (card == Color::green)   // no problem (bad)
			cout << "bad\n";


		//Enum class:
		// examples of good use of enum classes (safe)
		Animal a = Animal::deer;
		Mammal m = Mammal::deer;

		/*
		int num2 = a;   // error
		if (m == a)         // error (good)
			cout << "bad\n";

		if (a == Mammal::deer) // error (good)
			cout << "bad\n";
		*/
		
		if ((int)a == (int)m)
			cout << "works tho\n";
	}
}