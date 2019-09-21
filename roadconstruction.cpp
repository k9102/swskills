#include "pch.h"


#include <iostream>
#include <limits.h>
#include <algorithm>
#include <tuple>
using namespace std;

int N;//���� ũ��
char map[110][110];//���� ����

int road[100][100];

void Input_Data() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> map[i];
	}
}


pair<int, int> mv[4] = { {-1,0},{0,1},{1,0},{0,-1} };

bool InPt(int y,int x) {
	if (y >= 0 && y < N && x >= 0 && x < N)
		return true;

	return false;
}

void traverse(int y,int x)
{
	for (int i = 0; i < 4; i++)
	{
		auto [ny, nx] = mv[i];
		ny += y;
		nx += x;

		if (!InPt(ny, nx)) continue;
		int nval = road[y][x] + (map[ny][nx] - '0');

		if (road[ny][nx] > nval)
		{
			if (nval < road[N - 1][N - 1])
			{
				road[ny][nx] = nval;
				traverse(ny, nx);
			}
		}
	}
	
}

int main() {
	int ans = -1;
	Input_Data();		//	�Է� �Լ�

	//	�ڵ带 �ۼ��ϼ���
	for (int i = 0; i < N; i++)
	{
		for (int j = 0;j < N;j++)
		{
			road[i][j] = INT_MAX;
		}

	}
	road[0][0] = 0;
	traverse(0,0);

	ans = road[N - 1][N - 1];
	cout << ans << endl;	//	���� ���
	return 0;
}

/*
3
041
253
620

8
*/