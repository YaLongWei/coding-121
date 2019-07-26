#include "Array.h"
#include <string>

template <class T>
Array<T>::Array() : Array(10)
{
	
}

template <class T>
Array<T>::Array(int n) :size(0), capacity(n)
{
	arr = new T[capacity];
}

template <class T>
Array<T>::~Array()
{
	delete []arr;
}

template <class T>
int Array<T>::getSize()
{
	return size;
}

template <class T>
int Array<T>::getCapacity()
{
	return capacity;
}
template <class T>
bool Array<T>::isEmpty()
{
	return size == 0;
}

template <class T>
void  Array<T>::add(int index, T t)
{
	if (index < 0 || index > size)
	{
		throw "bbbb";
	}
	if (size == capacity)
	{
		resize(capacity * 2);
	}
	for (int i = size - 1; i >= index; i--)
	{
		arr[i + 1] = arr[i];
	}
	arr[index] = t;
	size++;
}


template <class T>
void  Array<T>::addLast(T t)
{
	add(size, t);
}

template <class T>
void Array<T>::addFirst(T t)
{
	add(0, t);
}

template <class T>
T Array<T>::get(int index)
{
	if (index < 0 || index >= size)
		throw "index err";
	return arr[index];
}

template <class T>
void Array<T>::set(int index, T t)
{
	if (index < 0 || index >= size)
		throw "index err";
	arr[index] = t;
}

template <class T>
bool Array<T>::contains(T t)
{
	return find(t) >= 0;
}

template <class T>
int Array<T>::find(T t)
{
	for (int i = 0; i < size; i++)
	{
		if (t == arr[i])
		{
			return i;
		}
	}
	return -1;
}

template <class T>
T Array<T>::remove(int index)
{
	T tmp = get(index); 
	for (int i = index; i < size-1; i++)
	{
		arr[i] = arr[i + 1];
	}
	size--;
	if (size == capacity / 4 && capacity / 2 != 0)
		resize(capacity / 2);
	return tmp;
}

template <class T>
T Array<T>::removeFirst()
{
	return remove(0);
}

template <class T>
T Array<T>::removeLast()
{
	return remove(size-1);
}

template <class T>
void Array<T>::removeElement(T t)
{
	int index = find(t);
	if (index >= 0)
		remove(index);
}

template <class T>
std::string Array<T>::toString(std::string (* func)(T))
{
	std::string str;
	str += "Array: size = " +
		std::to_string(size) +
		", capacity = " +
		std::to_string(capacity) +
		"\n";
	str += "[";
	for (int i = 0; i < size; i++)
	{
		str += func(arr[i]);
		if (i != size - 1)
		{
			str += ", ";
		}
	}
	str += "]";
	return str;
}

template <class T>
void Array<T>::resize(int newCapacity)
{
	T * newArr = new T[newCapacity];
	for (int i = 0; i < size; i++)
		newArr[i] = arr[i];
	capacity = newCapacity;
	delete[]arr;
	arr = newArr;
}

template <class T>
T Array<T>::getLast()
{
	return this->get(size - 1);
}

template <class T>
T Array<T>::getFirst()
{
	return this->get(0);
}