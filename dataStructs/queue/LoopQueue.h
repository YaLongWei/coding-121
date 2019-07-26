#pragma once

#include "Queue.h"

template <class T>
class LoopQueue : public Queue<T>
{
public:
	LoopQueue();
	LoopQueue(int);
	~LoopQueue();

	virtual int getSize();
	virtual bool isEmpty();
	virtual void enqueue(T t);
	virtual T dequeue();
	virtual T getFront();

	int getCapacity();
	void resize(int);

	std::string toString(std::string(*func)(T));
private:
	T * arr;
	int front;
	int tail;
	int size;
	int capacity;
};

