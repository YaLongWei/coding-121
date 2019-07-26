#pragma once

#include "Stack.h"
#include "LinkedList.cpp"

template <class T>
class LinkedListStack : public Stack<T>
{
public:
	LinkedListStack();
	~LinkedListStack();

	virtual int getSize();
	virtual bool isEmpty();
	virtual void push(T t);
	virtual T pop();
	virtual T peek();

	std::string toString(std::string(*func)(T));
private:
	LinkedList<T> linklist;
};

