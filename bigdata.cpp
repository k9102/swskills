
#include "pch.h"
#include <iostream>
#include <cstring>
using namespace std;

#include <vector>
#include <tuple>
#include <map>
#include <algorithm>
#include <string>
int N;							//	�𵨸��� ����
char str[10010][21];	//	�𵨸� ����


map<string, int> idx;
vector<pair<string, vector<int>>>  tbl;

void Solve() {

	//	�ڵ带 �ۼ��ϼ���

	for (int i = 0; i < N; i++)
	{
		auto& m = idx[str[i]];
		if (m == 0)
		{
			tbl.emplace_back(str[i], vector<int>{i + 1});
			m = tbl.size();
		}
		else
		{
			tbl[m - 1].second.push_back(i + 1);
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
		for (const auto &[name, vec] : tbl)
		{
			if (acc >= N / 2)
				break;
			if (vec.size() < 2)
				break;

			cout << name;
			for (const auto pos : vec)
			{
				cout << " " << pos;
			}
			cout << endl;

			acc += vec.size();
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

	InputData();		//	�Է� �Լ�

	Solve();				//	���� Ǯ��

	return 0;
}