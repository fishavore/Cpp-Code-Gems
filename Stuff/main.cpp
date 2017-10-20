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
#include "Union.h"
#include "Datastructures.h"
#include "Random.h"
#include "StringManipulation.h"
#include "enumenumclass.h"
#include "DebugRelease.h"
#include "TryCatch.h"
#include "DeleteNullptr.h"
#include "NewOperator.h"
#include "TypenameOperator.h"
#include "TypeCasting.h"
#include "PreprocessorDefinition.h"
#include "CopyElision.h"
#include "NumericalLimits.h"
#include "NotCopyable.h"
#include "CompilerVersion.h"
#include "AttributeSpecifierSequence.h"
#include "Tuples.h"
#include "Map.h"
#include "SystemArchitecture.h"
#include "Literals.h"
#include "Algorithms.h"
#include "Functor.h"

#include "TestingHeader.h"

#include "Timer.h"
#include <memory>


int main()
{
	//Memory Leak Detection
	//This line will output memory leak information to output window.
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	
	//Take the value in the paranthesis and insert into this line below.
	//The application will then break at the allocation of the memory 
	//leak which you can trace back through the call stack.
	//_CrtSetBreakAlloc(1072);

	//Polymorphism
	{
		Polymorphism::start();
	}

	//Friend class
	{
		Friends::start();
	}

	//Smart pointers
	{
		SmartPointers::start();
	}

	//std array
	{
		StdArray::start();
	}

	//const check
	{
		ConstExamples::start();
	}

	//rvalue reference
	{
		RValueReference::start();
	}

	//constexpr
	{
		ConstExpression::start();
	}

	//Lambda
	{
		Lambda::start();
	}

	//bitoperators
	{
		Bitwise::start();
	}

	//look up table
	{
		LookupTable::start();
	}

	//Other - Argument order.
	{
		Other::ArgumentOrder::start();
	}

	//Multithreading
	{
		Multithreading::start();
	}

	//PriorityQueue
	{
		PriorityQueue::start();
	}

	//Union keyword
	{
		Union::start();
	}

	//DataStructures
	{
		Datastructures::start();
	}

	//Random
	{
		Random::start();
	}
	
	//String manipulation
	{
		StringManipulation::start();
	}

	//enum / enumclass
	{
		EnumEnumclass::start();
	}

	//Debug / Release
	{
		DebugRelease::start();
	}

	//Try Catch
	{
		TryCatch::start();
	}

	//Delete / Nullptr
	{
		DeleteNullptr::start();
	}

	//New
	{
		NewOperator::start();
	}

	//template typename
	{
		TypenameOperator::start();
	}

	//TypeCasting
	{
		TypeCasting::start();
	}

	//Preprocessor
	{
		PreprocessorDefinition::start();
	}

	//Copy-Elision
	{
		CopyElision::start();
	}

	//Numerical Limits
	{
		NumericalLimits::start();
	}

	//= Delete, Not copyable
	{
		NotCopyable::start();
	}

	//Compiler Version
	{
		CompilerVersion::start();
	}

	//Attribute Specifier Sequence
	{
		AttributeSpecifierSequence::start();
	}

	//Tuples
	{
		Tuples::start();
	}

	//Map
	{
		Map::start();
	}

	//System Architecture
	{
		SystemArchitecture::start();
	}

	//Literals
	{
		Literals::start();
	}

	//Algorithms
	{
		Algorithms::start();
	}
    
	//Functors
	{
		Functor::start();
	}

	//Tests
	{
		TestStart();
	}

	system("pause");
	return 0;
}