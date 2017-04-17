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

	inline void main()
	{
		std::priority_queue<int> pQueue;
		for (int n : {1, 8, 5, 6, 3, 4, 0, 9, 7, 2})
			pQueue.push(n);
	}
}