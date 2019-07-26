#pragma once

#include "Array.cpp"

template <class T>
class Queue
{
public:
	virtual int getSize() = 0; 
	virtual bool isEmpty() = 0;
	virtual void enqueue(T t) = 0;
	virtual T dequeue() = 0;
	virtual T getFront() = 0;
};


template <class T>
class ArrayQueue : public Queue<T>
{
public:
	ArrayQueue();
	ArrayQueue(int capacity);
	~ArrayQueue();
	virtual int getSize();
	virtual bool isEmpty();
	virtual void enqueue(T t);
	virtual T dequeue();
	virtual T getFront();

	int getCapacity();

	std::string toString(std::string(*func)(T));


private:
	Array<T> arr;
};
