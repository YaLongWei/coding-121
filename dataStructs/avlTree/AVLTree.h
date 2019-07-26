#pragma once

#include <stack>
#include <vector>
using namespace std;
//模板参数的二叉搜索树
template <class T>
class AVLTree
{
public:
	AVLTree();
	~AVLTree();
	//树的长度
	int Size();
	//判断是否是空树
	bool isEmpty();
	//添加一个元素
	void add(T t);
	//查找元素
	bool contians(T t);
	//递归先序遍历
	void preOrder();
	//递归中序遍历
	void inOrder();
	//递归后序遍历
	void postOrder();
	//非递归先序遍历
	void preOrderNR();
	//非递归中序遍历
	void inOrderNR();
	//非递归后序遍历
	void postOrderNR();
	//广度优先遍历
	void levelOrder();
	//非递归中序遍历不借助栈实现

	//非递归后序遍历不借助栈实现

	//递归查找最小元素
	T minimum();
	//非递归查找最小元素
	T minimumNR();

	//递归查找最小元素
	T maxmum();
	//非递归查找最小元素
	T maxmumNR();

	//删除最小元素
	T removeMin();
	//删除最大元素
	T removeMax();

	//删除指定元素
	bool remove(T t);

	//判断这个树是否是二分搜索树
	bool isBST();
	//判断这个树是否是平衡二叉树
	bool isBalanced();

	//设置字符串转换函数
	void setToStrFunc(std::string(*toStr)(T t));
	//返回树结构字符串
	std::string toString();

private:
	class Node
	{
	public:
		Node(T e) :left(NULL), right(NULL)
		{
			this->e = e;
			high = 1;
		}
	public:
		T e;
		int high;
		Node *left, *right;
	};
private:
	Node* add(Node *n, T t);
	bool contians(Node *n, T t);
	void preOrder(Node *n);
	void postOrder(Node * n);
	void inOrder(Node *n);
	void generateAVLTreeString(Node * n, int depth, std::string &str);
	std::string generateDepthString(int depth);
	Node * minimum(Node *);
	Node * maxmum(Node *);
	Node * removeMin(Node *);
	Node * removeMax(Node *);

	Node * remove(Node *, T t);
	int maxHigh(Node * node);
	int getHigh(Node * node);
	int getBalanceFactor(Node * node);

	void inOrderArr(Node *n, vector<T> &vect);
	//判断这个树是否是平衡二叉树
	bool isBalanced(Node *n);

	//右旋转
	Node * rightRotate(Node * y);

	//左旋转
	Node * leftRotate(Node * y);

private:
	Node * root;
	int size;
	std::string(*toStr)(T t);
};



template <class T>
AVLTree<T>::AVLTree() : root(NULL), size(0)
{
}

template <class T>
AVLTree<T>::~AVLTree()
{
}
template <class T>
int AVLTree<T>::Size()
{
	return size;
}

template <class T>
bool AVLTree<T>::isEmpty()
{
	return size == 0;
}

template <class T>
void AVLTree<T>::add(T t)
{
	root = add(root, t);
}

template <class T>
typename AVLTree<T>::Node * AVLTree<T>::rightRotate(Node * y)
{
	Node * left = y->left;
	y->left = left->right;
	left->right = y;
	y->high = maxHigh(y)+1;
	left->high = maxHigh(left) + 1;
	return left;
}

template <class T>
typename AVLTree<T>::Node * AVLTree<T>::leftRotate(Node * y)
{
	Node * right = y->right;
	y->right = right->left;
	right->left = y;
	y->high = maxHigh(y) + 1;
	right->high = maxHigh(right) + 1;
	return right;
}

template <class T>
typename AVLTree<T>::Node *AVLTree<T>::add(Node * n, T t)
{
	if (n == NULL)
	{
		size++;
		return new Node(t);
	}

	if (t < n->e)
		n->left = add(n->left, t);
	else if (t > n->e)
		n->right = add(n->right, t);
	n->high = maxHigh(n) + 1;
	int balanceFactor = getBalanceFactor(n);
	if (balanceFactor > 1 || balanceFactor < -1)
	{
		cout << "unbalanced:" << balanceFactor << endl;
	}
	//LL
	if (balanceFactor > 1 && getBalanceFactor(n->left) >= 0)
	{
		return rightRotate(n);
	}
	//RR
	if (balanceFactor < -1 && getBalanceFactor(n->right) <= 0)
	{
		return leftRotate(n);
	}
	//RL
	if (balanceFactor < -1 && getBalanceFactor(n->right) >= 0)
	{
		n->right = rightRotate(n->right);
		return leftRotate(n);
	}
	//LR
	if (balanceFactor > 1 && getBalanceFactor(n->left) <= 0)
	{
		n->left = rightRotate(n->left);
		return rightRotate(n);
	}

	
	return n;
}

