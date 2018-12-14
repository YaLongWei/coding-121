#include <iostream>
#include <algorithm>
#include <string>
#include <ctime>
#include <cassert>

using namespace std;

template<typename T>

class MaxHeap
{
private:
    T * data;
    int count;
public:
    MaxHeap(int capacity);
    ~MaxHeap();
};

template<typename T>
MaxHeap<T>::MaxHeap(int capacity);
{
    data = new T[capacity+1];
    count = 0;
	
}

template<typename T>
MaxHeap<T>::~MaxHeap()
{
    delete [] data;
}
