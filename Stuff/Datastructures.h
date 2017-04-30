#pragma once

#include "RedBlackTree.h"

namespace Datastructures
{
	inline void RedBlackTreeFunc()
	{
		RedBlackTree<int> rbt;

		for (int n : {5, 4, 7, 1, 9, 2, 6, 10})
			rbt.Insert(n);

		rbt.PrintInOrder();
	}

	inline void main()
	{
		RedBlackTreeFunc();
	}
}