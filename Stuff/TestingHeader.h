#pragma once

#include "Timer.h"
#include <iostream>
#include <vector>
#include <map>
#include "BreakAtAccess.h"

inline void TestStart()
{
	std::cout << "TestStart: \n";

	bool found = false;
	int incr = 0;

	int val = -16;
	unsigned long val2 = (unsigned long)val;
	std::cout << val2 << std::endl;
	int val3 = 0xFFFFFFFF;

	//Timer timer(Timer::TimeFrequency::Microseconds);
	//timer.StartClock();
	//timer.StopClock();
	//std::cout << "Testing time: " << timer.GetStopClock() << '\n';
}