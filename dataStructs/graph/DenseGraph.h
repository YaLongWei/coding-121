#pragma once

#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include <cassert>

using namespace std;

//≥Ì√‹Õº--¡⁄Ω”æÿ’Û
class DenseGraph
{
private:
	int n, m;
	bool directed;
	vector<vector<bool>> g;


public:
	DenseGraph(int n, bool directed)
	{
		this->n = n;
		this->m = 0;
		this->directed = directed;
		
		for (int i = 0; i < n; i++)
		{
			g.push_back(vector<bool>(n, false));
		}
	}
	~DenseGraph()
	{

	}
	int V()
	{
		return n;
	}
	int	E()
	{
		return m;
	}
	//ÃÌº”“ªÃı±ﬂ
	void addEdge(int v, int w)
	{
		assert(v >= 0 && v < n);
		assert(w >= 0 && w < n);
		
		if (hasEdge(v, w))
		{
			return;
		}
		g[v][w] = true;	
		if (!directed)
		{
			g[w][v] = true;
		}
		m++;
	}
	//≈–∂œ±ﬂ «∑Ò¥Ê‘⁄
	bool hasEdge(int v, int w)
	{
		assert(v >= 0 && v < n);
		assert(w >= 0 && w < n);
		return g[v][w];
	}
};