#pragma once
#include <queue>
#include <string>

template <class T>
class BST
{
private:
	class Node{
	public:
		T data;
		Node * left;
		Node * right;
		Node(T t) :data(t), left(nullptr), right(nullptr)
		{

		}
	};
public:
	BST();
	~BST();
	int getSize();
	bool isEmpty();

	void add(T t);
	bool contains(T t);

	void preOrder();
	void inOrder();
	void levelOrder();

	T minimum();
	T maximum();

	T removeMin();
	T removeMax();
	void remove(T t);

	std::string toString(std::string(*func)(T));

private:
	Node * add(Node *node, T t);
	bool contains(Node *node, T t);

	void preOrder(Node * node);
	void inOrder(Node * node);

	Node* minimum(Node*);
	Node* maximum(Node*);

	Node* removeMin(Node*);
	Node* removeMax(Node*);
	Node* remove(Node*, T t);
	void removeALL();

	void generateBSTStirng(Node * node, int depth, std::string &str);
	std::string generateDepthString(int depth);
	std::string(*mTtoStr)(T);

private:
	Node * root;
	int size;
};

