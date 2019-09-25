#include "pch.h"
#include <iostream>
using namespace std;

int N;	//	지도크기
char map[110][110];	//	지도데이터
bool vis[110][110] = {};


bool GetV(int x, int y)
{
	if (x < 0 || y < 0 || x >= N || y >= N)
		return true;

	return vis[y][x];
}

int mv[8][2] = {
	{-1,-1},{0,-1},{1,-1},{1,0},
	{1,1},{0,1},{-1,1},{-1,0}
};

void Traverse(int x,int y)
{
	int nx, ny;

	vis[y][x] = true;
	
	for (int i = 0; i < 8; i++)
	{
		nx =  x + mv[i][0];
		ny =  y + mv[i][1];

		if (GetV(nx, ny) == false && map[ny][nx] == '1')
		{
			Traverse(nx, ny);
		}
	}
}

int Solve() {

	int cnt = 0;
	for(int y=0;y<N;y++)
	for (int x = 0; x < N; x++)
	{
		if (GetV(x, y)==false && map[y][x] == '1')
		{
			Traverse(x, y);
			cnt++;
		}
	}
	return cnt;
}

void Input_Data() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> map[i];
	}
}

int main() {
	int ans = -1;
	Input_Data();
	ans = Solve();
	cout << ans << endl;
	return 0;
}


/*
6
000000
001011
010100
001000
010010
000010

2
*/