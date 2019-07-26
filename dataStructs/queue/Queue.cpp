#pragma once
#include "Queue.h"


template <class T>
ArrayQueue<T>::ArrayQueue()
{

}

template <class T>
ArrayQueue<T>::ArrayQueue(int capacity) : arr(capacity)
{

}

template <class T>
ArrayQueue<T>::~ArrayQueue()
{

}

template <class T>
int ArrayQueue<T>::getSize()
{
	return arr.getSize();
}
template <class T>
bool ArrayQueue<T>::isEmpty()
{
	return arr.isEmpty();
}

template <class T>
void ArrayQueue<T>::enqueue(T t)
{
	arr.addLast(t);
}

template <class T>
T ArrayQueue<T>::dequeue()
{
	return arr.removeFirst();
}

template <class T>
T ArrayQueue<T>::getFront()
{
	return arr.getFirst();
}

template <class T>
int ArrayQueue<T>::getCapacity()
{
	return arr.getCapacity();
}

template <class T>
std::string ArrayQueue<T>::toString(std::string(*func)(T))
{
	int size = arr.getSize();
	std::string str;
	str += "ArrayQueue: size = " +
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

