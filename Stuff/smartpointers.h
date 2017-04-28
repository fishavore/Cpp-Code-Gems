#pragma once

#include <memory>
#include <iostream>

//other
#include "Square.h"

//TODO: Make function look better for easier "go back".

namespace SmartPointers
{
	inline void main()
	{
		//auto myobj = std::make_unique<MyClass>(constructor_param1, constructor_param2); // C++14
		//auto myobj = std::unique_ptr<MyClass>(new MyClass(constructor_param1, constructor_param2)); // C++11
		auto mySquare = std::make_unique<Square>(5, 101);
		std::cout << "SmartPointer 1: " << mySquare->ReturnX() << endl;
		//alt.
		std::unique_ptr<Square> mySquare2 = std::make_unique<Square>(5, 102);
		std::cout << "SmartPointer 2: " << mySquare2->ReturnX() << endl;
		//Shared

		auto mySquare3 = std::make_shared<Square>(5, 103);
		std::cout << "SharedPointer 3: " << mySquare3->ReturnX() << endl;
		std::shared_ptr<Square> mySquare4 = mySquare3;
		//alt
		std::cout << "SharedPointer 4: " << mySquare4->ReturnX() << endl;
	}
}