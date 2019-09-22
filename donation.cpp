#include "pch.h"
#include <iostream>
#include <algorithm>
#include <tuple>
#include <numeric>
#include <limits.h>


using namespace std;

int N;//직원 수
int M;//기부금 총액
int A[1000010];//직원 별 성과급

void InputData() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}
}

int main() {
	int ans = 0;

	InputData();			//	입력 함수

	//	코드를 작성하세요

	sort(A, A + N);

	int lower=0, upper = 1'000'000'000;
	int mid;
	long long sum;
	while (lower+1 < upper)
	{
		mid = (lower + upper) / 2;

		auto itr = upper_bound(A, A + N, mid);

		sum	= accumulate(itr,A+N, (long long)0);
		sum = sum - (long long)mid * distance(itr, A + N);

		if (sum > M) lower = mid; else upper = mid;
	}

	if (sum > M)
		ans = upper;
	else
		ans = lower;


	cout << ans << endl;	//	정답 출력
	return 0;
}

/*
5 20
4 42 40 26 46

36
*/