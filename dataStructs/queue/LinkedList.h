#pragma once

#include <string>

template <class T>
class LinkedList
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
	LinkedList();
	~LinkedList();

	int getSize();
	bool isEmpty();

	void add(int index, T t);
	void addFirst(T t);
	void addLast(T t);

	T get(int index);
	T getFirst();
	T getLast();

	void set(int index, T t);

	bool contains(T t);

	T remove(int index);
	T removeFirst();
	T removeLast();

	std::string toString(std::string(*func)(T));

private:
	void removeALL();
private:	
	Node * dummyHead;
	int size;
};




