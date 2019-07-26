#include "BSTMap.h"


template <class K, class V>
BSTMap<K, V>::BSTMap()
{
}

template <class K, class V>
BSTMap<K, V>::~BSTMap()
{
}


template <class K, class V>
int BSTMap<K, V>::getSize()
{
	return size;
}

template <class K, class V>
bool BSTMap<K, V>::isEmpty()
{
	return size == 0;
}

template <class K, class V>
void BSTMap<K, V>::add(K key, V value)
{
	root = add(root, key, value);
}

template <class K, class V>
typename BSTMap<K, V>::Node * BSTMap<K, V>::add(Node * node, K k, V v)
{
	if (node == nullptr)
	{
		size++;
		return new Node(k, v);
	}
	if (k == node->key)
}