#pragma once

/*

In computer science, a priority queue is an abstract data type which is like a 
regular queue or stack data structure, but where additionally each element has 
a "priority" associated with it. In a priority queue, an element with high 
priority is served before an element with low priority. If two elements have 
the same priority, they are served according to their order in the queue.

While priority queues are often implemented with heaps, they are conceptually 
distinct from heaps. A priority queue is an abstract concept like "a list" or 
"a map"; just as a list can be implemented with a linked list or an array, a 
priority queue can be implemented with a heap or a variety of other methods such 
as an unordered array.

*/

#include <iostream>
#include <queue>
//
#include <vector>

namespace PriorityQueue
{
	inline void print_queue(std::priority_queue<int> q)
	{
		//It is near impossible to return the priority queue as a normal output.
		//You can, but the suggestions are according to other people quite unsafe
		//due to lack of destructors.
		
		//print and pop.
		while (!q.empty()) {
			std::cout << q.top() << " "; // return highest-priority element
			q.pop(); // erase highest-priority element
		}
		std::cout << '\n';
	}

	

	class A
	{
		int val;
	public:
		A()
		{
			std::cout << "Inside A. Constructor with val =" << val << ".\n";
		}
		A(const A& msg)
		{
			std::cout << "Inside const A. Never want to come here. val =" << msg.val << ".\n";
		}
		bool operator()(const A* m1, const A* m2)
		{
			std::cout << "Inside () function.\n";
			std::cout << "m1: " << m1->GetVal() << " m2: " << m2->GetVal()<<"\n";
			return (m1->GetVal() < m2->GetVal());
		}
		void setVal(int input) { std::cout << "inside setVal.\n"; val = input; }
		int GetVal()const { return val; }
		
	};

	struct Compare
	{
		bool operator()(const A* m1, const A* m2) const {
			return m1->GetVal() < m2->GetVal();
		}
	};

	void comparatorPriorityQueue()
	{
		//init
		A* val = new A();
		val->setVal(5);
		std::priority_queue<A*, std::vector<A*>, Compare> pq;
		pq.push(val);

		A* val2 = new A();
		val2->setVal(3);
		pq.push(val2);

		delete val;
		delete val2;
	}

	inline void start()
	{
		std::priority_queue<int> pQueue;
		for (int n : {1, 8, 5, 6, 3, 4, 0, 9, 7, 2})
			pQueue.push(n);

		comparatorPriorityQueue();
	}
}