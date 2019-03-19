#pragma once

#include <map>

#include <iostream>
#include <string>

namespace Map
{
	void map_copy(std::map<int, std::string>&& map_)
	{
		std::map<int, std::string> thirdMap;
		thirdMap[1] = "Rudolf";
		thirdMap[2] = "Red";
		map_.clear();
		map_.insert(thirdMap.begin(), thirdMap.end());
	}

	void start()
	{
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
		//
		//map
		std::map<int, std::string> secMap;
		secMap[1] = "Test1";
		secMap[2] = "Test2";
		for (int i = 1; i < 3; i++)
		{
			std::cout << secMap.at(i) << ' '; //Test1 Test2
		}
		map_copy(std::move(secMap));
		for (int i = 1; i < secMap.size() + 1; i++)
		{
			std::cout << secMap.at(i) << ' '; //Rudolf Red
		}
	}
}