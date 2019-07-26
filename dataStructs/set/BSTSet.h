#pragma once
#include "BST.cpp"
#include "Set.h"

template <class T>
class BSTSet : public Set<T>
{
public:
	BSTSet();
	~BSTSet();
	virtual int getSize();
	virtual bool isEmpty();

	virtual void add(T);
	virtual void remove(T);
	virtual bool contains(T);

	std::string toString(std::string(*func)(T));
private:
	BST<T> bst;
};

