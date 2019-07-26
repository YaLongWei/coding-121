#pragma once

template <class T>
class Set
{
public:
	virtual void add(T) = 0;
	virtual void remove(T) = 0;
	virtual bool contains(T) = 0;
	virtual int getSize() = 0;
	virtual bool isEmpty() = 0;
};