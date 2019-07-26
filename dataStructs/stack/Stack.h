#pragma once

#include "Array.cpp"

template <class T>
class Stack
{
public:

	virtual int getSize() = 0;
	virtual bool isEmpty() = 0;
	virtual void push(T t) = 0;
	virtual T pop() = 0;
	virtual T peek() = 0;
};

template <class T>
class ArrayStack : public Stack<T>
{
public:
	ArrayStack();
	ArrayStack(int capacity);
	~ArrayStack();

	virtual int getSize() ;
	virtual bool isEmpty();
	virtual void push(T t);
	virtual T pop();
	virtual T peek();

	int getCapacity();

	std::string toString(std::string(*func)(T));
private:
	Array<T> arr;
};