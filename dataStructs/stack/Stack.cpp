#pragma once
#include "Stack.h"

template <class T>
ArrayStack<T>::ArrayStack()
{
	
}

template <class T>
ArrayStack<T>::ArrayStack(int capacity) : arr(capacity)
{
	
}

template <class T>
ArrayStack<T>::~ArrayStack()
{
	
}

template <class T>
int ArrayStack<T>::getSize()
{
	return arr.getSize();
}

template <class T>
bool ArrayStack<T>::isEmpty()
{
	return arr.isEmpty();
}


template <class T>
int ArrayStack<T>::getCapacity()
{
	return arr.getCapacity();
}

template <class T>
void ArrayStack<T>::push(T t)
{
	arr.addLast(t);
}

template <class T>
T ArrayStack<T>::pop()
{
	return arr.removeLast();
}

template <class T>
T ArrayStack<T>::peek()
{
	return arr.getLast();
}

template <class T>
std::string ArrayStack<T>::toString(std::string(*func)(T))
{
	int size = arr.getSize();
	std::string str;
	str += "ArrayStack: size = " +
		std::to_string(size) +
		", capacity = " +
		std::to_string(arr.getCapacity()) +
		"\n";
	str += "[";
	
	for (int i = 0; i < size; i++)
	{
		str += func(arr.get(i));
		if (i != size - 1)
		{
			str += ", ";
		}
	}
	str += "]";
	return str;
}

