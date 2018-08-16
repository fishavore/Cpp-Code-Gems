#pragma once

#include <memory>
#include <iostream>

//other
#include "Square.h"

//TODO: Make function look better for easier "go back".

namespace SmartPointers
{
	void start()
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

		// Examples of working with an array.
		const int size = 10;
		std::unique_ptr<char[]> message = std::unique_ptr<char[]>(new char[size]);
		for (int i=0; i<size; i++)
		{
			message[i] = 'A';
		}
		char* check = message.get();
		check[0] = 'O';
		message[1] = 'K';
		for (int i = 0; i<2; i++)
		{
			std::cout << message[i];
		}

		message.reset();
		const int messageSize = 2;
		message = std::unique_ptr<char[]>(new char[messageSize]);
		for (int i = 0; i<messageSize; i++)
		{
			message[i] = 'B';
		}

		//Combined
		{
			struct MyStruct
			{
				int five;
				int lol;
				int heh;
			};

			MyStruct* variable = new MyStruct;
			variable->five = 5;
			variable->lol = 5;
			variable->heh = 5;

			std::unique_ptr<MyStruct> smartVariable(variable);
		}
	}
}