#pragma once

#include "LinkedListStack.h"


template <class T>
LinkedListStack<T>::LinkedListStack()
{
}

template <class T>
LinkedListStack<T>::~LinkedListStack()
{
}


template <class T>
int LinkedListStack<T>::getSize()
{
	return linklist.getSize();
}

template <class T>
bool LinkedListStack<T>::isEmpty()
{
	return linklist.isEmpty();
}

template <class T>
void LinkedListStack<T>::push(T t)
{
	linklist.addFirst(t);
}

template <class T>
T LinkedListStack<T>::pop()
{
	return linklist.removeFirst();
}

template <class T>
T LinkedListStack<T>::peek()
{
	return linklist.getFirst();
}

template <class T>
std::string LinkedListStack<T>::toString(std::string(*func)(T))
{
	std::string str;

	str += "LinkedListStack size = " + to_string(linklist.getSize()) + "\n";
	str += linklist.toString(func);
	return str;
}