template <class T>
bool AVLTree<T>::contians(T t)
{
	return contians(root, t);
}

template <class T>
bool AVLTree<T>::contians(Node *n, T t)
{
	if (n == NULL)
	{
		return false;
	}
	if (t == n->e)
		return true;
	
	if (t < n->e)
		return contians(n->left, t);
	else// if (t > n->e)
		return contians(n->right, t);
}

template <class T>
void AVLTree<T>::preOrder()
{
	preOrder(root);
}

template <class T>
void AVLTree<T>::preOrder(Node *n)
{
	if (n == NULL)
	{
		return;
	}
	cout << n->e << endl;
	preOrder(n->left);
	preOrder(n->right);
}

template <class T>
std::string AVLTree<T>::toString()
{
	std::string str = "";
	generateAVLTreeString(root, 0, str);
	return str;
}

template <class T>
void AVLTree<T>::generateAVLTreeString(Node * n, int depth, std::string &str)
{
	if (n == NULL)
	{
		str += generateDepthString(depth) + "NULL\n";
		return;
	}
	str += generateDepthString(depth) + toStr(n->e) + "\n";

	generateAVLTreeString(n->left, depth + 1, str);
	generateAVLTreeString(n->right, depth + 1, str);

}

template <class T>
std::string AVLTree<T>::generateDepthString(int depth)
{
	std::string str = "";
	for (int i = 0; i < depth; i++)
	{
		str += "--";
	}
	return str;
}

template <class T>
void AVLTree<T>::setToStrFunc(std::string(*toStr)(T t))
{
	this->toStr = toStr;
}

template <class T>
void AVLTree<T>::inOrder()
{
	inOrder(root);
}

template <class T>
void AVLTree<T>::inOrder(Node *n)
{
	if (n == NULL)
	{
		return;
	}
	inOrder(n->left);
	cout << n->e << endl;
	inOrder(n->right);
}

template <class T>
void AVLTree<T>::postOrder()
{
	postOrder(root);
}

template <class T>
void AVLTree<T>::postOrder(Node * n)
{
	if (n == NULL)
	{
		return;
	}
	postOrder(n->left);
	postOrder(n->right);
	cout << n->e << endl;
}


//非递归先序遍历
template <class T>
void AVLTree<T>::preOrderNR()
{
	stack<Node*> st;
	st.push(root);
	Node*tmp = NULL;
	while (!st.empty())
	{
		tmp = st.top();
		st.pop();
		cout << tmp->e << endl;
		if (tmp->right != NULL)
		{
			st.push(tmp->right);
		}
		if (tmp->left != NULL)
		{
			st.push(tmp->left);
		}
	}
}

//非递归中序遍历
template <class T>
void AVLTree<T>::inOrderNR()
{
	stack<Node*> st;
	Node*tmp = root;
	while (!st.empty() || tmp != NULL)
	{
		while (tmp != NULL)
		{
			st.push(tmp);
			tmp = tmp->left;
		}
		if (!st.empty())
		{
			tmp = st.top();
			cout << tmp->e << endl;
			st.pop();
			tmp = tmp->right;

		}
	}
}

//非递归后序遍历
template <class T>
void AVLTree<T>::postOrderNR()
{
	stack<Node*> st;
	stack<Node*> st2;
	Node*tmp = root;
	while (!st.empty() || tmp != NULL)
	{
		while (tmp != NULL)
		{
			st.push(tmp);
			st2.push(tmp);
			tmp = tmp->right;
		}
		if (!st.empty())
		{
			tmp = st.top();
			st.pop();
			tmp = tmp->left;
		}
	}
	while (!st2.empty())
	{
		cout << st2.top()->e << endl;
		st2.pop();
	}
}

template <class T>
void AVLTree<T>::levelOrder()
{
	std::deque<T> que;
	Node * p = NULL;
	que.push_back(root);
	while (que.empty())
	{
		p = que->front();
		que->pop_front();
		cout << p.e << endl;
		if (p->left != NULL)
		{
			que->push_back(p->left);
		}
		if (p->right != NULL)
		{
			que->push_back(p->right);
		}
	}
}

template <class T>
T AVLTree<T>::minimum()
{
	if (size == 0)
		throw "tree null";
	return minimum(root)->e;
}

template <class T>
typename AVLTree<T>::Node * AVLTree<T>::minimum(Node *n)
{
	if (n->left == NULL)
	{
		return n;
	}
	return minimum(n->left);
}

template <class T>
T AVLTree<T>::minimumNR()
{
	if (size == 0)
		throw "tree null";
	Node *n = root;
	while (n->left)
	{
		n = n->left;
	}
	return n->e;
}

template <class T>
T AVLTree<T>::maxmum()
{
	if (size == 0)
		throw "tree null";
	return maxmum(root)->e;
}

