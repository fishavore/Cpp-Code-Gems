#pragma once

#include <map>
#include <iostream>

//TODO https://www.fluentcpp.com/2018/12/11/overview-of-std-map-insertion-emplacement-methods-in-cpp17/

namespace Map
{
	void start()
	{
		std::map<int, unsigned int> myMap;

		myMap[1] = 1;
		myMap[2] = 2;
		myMap[3] = 3;
		myMap[4] = 4;
		myMap[5] = 5;
		myMap[6] = 6;
		
		for (int i = 1; i < 6; i++)
		{
			std::cout << myMap.at(i) << ' ';
		}

		myMap[2] = 99;

		for (int i = 1; i < 6; i++)
		{
			std::cout << myMap.at(i) << ' ';
		}

		std::cout << '\n';

	}
}