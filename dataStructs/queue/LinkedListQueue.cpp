#pragma once
#include "LinkedListQueue.h"

template <class T>
LinkedListQueue<T>::LinkedListQueue()
{
	head = nullptr;
	tail = nullptr;
	size = 0;
}

template <class T>
LinkedListQueue<T>::~LinkedListQueue()
{
	removeALL();
}

template <class T>
int LinkedListQueue<T>::getSize()
{
	return size;
}

template <class T>
bool LinkedListQueue<T>::isEmpty()
{
	return size == 0;
}

template <class T>
void LinkedListQueue<T>::enqueue(T t)
{
	if (tail == nullptr)
	{
		tail = new Node(t);
		head = tail;
	}
	else
	{
		tail->next = new Node(t);
		tail = tail->next;
	}
	size++;
}

template <class T>
T LinkedListQueue<T>::dequeue()
{

	if (isEmpty())
		throw "LinkedListQueue::dequeue: Head Is Empty";

	Node * tmp = head;
	T t = tmp->data;
	head = head->next;
	delete tmp;
	if (head == nullptr)
		tail = nullptr;
	size--;
	return t;
	
}

template <class T>
T LinkedListQueue<T>::getFront()
{
	if (isEmpty())
		throw "LinkedListQueue::getFront: Head Is Empty";
	return head->data;
}

template <class T>
void LinkedListQueue<T>::removeALL()
{
	while (!isEmpty())
	{
		dequeue();
	}
}

template <class T>
std::string LinkedListQueue<T>::toString(std::string(*func)(T))
{
	std::string str;
	Node * cur = head;
	str += "LinkedListQueue size = " + to_string(size) + "\n";
	str += "[";
	while (cur != nullptr)
	{
		str += func(cur->data);
		str += "->";
		cur = cur->next;
	}
	str += "nullptr";
	return str;
}
