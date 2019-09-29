#include "pch.h"
#include <iostream>
#include <algorithm>
using namespace std;

#define MAX_N (95)
int matrix[MAX_N][MAX_N] = {};

// 작성할 함수
void Make_Magic_Square(int N)
{
	int x=N/2, y=0;
	int c = 1;
	do
	{
		matrix[y][x] = c;

		if (c%N == 0) {
			if (++y >= N) y = 0;
		}
		else {
			if (--y < 0) y = N-1;
			if (--x < 0) x = N-1;
		}
		c++;
	} while (matrix[y][x] == 0);
}

void Print_Complete_Matrix(int N)
{
	int r, c;
	for (r = 0; r < N; r++)
	{
		for (c = 0; c < N; c++)
		{
			cout << matrix[r][c] << " ";
		}
		cout << endl;
	}
}

int main(void)
{
	int N;

	// 입력 받는 부분
	cin >> N;

	// 마방진 완성 코드
	Make_Magic_Square(N);

	// 마방진 출력
	Print_Complete_Matrix(N);

	return 0;
}