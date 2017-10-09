#pragma once

#include "RedBlackTree.h"
#include "AVLTree.h"
#include <assert.h>
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
		std::random_device rng;
		std::mt19937 urng(rng());
		std::shuffle(myvector.begin(), myvector.end(), urng);

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

	struct ValueType
    {
        int data;

        friend std::ostream& operator<< (std::ostream& stream, const ValueType& value)
        {
            stream << value.data;
            return stream;
        }
    };

    struct KeyType
    {
        int data;

        friend bool operator<(const KeyType& key1, const KeyType& key2)
        {
            return key1.data < key2.data;
        }
        friend bool operator>(const KeyType& key1, const KeyType& key2)
        {
            return key1.data > key2.data;
        }
        friend std::ostream& operator<< (std::ostream& stream, const KeyType& key)
        {
            stream << key.data;
            return stream;
        }
    };

    inline void AVLTreeWorkTest()
    {
        // Test creation
        {
            AVLTree<int, int> tree;

            assert(tree.PrintPreOrder() == "");
        }
        // Test insertion
        {
            AVLTree<int, int> tree;
            tree.Insert(1, 0);
            tree.Insert(1, 0);
            tree.Insert(2, 0);
            tree.Insert(3, 0);
            tree.Insert(4, 0);
            tree.Insert(2, 0);

            assert(tree.PrintPreOrder() == "(2, 0) (1, 0) (1, 0) (3, 0) (2, 0) (4, 0) ");
        }
        // Test deletion existing
        {
            AVLTree<int, int> tree;
            tree.Insert(1, 0);
            tree.Insert(2, 0);
            tree.Insert(3, 0);
            tree.Delete(1);
            tree.Delete(2);
            tree.Delete(3);

            assert(tree.PrintPreOrder() == "");
        }
        // Test deletion non-existing
        {
            AVLTree<int, int> tree;
            tree.Insert(1, 0);
            tree.Insert(2, 0);
            tree.Insert(3, 0);
            tree.Delete(4);

            assert(tree.PrintPreOrder() == "(2, 0) (1, 0) (3, 0) ");
        }
        // Test search existing
        {
            AVLTree<int, int> tree;
            tree.Insert(1, 1);
            tree.Insert(2, 2);
            tree.Insert(3, 3);

            assert(tree.Has(1));
            assert(tree.Get(1) == 1);
            assert(tree.Has(2));
            assert(tree.Get(2) == 2);
            assert(tree.Has(3));
            assert(tree.Get(3) == 3);
        }
        // Test search non-existing
        {
            AVLTree<int, int> tree;
            tree.Insert(1, 1);
            tree.Insert(2, 2);
            tree.Insert(3, 3);

            assert(!tree.Has(4));
        }
        // Test user defined value type
        {
            AVLTree<int, ValueType> tree;
            tree.Insert(1, { 1 });
            tree.Insert(2, { 2 });
            tree.Insert(3, { 3 });
            tree.Delete(1);

            assert(tree.PrintPreOrder() == "(2, 2) (3, 3) ");
            assert(!tree.Has(1));
            assert(tree.Has(2));
            assert(tree.Has(3));
            assert(!tree.Has(4));
        }
        // Test user defined key type
        {
            AVLTree<KeyType, int> tree;
            tree.Insert({ 1 }, 1);
            tree.Insert({ 2 }, 2);
            tree.Insert({ 3 }, 3);
            tree.Delete({ 1 });

            assert(tree.PrintPreOrder() == "(2, 2) (3, 3) ");
            assert(!tree.Has({ 1 }));
            assert(tree.Has({ 2 }));
            assert(tree.Has({ 3 }));
            assert(!tree.Has({ 4 }));
        }
	}

	inline void start()
	{
		RedBlackTreeWorkTest();
		AVLTreeWorkTest();
	}
}