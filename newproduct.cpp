
#include "pch.h"
#include <iostream>
using namespace std;

int a[50 + 10];		//	카드뒷면 숫자를 저장하는 배열
int N;					//	카드 개수
int M;					//	신제품용량
int sol;				//	정답

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


	cout << sol;	//	정답 출력

	return 0;
}

/*
6 60
10 10 15 15 20 20

5
*/