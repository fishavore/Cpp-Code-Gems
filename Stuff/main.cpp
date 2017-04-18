/*
////////////////////////////////////////////////////////////////////////////////////

This solution was created in order to keep notes about optimisations, tips,
tricks and other various things that could be useful one day. Micro-optimisations
usually isn't necessary in most ways but to be a better programmer, it certainly
wouldn't hurt to know them. I like to believe that it is better to know all the
unnecessary stuff in order to know when *not* to use them. Good code isn't the 
coolest syntax on the block but the one that is exactly what you were looking for.

////////////////////////////////////////////////////////////////////////////////////
*/




#include <iostream>
#include <string>
using namespace std;

#include "Wheel.h"
#include "Seat.h"

#include "Rectangle.h"
#include "Square.h"

#include "rvaluereference.h"
#include "lambdaFuncs.h"
#include "bitwise.h"
#include "lookupTable.h"
#include "constexpression.h"
#include "constExamples.h"
#include "smartpointers.h"
#include "friends.h"
#include "argumentOrder.h"
#include "Multithreading.h"
#include "PriorityQueue.h"
#include "paradoxPathfinding.h"

#include "TestingHeader.h"

#include "Timer.h"
#include <memory>
#include <array>



int main()
{
	//Polymorphism
	{
		Car* s = nullptr;
		Car* w = nullptr;

		s = new Seat();
		w = new Wheel();

		((Seat*)s)->Print();
		((Wheel*)w)->Print();

		delete s;
		delete w;
	}

	//Friend class
	{
		friends();
	}

	//Smart pointers
	{
		smartpointers();
	}

	//std array
	{
		const int CAP = 5;
		std::array<int, CAP> nummer;
		for (int i = 0; i < CAP; i++)
		{
			nummer[i] = i + 1;
		}
		for (auto i : nummer)
		{
			cout << i << endl;
		}
	}

	//const check
	{
		constExamples();
	}

	//rvalue reference
	{
		rvaluereference();
	}

	//constexpr
	{
		constexpression();
	}

	//Lambda
	{
		lambdaHelloWord();
		lambdaBasicExample();
		lambdaPassParameter();
	}

	//bitoperators
	{
		bitwiseBasic();
	}

	//look up table
	{
		lookupTable();
	}

	//Other - Argument order.
	{
		argumentOrder();
		assignmentOrder();
	}

	//Multithreading
	{
		multiThreading();
	}

	//PriorityQueue
	{
		PriorityQueue::main();
	}

	//Paradox Interactive Path finding
	{
		Paradox::main();
	}

	//Tests
	{
		TestStart();

	}

	system("pause");
	return 0;
}