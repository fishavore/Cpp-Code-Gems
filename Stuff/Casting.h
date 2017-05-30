#pragma once

#include <iostream>
#include <string>

namespace Casting
{
	//Basic
	inline void basics()
	{
		float fVar = 15.5f;
		int iVar = 15;
		std::cout << "float casted as int: " << int(fVar) << '\n';
		std::cout << "int casted as float: " << float(iVar) << '\n';
	}

	////////////////////////////////////////////////////////////////////////////////////
	//explicitConversion

	class CDummy {
		float i, j;
	};

	class CAddition {
		int x, y;
	public:
		CAddition(int a, int b) { x = a; y = b; }
		int result()const { return x + y; }
		void setValue(int a, int b) { x = a; y = b; }
	};

	inline void explicitConversion()
	{
		CDummy d;
		CAddition * padd;
		padd = (CAddition*)&d;
		//padd->setValue(1, 1);
		std::cout << padd->result() << '\n';
	}

	////////////////////////////////////////////////////////////////////////////////////
	// dynamic_cast

	////////////////////////////////////////////////////////////////////////////////////
	// reinterpret_cast
	
	////////////////////////////////////////////////////////////////////////////////////
	// static_cast

	////////////////////////////////////////////////////////////////////////////////////
	// const_cast

	////////////////////////////////////////////////////////////////////////////////////

	inline void start()
	{
		basics();
		explicitConversion();
	}
}