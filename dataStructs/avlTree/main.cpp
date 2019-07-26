#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include <vector>
using namespace std;

#include "AVLTree.h"


string intToStr(int data)
{
	char buf[32] = { 0 };
	sprintf(buf, "%d", data);
	return buf;
}

int main()
{

	AVLTree<int> b;

	int arr[] = { 5, 3, 6, 8, 4, 2,1,2,3,4,5,6,7,8,9,10,11,12};
	for (int i = 0; i < sizeof(arr)/sizeof(arr[0]); i++)
	{
		b.add(arr[i]);
	}
	cout << "b is " << b.isBST() << " BTS." << endl;
	cout << "b is " << b.isBalanced() << " Balanced." << endl;
	
	b.preOrder();
	cout << "--------------------" << endl;
	b.inOrder();
	cout << "--------------------" << endl;
	b.postOrder();
	cout << "--------------------" << endl;
	b.preOrderNR();
	cout << "--------------------" << endl;
	b.inOrderNR();
	cout << "--------------------" << endl;
	b.postOrderNR();

	b.removeMin();
	cout << "b is " << b.isBST() << " BTS." << endl;
	cout << "b is " << b.isBalanced() << " Balanced." << endl;
	b.removeMax();
	cout << "b is " << b.isBST() << " BTS." << endl;
	cout << "b is " << b.isBalanced() << " Balanced." << endl;
	b.remove(3);
	cout << "b is " << b.isBST() << " BTS." << endl;
	cout << "b is " << b.isBalanced() << " Balanced." << endl;

	cout << "--------------------" << endl;
	b.postOrderNR();

	b.setToStrFunc(intToStr);
	cout << "--------------------" << endl;
	cout << b.toString().c_str() << endl;

	system("pause");
	return EXIT_SUCCESS;
}