#pragma once

//According to http://stackoverflow.com/a/19666713/2359879
/*

Summery of video:
in srand(time(NULL)), time has an update frequency of once every second. Which means, if you run the code
fast, 60 fps, you will get 60 equal values. srand takes a 32-bit seed even tho you give it more.
rand()% n : has range of 0-32767. It has shit quality, after a while it will start repeating values.
Modular % gives incorrectly at the very end. As [0,99] gives -> 0, 99. But [32700, 32767] -> [0, 67].

*/

#include <random>
#include <iostream>
#include <algorithm>    // std::random_shuffle

namespace Random
{
	inline void random()
	{
		std::random_device rd;
		std::mt19937 mt(rd()); //mt19937_64 is an alternative.

							   //Double
							   //std::uniform_real_distribution<double> dist(1.0, 10.0);
							   //std::uniform_real_distribution<double> dist(1, std::nextafter(10, DBL_MAX));

							   //Int
		std::uniform_int_distribution<int> dist(1, 10); //Actual range: 1,2,3,4,5,6,7,8,9,10


		for (int i = 0; i<10; ++i)
			std::cout << dist(mt) << ", ";
		std::cout << '\n';
	}

	inline void vectorShuffle()
	{
		std::vector<int> myvector;
		for (int i = 1; i<10; ++i) myvector.push_back(i); // 1 2 3 4 5 6 7 8 9
		std::random_shuffle(myvector.begin(), myvector.end());
		for (auto i : myvector)
			std::cout << i << ' ';
		std::cout << '\n';
	}

	inline void main()
	{
		random();
		vectorShuffle();
	}
}