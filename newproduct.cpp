
#include "pch.h"
#include <iostream>
using namespace std;

int a[50 + 10];		//	ī��޸� ���ڸ� �����ϴ� �迭
int N;					//	ī�� ����
int M;					//	����ǰ�뷮
int sol;				//	����

void Input(void) {
	cin >> N >> M;
	for (int i = 0; i < N; i++) cin >> a[i];
}

#include <vector>
#include <algorithm>
int main(void) {

	Input();

	sol = 0;
	vector<bool> perm(N, false);
	fill(end(perm) - 4, end(perm), true);

	do
	{
		int sum = 0;
		for (int i = 0; i < N; i++)
		{
			if (perm[i] == true) sum += a[i];
		}
		if (sum == M)  sol++;
	} while (next_permutation(begin(perm), end(perm)));


	cout << sol;	//	���� ���

	return 0;
}

/*
6 60
10 10 15 15 20 20

5
*/