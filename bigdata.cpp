
#include "pch.h"
#include <iostream>
#include <cstring>
using namespace std;

#include <vector>
#include <tuple>
#include <map>
#include <algorithm>
#include <string>
int N;							//	모델명의 개수
char str[10010][21];	//	모델명 저장


map<string, int> idx;
vector<pair<string, vector<int>>>  tbl;

void Solve() {

	//	코드를 작성하세요

	for (int i = 0; i < N; i++) 
	{
		auto& m = idx[str[i]];
		if (m == 0)
		{
			tbl.emplace_back(str[i], vector<int>{i+1});
			m = tbl.size();
		}
		else
		{
			tbl[m-1].second.push_back(i + 1);
		}
	
	}

	stable_sort(begin(tbl), end(tbl), [](const auto &a, const auto &b) 
	{
		return (a.second.size() > b.second.size());
	});

	if (tbl.size() == N)
	{
		cout << "unique" << endl;
	}
	else
	{
		int acc = 0;
		int i = 0;
		while( acc < N / 2  && i < tbl.size())
		{
			const auto p = tbl[i++];

			if (p.second.size() < 2)
				break;

			cout << p.first;
			for (int j = 0; j < p.second.size(); j++)
			{
				cout << " " <<p.second[j];
			}
			cout << endl;
			acc += p.second.size();
		}
		
	}
}

void InputData() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> str[i];
	}
}



int main() {

	InputData();		//	입력 함수

	Solve();				//	문제 풀이

	return 0;
}
