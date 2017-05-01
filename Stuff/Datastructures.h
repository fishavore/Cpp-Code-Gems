#pragma once

#include "RedBlackTree.h"
#include <random>

namespace Datastructures
{
	inline void RedBlackTreeWorkTest()
	{
		struct A
		{
			char c = 'A';
			int val = 5;
		}exampleStruct;

		RedBlackTree<A> rbt;
		//random
		std::random_device rd;
		std::mt19937 mt(rd());
		
		const int CAP = 500;
		std::uniform_int_distribution<int> dist(1, CAP);
		
		std::vector<int> myvector;
		for (int i = 1; i<CAP; ++i) myvector.push_back(i);
		std::random_shuffle(myvector.begin(), myvector.end());

		for(auto i : myvector)
			rbt.insert(exampleStruct, i);
		
		for (auto i : myvector)
			rbt.remove(i);

		/*
		for (int i = 0; i < CAP; i++)
		{
			int val = dist(mt);
			arr.push_back(val);
			rbt.insert(exampleStruct, val);
		}*/

		rbt.printInOrder();


	}

	inline void main()
	{
		RedBlackTreeWorkTest();
	}
}