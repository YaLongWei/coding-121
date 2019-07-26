#pragma once

#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include <cassert>

using namespace std;

//稀疏图--邻接表
class SparseGraph
{
private:
	//n顶点数，m边数
	int n, m;
	//
	bool directed;
	vector<vector<int>> g;
public:
	SparseGraph(int n, bool directed)
	{
		this->n = n;
		this->m = 0;
		this->directed = directed;
		for (int i = 0; i < n; i++)
		{
			g.push_back(vector<int>());
		}
	}

	~SparseGraph()
	{

	}
	int V()
	{
		return n;
	}
	int E()
	{
		return m;
	}
	void addEdge(int v, int w)
	{
		assert(v >= 0 && v < n);
		assert(w >= 0 && w < n);
		g[v].push_back(w);

		//v != w处理自环边问题   directed判断是不是无向图
		if ( v!=w && !directed )
		{
			g[w].push_back(v);
		}
		m++;
	}
	bool hasEdge(int v, int w)
	{
		assert(v >= 0 && v < n);
		assert(w >= 0 && w < n);
		int len = g[v].size();
		for (int i = 0; i < len; i++)
		{
			if (g[v][i] == w)
			{
				return true;
			}
		}
		len = g[w].size();
		for (int i = 0; i < len; i++)
		{
			if (g[w][i] == v)
			{

			}
		}
		return false;
	}
};