template <class T>
typename AVLTree<T>::Node * AVLTree<T>::maxmum(Node *n)
{
	if (n->right == NULL)
		return n;
	return maxmum(n->right);
}

template <class T>
T AVLTree<T>::maxmumNR()
{
	Node *n = root;
	while (n->right)
	{
		n = n->right;
	}
	return n->e;
}

template <class T>
T AVLTree<T>::removeMin()
{
	T t = minimum();
	root = removeMin(root);
	return t;
}

template <class T>
typename AVLTree<T>::Node * AVLTree<T>::removeMin(Node * n)
{
	if (n->left == NULL)
	{
		Node * rightNode = n->right;
		n->right = NULL;
		size--;
		delete n;
		return rightNode;
	}
	n->left = removeMin(n->left);
	return n;
}

template <class T>
T  AVLTree<T>::removeMax()
{
	T ret = minimum();
	root = removeMax(root);
	return ret;

}

template <class T>
typename AVLTree<T>::Node * AVLTree<T>::removeMax(Node *n)
{
	if (n->right == NULL)
	{
		Node * leftNode = n->left;
		n->left = NULL;
		delete n;
		size--;
		return leftNode;
	}
	n->right = removeMax(n->right);
	return n;
}

template <class T>
bool AVLTree<T>::remove(T t)
{
	if (!contians(t))
	{
		return false;
	}

	root = remove(root, t);
	return true;
}

template <class T>
typename AVLTree<T>::Node * AVLTree<T>::remove(Node *n, T t)
{
	if (n == NULL)
	{
		return NULL;
	}
	Node * retNode = NULL;
	if (t < n->e)
	{
		n->left = remove(n->left, t);
		retNode = n;
	}
	else if (t > n->e)
	{
		n->right = remove(n->right, t);
		retNode = n;
	}
	else
	{
		if (n->left == NULL)
		{
			Node * rightNode = n->right;
			n->right = NULL;
			delete n;
			size--;
			retNode = rightNode;
			
		}
		else if (n->right == NULL)
		{
			Node * leftNode = n->left;
			n->left = NULL;
			delete n;
			size--;
			retNode = leftNode;
		}
		else//if(n->left && n->right)
		{
			int nE = n->e = minimum(n->right)->e;
			n->right = remove(n->right, nE);
			retNode = n;
		}
	}
	if (retNode == NULL)
		return NULL;
	retNode->high = maxHigh(retNode) + 1;
	int balanceFactor = getBalanceFactor(retNode);
	if (balanceFactor > 1 || balanceFactor < -1)
	{
		cout << "unbalanced:" << balanceFactor << endl;
	}
	//LL
	if (balanceFactor > 1 && getBalanceFactor(retNode->left) >= 0)
	{
		return rightRotate(retNode);
	}
	//RR
	if (balanceFactor < -1 && getBalanceFactor(retNode->right) <= 0)
	{
		return leftRotate(retNode);
	}
	//RL
	if (balanceFactor < -1 && getBalanceFactor(retNode->right) >= 0)
	{
		retNode->right = rightRotate(retNode->right);
		return leftRotate(retNode);
	}
	//LR
	if (balanceFactor > 1 && getBalanceFactor(retNode->left) <= 0)
	{
		retNode->left = rightRotate(retNode->left);
		return rightRotate(retNode);
	}


	return retNode;
}

template <class T>
int AVLTree<T>::getHigh(Node * node)
{
	if (node == NULL)
	{
		return 0;
	}
	return node->high;
}

template <class T>
int AVLTree<T>::maxHigh(Node * node)
{
	int leftHigh = getHigh(node->left);
	int rightHigh = getHigh(node->right);
	return leftHigh > rightHigh ? leftHigh : rightHigh;
}

template <class T>
int AVLTree<T>::getBalanceFactor(Node * node)
{
	if (node == NULL)
		return 0;
	return getHigh(node->left) - getHigh(node->right);
}

template <class T>
bool AVLTree<T>::isBST()
{
	vector<T> vect;
	inOrderArr(root, vect);
	int vsize = vect.size();
	for (int i = 0; i < vsize-1; i++)
	{
		if (vect[i] > vect[i + 1])
		{
			return false;
		}
	}
	return true;
}

template <class T>
void AVLTree<T>::inOrderArr(Node *n, vector<T> &vect)
{
	if (n == NULL)
	{
		return;
	}
	inOrderArr(n->left, vect);
	vect.push_back(n->e);
	inOrderArr(n->right, vect);
}

template <class T>
bool AVLTree<T>::isBalanced()
{
	return isBalanced(root);
}

template <class T>
bool AVLTree<T>::isBalanced(Node *n)
{
	if (n == NULL)
	{
		return true;
	}
	if (getBalanceFactor(n) > 1 || getBalanceFactor(n) < -1)
	{
		return false;
	}
	return isBalanced(n->left) && isBalanced(n->right);
}