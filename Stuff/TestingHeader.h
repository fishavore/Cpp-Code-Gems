#pragma once

#include "Timer.h"
#include <iostream>

enum TestCommMsg
{
	var1,
	var2,
	var3,
	var4,
	var5,
	var6,
	var7,
	var8,
	var9,
	var10,
	var11,
	var12,
	var13,
	var14,
	var15,
	var16,
	var17,
	var18,
	var19,
	var20,
	var21,
	var22,
	var23
};

inline bool TestFunction1(int messageTag)
{
	if (
		(messageTag == var1) ||
		(messageTag == var2) ||
		(messageTag == var3) ||
		(messageTag == var4) ||
		(messageTag == var5) ||
		(messageTag == var6) ||
		(messageTag == var7) ||
		(messageTag == var8) ||
		(messageTag == var9) ||
		(messageTag == var10) ||
		(messageTag == var11) ||
		(messageTag == var12) ||
		(messageTag == var13) ||
		(messageTag == var14) ||
		(messageTag == var15) ||
		(messageTag == var16) ||
		(messageTag == var17) ||
		(messageTag == var18) ||
		(messageTag == var19) ||
		(messageTag == var20) ||
		(messageTag == var21) ||
		(messageTag == var22) ||
		(messageTag == var23)
		)
	{
		return true;
	}
	else
	{
		return false;
	}
}

inline bool TestFunction2(int messageTag)
{
	switch (messageTag)
	{
	case var1:
	case var2:
	case var3:
	case var4:
	case var5:
	case var6:
	case var7:
	case var8:
	case var9:
	case var10:
	case var11:
	case var12:
	case var13:
	case var14:
	case var15:
	case var16:
	case var17:
	case var18:
	case var19:
	case var20:
	case var21:
	case var22:
	case var23:
		return true;
		break;
	default:
		return false;
		break;
	}
}

inline bool TestFunction3(int messageTag)
{
	static const int check[] =
	{
		var1,
		var2,
		var3,
		var4,
		var5,
		var6,
		var7,
		var8,
		var9,
		var10,
		var11,
		var12,
		var13,
		var14,
		var15,
		var16,
		var17,
		var18,
		var19,
		var20,
		var21,
		var22,
		var23
	};
	for (int i = 0; i < 23; i++)
	{
		if (check[i] == messageTag)
			return true;
		else
			return false;
	}
	return false;
}

inline void TestStart()
{
	std::cout << "TestStart: \n";
	
	bool found = false;
	int incr = 0;

	while (!found)
	{
		incr++;
		if (incr == 5)
			break;
		if (incr == 8)
			found = true;
	}

}