#pragma once

#include "Queue.h"

template <class T>
class LinkedListQueue : public Queue<T>
{
private:

	class Node
	{
	public:
		T data;
		Node * next;
		Node(T t, Node * next)
		{
			this->data = t;
			this->next = next;
		}
		Node(T t) :Node(t, nullptr)
		{

		}
		Node() :Node(0, nullptr)
		{

		}
		std::string toString(std::string(*func)(T))
		{
			return func(data);
		}
	};
public:
	LinkedListQueue();
	~LinkedListQueue();
	virtual int getSize();
	virtual bool isEmpty();
	virtual void enqueue(T t);
	virtual T dequeue();
	virtual T getFront();

	std::string toString(std::string(*func)(T));
private:
	void removeALL();

private:
	Node * head;
	Node * tail;
	int size;
};

