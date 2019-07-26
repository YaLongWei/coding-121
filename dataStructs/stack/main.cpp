#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

#include "Stack.cpp"
#include "LinkedListStack.cpp"


string IntToStirng(int n)
{
	return to_string(n);
}

void testArrayStack()
{
	ArrayStack<int> myStack;

	for (int i = 0; i < 5; i++)
	{
		myStack.push(i);
		cout << myStack.toString(IntToStirng) << endl;
	}
	myStack.pop();
	cout << myStack.toString(IntToStirng) << endl;
}

void testLinkedListStack()
{
	LinkedListStack<int> myStack;

	for (int i = 0; i < 5; i++)
	{
		myStack.push(i);
		cout << myStack.toString(IntToStirng) << endl;
	}
	myStack.pop();
	cout << myStack.toString(IntToStirng) << endl;
}

int main()
{

	testArrayStack();
	testLinkedListStack();

	system("pause");
	return EXIT_SUCCESS;
}