#include "pch.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

const string seed = "1234";
int n = seed.size();
int r = 3;

vector<bool> smap(n);
vector<string> rets;


/*
combination
*/
void Comb(int d=0,string s="")
{
	if (s.size() == r)
	{
		rets.emplace_back(s);
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
	fill(begin(sel), begin(sel)+r, true);

	do {
		string s;
		for (int i = 0; i < size(sel); i++)
		{
			if (sel[i]) s += seed[i];
		}
		rets.push_back(move(s));
	} while (prev_permutation(begin(sel), end(sel)));
}

/*
permutation
*/
void Perm(int d=0, string s="")
{
	if (d>=n)
	{
		rets.emplace_back(s);
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

void Perm_()
{
	string s = seed;

	sort(begin(s), end(s));

	do {
		rets.emplace_back(s);
	} while (next_permutation(begin(s), end(s)));
}


void main()
{
	vector<string> rets_;
	Perm_();
	rets_ = rets;
	rets.clear();
	Perm();

	if (rets_ == rets)
	{
		cout << "======" << endl;
	}

	for (auto v : rets)
	{
		cout << v << endl;
	}
}