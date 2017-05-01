#pragma once

#include "RedBlackTree.h"

namespace Datastructures
{
	inline void RedBlackTreeFunc()
	{
		struct A
		{
			char c = 'A';
			int val = 5;
		}exampleStruct;

		RedBlackTree<A> rbt;

		for (int key : {8, 5, 4, 7, 1, 9, 2, 6, 10, 3})
			rbt.Insert(exampleStruct, key);

		rbt.PrintInOrder();
	}

	inline void main()
	{
		RedBlackTreeFunc();
	}
}