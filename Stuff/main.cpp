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


#include "Polymorphism.h"
#include "STDArray.h"
#include "constExamples.h"
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
#include "Union.h"
#include "Datastructures.h"
#include "Random.h"
#include "StringManipulation.h"
#include "enumenumclass.h"

#include "TestingHeader.h"

#include "Timer.h"
#include <memory>



int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	//Polymorphism
	{
		Polymorphism::main();
	}

	//Friend class
	{
		Friends::main();
	}

	//Smart pointers
	{
		SmartPointers::main();
	}

	//std array
	{
		StdArray::main();
	}

	//const check
	{
		ConstExamples::main();
	}

	//rvalue reference
	{
		RValueReference::main();
	}

	//constexpr
	{
		ConstExpression::main();
	}

	//Lambda
	{
		Lambda::main();
	}

	//bitoperators
	{
		Bitwise::main();
	}

	//look up table
	{
		LookupTable::main();
	}

	//Other - Argument order.
	{
		Other::ArgumentOrder::main();
	}

	//Multithreading
	{
		Multithreading::main();
	}

	//PriorityQueue
	{
		PriorityQueue::main();
	}

	//Paradox Interactive Path finding
	{
		Paradox::main();
	}

	//Union keyword
	{
		Union::main();
	}

	//DataStructures
	{
		Datastructures::main();
	}

	//Random
	{
		Random::main();
	}
	
	//String manipulation
	{
		StringManipulation::main();
	}

	//enum / enumclass
	{
		EnumEnumclass::main();
	}

	//Tests
	{
		TestStart();
	}

	system("pause");
	return 0;
}