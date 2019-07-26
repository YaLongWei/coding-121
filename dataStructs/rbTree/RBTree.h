#pragma once

template <class K, class  V>
class RBTree
{
public:
	RBTree();
	int getSize();
	bool isEmpty();
	void add(K key, V value);
	V remove(K key);
	bool contains(K key);
	V get(K key);
	void set(K key, V newValue);
	//µÝ¹éÖÐÐò±éÀú
	void inOrder();
	

private:
	class Node;
	Node * add(Node *n, K key, V value);
	Node * removeMin(Node *n);
	Node * minimum(Node *n);
	bool isRed(Node *n);
	void flipColors(Node *n);
	Node * leftRotate(Node * n);
	Node * rightRotate(Node * n);

	void inOrder(Node *);
private:
	static const bool RED = true;
	static const bool BLACK = false;
	class Node
	{
	public:
		K key;
		V value;
		Node * left;
		Node * right; 
		bool color;
		Node(K key, V value)
		{
			this->key = key;
			this->value = value;
			left = NULL;
			right = NULL;
			color = RED;
		}

	};

private:
	Node * root;
	int size;
};


template <class K, class  V>
RBTree<K, V>::RBTree()
{
	root = NULL;
	size = 0;
}

template <class K, class  V>
int RBTree<K, V>::getSize()
{
	return size;
}

template <class K, class  V>
bool RBTree<K, V>::isEmpty()
{
	return size == 0;
}

template <class K, class  V>
void RBTree<K, V>::add(K key, V value)
{
	root = add(root, key, value);
	root->color = BLACK;
}

template <class K, class  V>
V RBTree<K, V>::remove(K key)
{

}

template <class K, class  V>
bool RBTree<K, V>::contains(K key)
{

}

template <class K, class  V>
V RBTree<K, V>::get(K key)
{
	V a;
	return a;
}

template <class K, class  V>
void RBTree<K, V>::set(K key, V newValue)
{

}

template <class K, class  V>
typename RBTree<K, V>::Node * RBTree<K, V>::add(Node *n, K key, V value)
{
	if (n == NULL)
	{
		size++;
		return new Node(key, value);
	}
	if (key < n->key)
		n->left = add(n->left, key, value);
	else if (key > n->key)
		n->right = add(n->left, key, value);
	else
		n->value = value;

	if (isRed(n->right) && !isRed(n->left))
	{
		n = leftRotate(n);
	}
	if (isRed(n->left) && isRed(n->left->left))
	{
		n = rightRotate(n);
	}
	if (isRed(n->left) && isRed(n->right))
	{
		flipColors(n);
	}

	return n;
}

template <class K, class  V>
typename RBTree<K, V>::Node * RBTree<K, V>::removeMin(Node *n)
{
	return NULL;
}

template <class K, class  V>
typename RBTree<K, V>::Node * RBTree<K, V>::minimum(Node *n)
{
	return NULL;
}
template <class K, class  V>
bool RBTree<K, V>::isRed(Node *n)
{
	if (n == NULL)
	{
		return BLACK;
	}

	return n->color;
}

template <class K, class  V>
typename RBTree<K, V>::Node * RBTree<K, V>::leftRotate(Node * n)
{
	Node * temp = n->right;
	n->right = temp->left;
	temp->left = n;
	temp->color = n->color;
	n->color = RED;
	return temp;

}

template <class K, class  V>
typename RBTree<K, V>::Node * RBTree<K, V>::rightRotate(Node * n)
{
	Node * temp = n->left;
	n->left = temp->right;
	temp->right = n;
	temp->color = n->color;
	n->color = RED;
	return temp;
}

template <class K, class  V>
void RBTree<K, V>::flipColors(Node *n)
{
	n->color = RED;
	n->left->color = BLACK;
	n->right->color = BLACK;
}

template <class K, class  V>
void RBTree<K, V>::inOrder()
{
	inOrder(root);
}

template <class K, class  V>
void RBTree<K, V>::inOrder(Node * n)
{
	if (n == NULL)
	{
		return;
	}
	inOrder(n->left);
	cout << n->key << " " << n->value << endl;
	inOrder(n->right);
}