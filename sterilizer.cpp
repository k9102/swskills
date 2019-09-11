#include "pch.h"
#include <iostream>
using namespace std;

int y[110];		//	살균대상의 y 좌표 배열
int x[110];		//	살균대상의 x 좌표 배열
int N;				//	필터 한 변의 크기
int L;				//	LED의 범위(길이) 
int M;				//	살균대상의 개수
int sol;			//	정답

void Input(void) {
	cin >> N >> L >> M;
	for (int i = 0; i < M; i++)		cin >> y[i] >> x[i];
}

int GermsInRect(int X,int Y,int w,int h)
{
	int cnt = 0;
	for (int i = 0; i < M; i++)
	{
		if (X <= x[i] && x[i] <= X+ w && Y<=y[i] && y[i] <= Y + h) cnt++;
	}

	return cnt;
}

int main(void) {

	Input();

	//	코드를 작성하세요
	int fl_x, fl_y;
	int fl = L / 2;
	int max_cnt = 0;
	for (int i = 1; i < fl; i++)
	{
		fl_x = i;
		fl_y = fl - i;

		for (int n = 0; n < M; n++)
		{
			int X = x[n];
			int Y = y[n];

			int cnt = GermsInRect(x[n], y[n], fl_x, fl_y);
			if (cnt > max_cnt) max_cnt = cnt;
		}

	}
	sol = max_cnt;
	//	정답출력
	printf("%d", sol);

	return 0;
}