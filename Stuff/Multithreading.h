#pragma once

#include <thread>
#include <iostream>
#include <string>
#include <mutex>

namespace Multithreading
{
	inline void basicExample()
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
			std::cout << input->threadId << '\n';
		};

		static const int numThreads = 3;
		std::thread threads[numThreads];


		inputArgs vals;
		vals.val = 1;
		vals.stringVal = "a";
		vals.longVal = 100;
		for (int i = 0; i < numThreads; i++)
		{
			vals.threadId = i + 1;
			threads[i] = std::thread(function, &vals);
		}

		for (int i = 0; i < numThreads; i++)
		{
			threads[i].join();
		}
	}

	inline void mutexLock()
	{
		//Input value
		struct threadInfo
		{
			std::mutex* mutex;
			int id;
		};

		//Thread
		auto threadFunction = [](void* vals)
		{
			threadInfo* input = static_cast<threadInfo*>(vals);
			input->mutex->lock();
			std::cout << "Thread ID: " << input->id << '\n';
			input->mutex->unlock();
		};
		

		std::mutex mtx;			
		const int CAP = 10;
		std::thread threads[CAP];
		threadInfo tInfo[CAP];
		for (int i = 0; i < CAP; i++)
		{
			tInfo[i].id = i + 1;
			tInfo[i].mutex = &mtx;
			threads[i] = std::thread(threadFunction, &tInfo[i]);
		}

		for (auto& thread : threads)
		{
			thread.join();
		}
	}

	inline void main()
	{
		basicExample();
		mutexLock();
	}
}