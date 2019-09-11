#include "pch.h"
#include <iostream>
using namespace std;

int y[110];		//	��մ���� y ��ǥ �迭
int x[110];		//	��մ���� x ��ǥ �迭
int N;				//	���� �� ���� ũ��
int L;				//	LED�� ����(����) 
int M;				//	��մ���� ����
int sol;			//	����

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

	//	�ڵ带 �ۼ��ϼ���
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
	//	�������
	printf("%d", sol);

	return 0;
}