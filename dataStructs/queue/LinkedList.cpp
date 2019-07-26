#pragma once
#include "LinkedList.h"


template <class T>
LinkedList<T>::LinkedList()
{
	dummyHead = new Node;
	size = 0;
}

template <class T>
LinkedList<T>::~LinkedList()
{
	removeALL();
	
}

template <class T>
int LinkedList<T>::getSize()
{
	return size;
}

template <class T>
bool LinkedList<T>::isEmpty()
{
	return size == 0;
}

template <class T>
void LinkedList<T>::add(int index, T t)
{
	if (index < 0 || index > size)
	{
		throw "Index Error";
	}

	Node * p = dummyHead;
	for (int i = 0; i < index; i++)
		p = p->next;
		
	p->next = new Node(t, p->next);
	size++;
	
}

template <class T>
void LinkedList<T>::addFirst(T t)
{
	add(0, t);
}

template <class T>
void LinkedList<T>::addLast(T t)
{
	add(size, t);
}

template <class T>
T LinkedList<T>::get(int index)
{
	if (index < 0 || index >= size)
		throw "List::get() Index Error";
	Node *cur = dummyHead->next;
	for (int i = 0; i < index; i++)
	{
		cur = cur->next;
	}
	return cur->data;
}

template <class T>
T LinkedList<T>::getFirst()
{
	return get(0);
}

template <class T>
T LinkedList<T>::getLast()
{
	return get(size - 1);
}


template <class T>
void LinkedList<T>::set(int index, T t)
{
	if (index < 0 || index >= size)
		throw "List::set() Index Error";
	Node *cur = dummyHead->next;
	for (int i = 0; i < index; i++)
	{
		cur = cur->next;
	}
	cur->data = t;
}


template <class T>
bool LinkedList<T>::contains(T t)
{
	Node * cur = dummyHead->next;
	while (cur != nullptr)
	{
		if (cur->data == t)
		{
			return true;
		}
	}
	return false;
}

template <class T>
T LinkedList<T>::remove(int index)
{
	if (index < 0 || index >= size)
	{
		throw "List::remove() Index Error";
	}
	Node * prev = dummyHead;
	for (int i = 0; i < index; i++)
		prev = prev->next;

	Node * removeNode = prev->next;
	T tmp = removeNode->data;
	prev->next = removeNode->next;
	delete removeNode;
	size--;
	return tmp;
}

template <class T>
T LinkedList<T>::removeFirst()
{
	return remove(0);
}

template <class T>
T LinkedList<T>::removeLast()
{
	return remove(size - 1);
}

template <class T>
void LinkedList<T>::removeALL()
{
	while (!isEmpty())
	{
		removeFirst();
	}
}

template <class T>
std::string LinkedList<T>::toString(std::string(*func)(T))
{
	std::string str;
	Node * cur = dummyHead->next;
	str += "LinkedList size = " + to_string(size) + "\n";
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