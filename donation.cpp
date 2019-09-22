#include "pch.h"
#include <iostream>
#include <algorithm>
#include <tuple>
#include <numeric>
#include <limits.h>


using namespace std;

int N;//���� ��
int M;//��α� �Ѿ�
int A[1000010];//���� �� ������

void InputData() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}
}

int main() {
	int ans = 0;

	InputData();			//	�Է� �Լ�

	//	�ڵ带 �ۼ��ϼ���

	sort(A, A + N);

	int lower=0, upper = 1'000'000'100;
	int mid;
	long long sum;
	long long lsum, usum;
	while (lower+1 < upper)
	{
		mid = (lower + upper) / 2;

		auto itr = upper_bound(A, A + N, mid);

		sum	= accumulate(itr,A+N, (long long)0);
		sum = sum - (long long)mid * distance(itr, A + N);

		if (sum >= M)
		{
			lsum = sum;
			lower = mid;
		}
		else
		{
			usum = sum;
			upper = mid;
		}
	}


	if (lsum >= M && usum >= M)
	{
		ans = max(lower, upper);
	}
	else 
	{
		if (lsum >= M)
			ans = lower;
		else
			ans = upper;
	}


	cout << ans << endl;	//	���� ���
	return 0;
}

/*
5 20
4 42 40 26 46

36
*/

/*
10 30
15 28 9 32 29 7 7 21 8 34

23
*/