#include "pch.h"
#include <iostream>
#include <algorithm>
#include <map>
#include <tuple>
#include <limits.h>

using namespace std;

int N;				//	����� ����
int P[310];		//	P[i]: i ����� ����� �� ��� ����

map<tuple<int, int, int>,int> cache;

int TakeStep(int i,int jump,int seq)
{
	int o, x;
	int ret;

	if(cache.find({i,jump,seq}) != end(cache))
	{
		return cache[{ i, jump, seq}];
	}


	if (i == N - 1)
	{
		if (seq == 2)
			ret = INT_MIN;
		else
			ret = P[i];
	}
	else {
		if (jump == 1)
		{
			ret = TakeStep(i + 1, 0, 1)+P[i];
		}
		else /*jump==0*/
		{
			if (seq == 2)
			{
				ret = TakeStep(i + 1, 1, 0);
			}
			else
			{
				x = TakeStep(i + 1, 1, 0);
				o = TakeStep(i + 1, 0, seq + 1) + P[i];
				ret = max(o, x);
			}
		}
	}

	cache[{i, jump, seq}] = ret;


	return ret;
}

int Solve() {
	int sol = 0;

	//	�ڵ带 �ۼ��ϼ���
	sol = TakeStep(0, 0, 0);


	return sol;
}

void InputData() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> P[i];
	}
}

int main() {

	InputData();					//	�Է� �Լ�

	int sol = Solve();

	cout << sol << endl;		//	���� ���
	return 0;
}


/*
6
10
20
15
25
10
20

75
*/