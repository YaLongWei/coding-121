#pragma once


template <class K, class V>
class Map
{
public:
	virtual void add(K key, V value) = 0;
	virtual V remove(K key) = 0;
	virtual bool contains(K key) = 0;
	virtual V get(K key) = 0;
	virtual void set(K key, V value) = 0;
	virtual int getSize() = 0;
	virtual bool isEmpty() = 0;
	virtual V operator [](K key) = 0;
};

