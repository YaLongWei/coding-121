#pragma once
#include "Map.h"
#include "BST.h"

template <class K, class V>
class BSTMap : public Map<K, V> , public BST<K>
{
private:
	class Node{
	public:
		K key;
		V value;
		Node * left;
		Node * right;

		Node(K k, V v){
			this->key = k;
			this->value = v;
			this->left = nullptr;
			this->right = nullptr;
		}
	};
public:
	BSTMap();
	~BSTMap();

	int getSize();
	bool isEmpty();
	void add(K key, V value);
private:
	Node * add(Node * node, K k, V v);
private:
	Node * root;
	int size;
};

