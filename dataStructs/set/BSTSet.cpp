#include "BSTSet.h"


template <class T>
BSTSet<T>::BSTSet()
{
}

template <class T>
BSTSet<T>::~BSTSet()
{
}

template <class T>
int BSTSet<T>::getSize()
{
	return bst.getSize();
}

template <class T>
bool BSTSet<T>::isEmpty()
{
	return bst.isEmpty();
}

template <class T>
void BSTSet<T>::add(T t)
{
	bst.add(t);
}

template <class T>
void BSTSet<T>::remove(T t)
{
	bst.remove(t);
}

template <class T>
bool BSTSet<T>::contains(T t)
{
	return bst.contains(t);
}

template <class T>
std::string BSTSet<T>::toString(std::string(*func)(T))
{
	return bst.toString(func);
}
