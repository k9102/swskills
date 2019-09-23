#include "pch.h"
#include <iostream>
#include <string>
#include <vector>

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
void Comb(int d,string s)
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
	Perm(0, "");

	for (auto v : perms)
	{
		cout << v << endl;
	}
}