#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

#include "BSTSet.cpp"

#include <time.h>
#include <stdlib.h>

string IntToStirng(int n)
{
	return to_string(n);
}

#include <set>
class Solution {
public:
	int uniqueMorseRepresentations(vector<string>& words) {
		vector<string> mVec = { ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.." };
		set<string> mSet;
		for (int i = 0; i < words.size(); i++)
		{
			string str;
			for (int j = 0; j < words[i].size(); j++)
			{
				str += mVec[words[i][j] - 'a'];
			}
			mSet.insert(str);
		}
		return mSet.size();
	}
};

int main()
{
	BSTSet<int> bstSet;
	int n = 10;
	srand((unsigned int)time(NULL));
	for (int i = 0; i < n; i++)
	{
		bstSet.add(rand()%10);
	}
	cout << bstSet.toString(IntToStirng) << endl;

	system("pause");
	return EXIT_SUCCESS;
}