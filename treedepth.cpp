#include "pch.h"
#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
#include <limits.h>

using namespace std;


int max_depth_ = 0;
int min_depth = INT_MAX;
vector<vector<int>> vs_;

void Traverse(int cur,int depth)
{
	if (vs_[cur].size() == 0) /*leaf*/
	{
		max_depth_ = max(depth,max_depth_);
		min_depth = min(depth, min_depth);
		return;
	}
	else
	{
		for (auto c : vs_[cur])
		{
			Traverse(c, depth + 1);
		}
	}
}

int main() {

	int V, E;

	cin >> V >> E;

	vs_.resize(V);

	for (int i = 0; i < E; i++)
	{
		int p, c;

		cin >> p >> c;
		vs_[p].emplace_back(c);
	}

	Traverse(0, 0);

	cout << max_depth_ - min_depth << endl;
	return 0;
}


/*
6 5
0 1
1 2
2 3
2 4
0 5

2
*/