#pragma once

#include <string>

template <class T>
class Array
{
public:
	Array();
	Array(int);
	~Array();
	int getSize();
	int getCapacity();
	bool isEmpty();

	void add(int index, T t);
	void addLast(T t);
	void addFirst(T t);
	
	T get(int index);
	void set(int index, T t);
	bool contains(T t);
	int find(T t);

	T remove(int index);
	T removeFirst();
	T removeLast();
	void removeElement(T t);

	T getLast();
	T getFirst();

	std::string toString(std::string(*func)(T));



private:
	void resize(int);
private:
	T * arr;
	int size;
	int capacity;
};

//#include "Array.cpp"  