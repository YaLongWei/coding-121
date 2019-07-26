#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

#include "RBTree.h"

int main()
{

	RBTree<int, int> b;

	int arr[] = { 5, 3, 6, 8, 4, 2, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12 };
	for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
	{
		b.add(i, arr[i]);
	}
	b.inOrder();
	system("pause");
	return EXIT_SUCCESS;
}