#include "pch.h"
#include <iostream>
using namespace std;

int a[5 + 10][5 + 10];	// 빙고판
int b[25 + 10];	// 사회자가 부르는 수
int sol;	// 결과값

int check(void)
{
	int i, j;
	int count = 0;

	//가로선체크
	for (i = 0; i < 5; i++)
	{
		for (j = 0; j < 5; j++)
		{
			if (a[i][j] != 0) break;
		}
		if (j == 5) count++;
	}

	// 세로선 체크
	for (j = 0; j < 5; j++)
	{
		for (i = 0; i < 5; i++)
		{
			if (a[i][j] != 0) break;
		}
		if (i == 5) count++;
	}

	// ↙ 대각선(좌측하단) 체크

	// ↘ 대각선(우측하단) 체크
	
	for (i = 0; i < 5; i++)
	{
		if (a[i][i] != 0) break;
	}
	if (i == 5) count++;

	for (i = 0; i < 5; i++)
	{
		if (a[i][4-i] != 0) break;
	}
	if (i == 5) count++;

	return count;
}

void recording_bingo(int k)
{	// 빙고판을 순서대로 스캔하여 k와 같은 값을 갖는 위치에 0으로 바꿔서 표시
	int i, j;
	for (i = 0; i < 5; i++)
	{
		for (j = 0; j < 5; j++)
		{
			if (a[i][j] == k)
			{
				a[i][j] = 0;
				return;
			}
		}
	}
}

int solve(void)
{
	int i;
	for (i = 0; i < 25; i++)
	{
		recording_bingo(b[i]);	// 사회자가 부른 수를 빙고판에 표시

		if (check() >= 3) break;	// 가로 세로 대각선을 체크 3개 이상이면 빙고
	}
	return i + 1;	// 빙고 될 때까지 부른 수(0부터 시작했으므로 +1을 함)
}

int main(void)
{
	int i, j;

	// 빙고판 입력
	for (i = 0; i < 5; i++)
	{
		for (j = 0; j < 5; j++)
		{
			cin >> a[i][j];
		}
	}

	// 사회자가 부른 수 입력
	for (i = 0; i < 25; i++)
	{
		cin >> b[i];
	}

	sol = solve();

	cout << sol;

	return 0;
}