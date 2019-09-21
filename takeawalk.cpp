#include "pch.h"
#include <iostream>
#include <map>
#include <algorithm>
#include <iterator>
#include <limits.h>

using namespace std;

int N;//���� ��
int T;//��å �ð�(�д���)
int P[100000 + 10];//���� ��� ��ġ
int S[100000 + 10];//���� ��å �ӵ�(�д�)

map<int, int> spd_;

void InputData() {
	cin >> N >> T;
	for (int i = 0; i < N; i++) {
		cin >> P[i] >> S[i];
	}
}

int main() {
	int ans = -1;

	InputData();			//	�Է� �Լ�

	//	�ڵ带 �ۼ��ϼ���

	for (int i = 0; i < N; i++)
	{
		if (spd_.find(P[i]) == end(spd_))
		{
			spd_[P[i]] = S[i];
		}
		else
		{
			spd_[P[i]] = min(S[i], spd_[P[i]]);
		}
	}
	
	long long nearest_loc = LLONG_MAX;
	int grp = 0;
	for_each(rbegin(spd_), rend(spd_), [&nearest_loc,&grp](auto speed) {
		auto[p, s] = speed;
		long long loc = p + (long long)s * T;

		if (loc < nearest_loc)
		{
			grp++;
			nearest_loc = loc;
		}

	});

	ans = grp;

	cout << ans << endl;	//	���� ���
	return 0;
}

/*
5 3
0 1
1 2
2 3
3 2
6 1

3*/