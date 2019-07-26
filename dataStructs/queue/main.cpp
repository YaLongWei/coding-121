#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

#include "Queue.cpp"
#include "LoopQueue.cpp"
#include "LinkedListQueue.cpp"

string IntToStirng(int n)
{
	return to_string(n);
}

void testArrayQueue()
{
	ArrayQueue<int> myQueue;


	for (int i = 0; i < 5; i++)
	{
		myQueue.enqueue(i);
		cout << myQueue.toString(IntToStirng) << endl;

		if (i % 3 == 2)
		{
			myQueue.dequeue();
			cout << myQueue.toString(IntToStirng) << endl;
		}
	}
	
}

void testLoopQueue()
{
	LoopQueue<int> myQueue;


	for (int i = 0; i < 20; i++)
	{
		myQueue.enqueue(i);
		cout << myQueue.toString(IntToStirng) << endl;
		if (i % 3 == 2)
		{
			myQueue.dequeue();
			cout << myQueue.toString(IntToStirng) << endl;
		}
	}
	
}

void testLinkedListQueue()
{
	LinkedListQueue<int> myQueue;


	for (int i = 0; i < 20; i++)
	{
		myQueue.enqueue(i);
		cout << myQueue.toString(IntToStirng) << endl;
		if (i % 3 == 2)
		{
			myQueue.dequeue();
			cout << myQueue.toString(IntToStirng) << endl;
		}
	}

}

int main()
{

	testArrayQueue();
	testLoopQueue();
	testLinkedListQueue();
	system("pause");
	return EXIT_SUCCESS;
}