
#include "pch.h"
#include <iostream>
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

int seq[9];
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

int CalMove(int *seq)
{
	int cur = 1;
	int mv = 0;
	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < nums[seq[i]]; j++)
		{
			if (ID[cur++] != seq[i])
			{
				mv++;
			}
		}
	}
	return mv;
}

void permute(int d)
{
	if (d == M)
	{
		int mv = CalMove(seq);
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
				seq[d] = i+1;
				
				sel[i] = 1;
				permute(d+1);
				sel[i] = 0;
			}
		}
	}
}


int main() {
	int ans = -1;

	InputData();//입력 함수

	for (int i = 1; i <=N; i++)
	{
		nums[ID[i]]++;
	}

	
	//	코드를 작성하세요
	permute(0);

	ans = min_val;

	cout << ans << endl;
	return 0;
}
/*
7 2
1 2 2 2 1 2 1
*/