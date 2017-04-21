#pragma once
#include <iostream>

namespace ConstExamples
{

	inline void main()
	{
		struct A
		{
			int value;
			A() {};
			~A() {};
			int getValue()const
			{
				return value;
			}
			void setValue(const int input)
			{
				value = input;
			}
		}A;

		A.setValue(5);
		std::cout << "5: " << A.getValue() << "\n";

		// This is a constant pointer to a constant area.
		const float area = 35.78f;
		const float* const pointer_area = &area;

		//You cannot create a static const int array[] with constant content. 
		// There are several methods as work arounds but they had problems. 
		// Either the data was unsafe or they were still dynamic input. All I 
		//could think of was to just make an enum/struct of some sort as an
		//alternative.


		//Whether the constants are defined with enum, const, or #define
		//makes no difference for the performance.

	}
}