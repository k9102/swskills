#include "pch.h"


#include <iostream>
#include <limits.h>
#include <algorithm>
#include <tuple>
using namespace std;

int N;//지도 크기
char map[110][110];//지도 정보

int road[100][100];

void Input_Data() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> map[i];
	}
}

enum {DN,DW,DS,DE};

pair<int, int> mv[4] = { {-1,0},{0,1},{1,0},{0,-1} };

int ndir[4] = { 2,3,0,1 };

bool InPt(int y,int x) {
	if (y >= 0 && y < N && x >= 0 && x < N)
		return true;

	return false;
}

void traverse(int y,int x,int dir)
{
	cout << y <<" "<< x <<endl;
	for (int i = 0; i < 3; i++)
	{
		dir = ++dir % 4;
		auto [ny, nx] = mv[dir];
		ny += y;
		nx += x;

		if (!InPt(ny, nx)) continue;

		if (road[ny][nx]==INT_MAX || road[ny][nx] > road[y][x] + map[ny][nx])
		{
			road[ny][nx] = road[y][x] + (map[y][x]-'0');
			traverse(ny, nx, ndir[dir]);
		}
	}
	
}

int main() {
	int ans = -1;
	Input_Data();		//	입력 함수

	//	코드를 작성하세요
	for (int i = 0; i < N; i++)
	{
		for (int j = 0;j < N;j++)
		{
			road[i][j] = INT_MAX;
		}

	}
	road[0][0] = 0;
	traverse(0,0,DE);

	ans = road[N - 1][N - 1];
	cout << ans << endl;	//	정답 출력
	return 0;
}

/*
3
041
253
620

8
*/