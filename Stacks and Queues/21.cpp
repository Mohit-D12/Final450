// Implement Stack and Queue using Deque
// https://www.geeksforgeeks.org/implement-stack-queue-using-deque/

#include <bits/stdc++.h>
using namespace std;


class Stack : public deque<int>
{
  public:

	void push(int element) {
		push_back(element);
	}

	void pop() {
		pop_back();
	}
};

class Queue : public deque<int>
{
  public:
	void enqueue(int element) {
		push_back(element);
	}

	void dequeue() {
		pop_front();
	}
};