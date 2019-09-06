
#include "pch.h"
#include <iostream>
#include <stdlib.h>
using namespace std;

int N;//제품 수
int M;//제품 종류 수
int ID[100000 + 10];//제품 ID

void InputData() {
	int i;
	cin >> N >> M;
	for (i = 1; i <= N; i++) {
		cin >> ID[i];
	}
}


void InputData_() {
	int i;
	N = 100000;
	M = 9;
	for (i = 1; i <= N; i++) {
		ID[i] = (rand() % M) + 1;
	}
}

int sel[9] = {};
int nums[9+1] = {};

template<int N> void print(int (&x)[N])
{
	for (int i = 0; i < N; i++)
	{
		cout << x[i] << ",";
	}
	cout << endl;
}

int min_val = 1000000;


void permute(int d,int cur,int mv)
{
	if (d == M)
	{
		if (mv < min_val)
		{
			min_val = mv;
		}
	}
	else
	{
		for (int i = 0; i < M; i++)
		{
			if (sel[i] == 0)
			{
				int nx_mv = mv;
				int nx_cur = cur;

	
				for (int j = 0; j < nums[i + 1]; j++)
				{
					if (ID[nx_cur++] != i + 1)
					{
						nx_mv++;
					}
				}

				if (nx_mv > min_val) continue;

				sel[i] = 1;
				permute(d+1,nx_cur, nx_mv);
				sel[i] = 0;
			}
		}
	}
}


int main() {
	int ans = -1;

	InputData_();//입력 함수

	for (int i = 1; i <=N; i++)
	{
		nums[ID[i]]++;
	}

	
	//	코드를 작성하세요
	permute(0,1,0);

	ans = min_val;

	cout << ans << endl;
	return 0;
}
/*
7 2
1 2 2 2 1 2 1
*/