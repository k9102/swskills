
#include "pch.h"
#include <iostream>
using namespace std;

int N;//정사각형 지도 크기
int X, Y;//수돗물 공급되는 시작 좌표, 가로, 세로
int map[20][20];//지도 정보

//NSEW



int pipe[12][4] = 
{
   /*N S E W*/
	{0,0,0,0},
	{0,0,1,1},
	{1,1,0,0},
	{0,1,1,0},
	
	{0,1,0,1},
	{1,0,0,1},
	{1,0,1,0},
	{1,1,1,0},
	
	{0,1,1,1},
	{1,1,0,1},
	{1,0,1,1},
	{1,1,1,1}
};

enum {NN,SS,EE,WW};

int GetP(int x, int y)
{
	if (x < 0 || x >= N || y < 0 || y >= N) return 0;
	
	return map[y][x];
	
}

int road[20][20] = {};//지도 정보

void traverse(int x,int y)
{
	
	int n = GetP(x, y - 1);
	int s = GetP(x, y + 1);
	int w = GetP(x-1, y);
	int e = GetP(x+1, y);

	road[y][x] = 1;

	int c = map[y][x];

	if (pipe[c][NN] && pipe[n][SS] && road[y-1][x] != 1)
	{
		traverse(x, y-1);
	}

	if (pipe[c][SS] && pipe[s][NN] && road[y+1][x] != 1)
	{
		traverse(x, y+1);
	}

	if (pipe[c][WW] && pipe[w][EE] && road[y][x-1] != 1)
	{
		traverse(x-1, y);
	}

	if (pipe[c][EE] && pipe[e][WW] && road[y][x+1] != 1)
	{
		traverse(x+1, y);
	}

}

void Input_Data(void) {
	char str[20];
	cin >> N;
	cin >> X >> Y;
	for (int i = 0; i < N; i++) {
		cin >> str;
		for (int j = 0; j < N; j++) {
			if (str[j] < 'A') map[i][j] = str[j] - '0';
			else map[i][j] = str[j] - 'A' + 10;
		}
	}
}


int main() {
	int ans = -1;
	Input_Data();		//	입력 함수


	//	코드를 작성하세요
	traverse(X, Y);

	ans = 0;

	for (int y = 0; y < N; y++)
	{
		for (int x = 0; x < N; x++)
		{

			cout << road[y][x] << " ";
;			if (road[y][x] == 0 && map[y][x] != 0)
			{
				ans++;
			}
		}
		cout << endl;
	}

	cout << ans << endl;	//	정답 출력
	return 0;
}
