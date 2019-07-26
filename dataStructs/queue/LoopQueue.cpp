#include "LoopQueue.h"


template <class T>
LoopQueue<T>::LoopQueue() : LoopQueue(10)
{
}

template <class T>
LoopQueue<T>::LoopQueue(int capacity)
{
	this->capacity = capacity + 1;
	arr = new T[capacity + 1];
	front = 0;
	tail = 0;
	size = 0;
}

template <class T>
LoopQueue<T>::~LoopQueue()
{
	delete[]arr;
}

template <class T>
int LoopQueue<T>::getCapacity()
{
	return capacity - 1;
}

template <class T>
int LoopQueue<T>::getSize()
{
	return size;
}

template <class T>
bool LoopQueue<T>::isEmpty()
{
	return front == tail;
}

template <class T>
void LoopQueue<T>::resize(int newCapacity)
{
	T * tmp = new T[newCapacity + 1];
	for (int i = 0; i < size; i++)
	{
		tmp[i] = arr[(i+front) % capacity];
	}
	
	delete[]arr;
	arr = tmp;
	front = 0;
	tail = size;
	capacity = newCapacity + 1;
}

template <class T>
void LoopQueue<T>::enqueue(T t)
{
	if ((tail + 1) % capacity == front)
		resize(getCapacity() * 2);


	arr[tail] = t;
	tail = (tail + 1) % capacity;
	size++;
}

template <class T>
T LoopQueue<T>::dequeue()
{
	if (isEmpty())
		throw "Queue Is Empty";
	T ret = arr[front];
	front = (front + 1) % capacity;
	size--;
	if (size == getCapacity() / 4 && getCapacity()/2 != 0)
	{
		resize(getCapacity() / 2);
	}
	return ret;
}

template <class T>
T LoopQueue<T>::getFront()
{
	return arr[front];
}


template <class T>
std::string LoopQueue<T>::toString(std::string(*func)(T))
{
	int size = getSize();
	std::string str;
	str += "LoopQueue: size = " +
		std::to_string(size) +
		", capacity = " +
		std::to_string(getCapacity()) +
		"\n";
	str += "front[";

	for (int i = front; i != tail; i = (i + 1) % capacity)
	{
		str += func(arr[i]);
		if ((i + 1) % capacity != tail)
		{
			str += ", ";
		}
	}
	str += "] tail";
	return str;
}