#include "pch.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string seed = "1234";
int n = seed.size();
int r = 3;

vector<bool> smap(n);
vector<string> coms;
vector<string> perms;

/*
combination
*/
void Comb(int d=0,string s="")
{
	if (s.size() == r)
	{
		coms.emplace_back(s);
	}
	else
	{
		if (d >= n) return;
		Comb(d + 1, s + seed[d]);
		Comb(d + 1,s);
	}
}

void Comb_()
{
	vector<bool> sel(n);
	fill(end(sel) - r, end(sel), true);

	do {
		string s;
		for (int i = 0; i < size(sel); i++)
		{
			if (sel[i]) s += seed[i];
		}
		coms.push_back(move(s));
	} while (next_permutation(begin(sel), end(sel)));



}

/*
permutation
*/
void Perm(int d, string s)
{
	if (d>=n)
	{
		perms.emplace_back(s);
	}
	else
	{
		for (int i = 0; i < n; i++)
		{
			if (smap[i] == false)
			{
				smap[i] = true;
				Perm(d + 1, s + seed[i]);
				smap[i] = false;
			}
		}
	}
}


void main()
{
	Comb_();

	for (auto v : coms)
	{
		cout << v << endl;
	}
}