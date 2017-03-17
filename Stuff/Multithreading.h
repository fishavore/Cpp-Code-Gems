#pragma once

#include <thread>
#include <iostream>
#include <string>

inline void multiThreading()
{
	struct inputArgs
	{
		int val;
		std::string stringVal;
		long longVal;
		int threadId;
	};
	auto function = [](void* vals)
	{
		inputArgs* input = static_cast<inputArgs*>(vals);
		std::cout << input->threadId<< "\n";
	};

	static const int numThreads = 3;
	std::thread threads[numThreads];


	inputArgs vals;
	vals.val = 1;
	vals.stringVal = "a";
	vals.longVal = 100;
	for (int i = 0; i < numThreads; i++)
	{
		vals.threadId = i+1;
		threads[i] = std::thread(function, &vals);
	}

	for (int i = 0; i < numThreads; i++)
	{
		threads[i].join();
	}
}