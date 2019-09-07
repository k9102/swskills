
#include "pch.h"
#include <iostream>
#include <stdlib.h>
#include <algorithm>
using namespace std;

int N;//占쏙옙품 占쏙옙
int M;//占쏙옙품 占쏙옙占쏙옙 占쏙옙
int ID[100000 + 10];//占쏙옙품 ID

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

int sel = 0;
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

#include <map>

map<int,int> C;

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
			if ((sel & (1<<i)) == 0)
			{
				int nx_mv = mv;
				int nx_cur = cur;

				int k = (sel<<8)|((d<<4)+i);
				if(C.find(k)==end(C))
				{
					for (int j = 0; j < nums[i + 1]; j++)
					{
						if (ID[nx_cur++] != i + 1)
						{
							nx_mv++;
						}
					}
					C[k] = nx_mv - mv;
				}
				else
				{
					nx_mv = mv + C[k];
					nx_cur = cur + nums[i+1];
				}

				if (nx_mv > min_val) continue;

				sel|=(1<<i);
				permute(d+1,nx_cur, nx_mv);
				sel^=(1<<i);
			}
		}
	}
}


int main() {
	int ans = -1;

	InputData_();//占쌉뤄옙 占쌉쇽옙

	for (int i = 1; i <=N; i++)
	{
		nums[ID[i]]++;
	}

	
	//	占쌘드를 占쌜쇽옙占싹쇽옙占쏙옙
	permute(0,1,0);

	ans = min_val;

	cout << ans << endl;
	return 0;
}
/*
7 2
1 2 2 2 1 2 1
*/