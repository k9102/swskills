#include "pch.h"
#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
#include <string>

using namespace std;

int n_;
char str_[50000 + 1];
vector<tuple<string,int>> nms_;

int main() {

	cin >> str_;
	cin >> n_;
	
	char name[100 + 1];

	for (int i = 0; i < n_; i++)
	{
		cin >> name;
		nms_.emplace_back(name,0);
	}

	int len = string{ str_ }.size();

	for (auto &p:nms_)
	{
		auto &[nm, cnt] = p;
		
		for (int i = 0; i <= len - nm.size(); i++)
		{
			char tmp = str_[i + nm.size()];
			str_[i + nm.size()] = 0;
			if (nm == str_+i)
			{
				cnt++;
			}
			str_[i + nm.size()] = tmp;
		}
	}

	stable_sort(begin(nms_), end(nms_), [](auto &a,auto &b) 
	{
		return get<1>(a) > get<1>(b);
	});

	auto [nm,cnt]= nms_[0];
	if (cnt == 0)
	{
		cout << "null" << endl;
	}
	else
	{
		cout << nm << endl;
	}

	return 0;
}

/*
aaaabbb
2
aaa
bb

aaa
*/