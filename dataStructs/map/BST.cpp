#include "BST.h"
#include <queue>

template <class T>
BST<T>::BST()
{
	root = nullptr;
	size = 0;
}

template <class T>
BST<T>::~BST()
{
	removeALL();
}

template <class T>
int BST<T>::getSize()
{
	return size;
}

template <class T>
bool BST<T>::isEmpty()
{
	return size == 0;
}

template <class T>
typename BST<T>::Node * BST<T>::add(Node *node, T t)
{
	if (node == nullptr)
	{
		size++;
		return new Node(t);
	}

	if (t < node->data)
		node->left = add(node->left, t);
	if (t > node->data)
		node->right = add(node->right, t);

	return node;
}

template <class T>
void BST<T>::add(T t)
{
	root = add(root, t);
}

template <class T>
bool BST<T>::contains(Node *node, T t)
{
	if (node == nullptr)
		return false;
	if (node->data == t)
		return true;
	else if (node->data < t)
		return contains(node->left, t);
	else
		return contains(node->right, t);
}

template <class T>
bool BST<T>::contains(T t)
{
	return contains(root, t);
}

template <class T>
void BST<T>::preOrder(Node * node)
{
	if (node == nullptr)
		return;
	cout << node->data << endl;
	preOrder(node->left);
	preOrder(node->right);
}

template <class T>
void BST<T>::preOrder()
{
	preOrder(root);
}

template <class T>
void BST<T>::inOrder(Node * node)
{
	if (node == nullptr)
		return;
	
	preOrder(node->left);
	cout << node->data << endl;
	preOrder(node->right);
}

template <class T>
void BST<T>::inOrder()
{
	inOrder(root);
}

template <class T>
void BST<T>::levelOrder()
{
	queue<Node *> que;
	que.push(root);
	while (!que.empty())
	{
		Node * tmp = que.front();
		que.pop();
		if (tmp->left != nullptr)
			que.push(tmp->left);
		if (tmp->right != nullptr)
			que.push(tmp->right);
		cout << tmp->data << endl;
	}
}

template <class T>
T BST<T>::minimum()
{
	if (size == 0)
		throw "BST<T>::minimum: Tree Is Empty.";
	return minimum(root)->data;
}

template <class T>
T BST<T>::maximum()
{
	if (size == 0)
		throw "BST<T>::maximum: Tree Is Empty.";
	return maximum(root)->data;
}

template <class T>
T BST<T>::removeMin()
{
	T t = minimum();
	root = removeMin(root);
	return t;
}

template <class T>
T BST<T>::removeMax()
{
	T t = maximum();
	root = removeMax(root);
	return t;
}

template <class T>
typename BST<T>::Node* BST<T>::removeMin(Node* node)
{
	if (node->left == nullptr)
	{
		Node * tmp = node->right;
		delete node;
		size--;
		return tmp;
	}

	node->left = removeMin(node->left);
	return node;
	
}

template <class T>
typename BST<T>::Node* BST<T>::removeMax(Node* node)
{
	if (node->right == nullptr)
	{
		Node *tmp = node->left;
		delete node;
		size--;
		return tmp;
	}
	node->right = removeMax(node->right);
	return node;
}

template <class T>
void BST<T>::removeALL()
{
	while (!isEmpty())
	{
		removeMax();
	}
}

template <class T>
typename BST<T>::Node* BST<T>::minimum(Node* node)
{
	if (node->left == nullptr)
		return node;
	return minimum(node->left);
}

template <class T>
typename BST<T>::Node* BST<T>::maximum(Node* node)
{
	if (node->right == nullptr)
		return node;
	return minimum(node->right);
}

template <class T>
void BST<T>::remove(T t)
{
	root = remove(root, t);
}

template <class T>
typename BST<T>::Node* BST<T>::remove(Node* node, T t)
{
	if (node == nullptr)
	{
		return nullptr;
	}

	if (node->data == t)
	{
		if (node->left == nullptr)
		{
			Node * tmp = node->right;
			delete node;
			size--;
			return tmp;
		}

		if (node->right == nullptr)
		{
			Node * tmp = node->left;
			delete node;
			size--;
			return tmp;
		}

		T tmp = minimum(node->right)->data;
		node->right = removeMin(node->right);
		node->data = tmp;
		return node;
	}
	else if ( t > node->data)
		node->right = remove(node->right, t);
	else
		node->left = remove(node->left, t);
	return node;

}

template <class T>
void BST<T>::generateBSTStirng(Node * node, int depth, std::string &str)
{
	if (node == nullptr)
	{
		str += generateDepthString(depth);
		str += "nullptr\n";
		return;
	}
	str += generateDepthString(depth);

	str += mTtoStr(node->data) + "\n";
	generateBSTStirng(node->left, depth + 1, str);
	generateBSTStirng(node->right, depth + 1, str);
	
}

template <class T>
std::string BST<T>::generateDepthString(int depth)
{
	std::string str;
	for (int i = 0; i < depth; i++)
		str += "--";
	return str;
}

template <class T>
std::string BST<T>::toString(std::string(*func)(T))
{
	mTtoStr = func;
	std::string str;
	generateBSTStirng(root, 0, str);
	return str;
}


