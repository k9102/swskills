// roof.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
using namespace std;

int N;//�ǹ� ��
int H[80010];//�ǹ� ����
int V[80010];

void Input_Data(void) {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> H[i];
	}
}

#include <algorithm>
void Input_Data_(void) {
	N = 80000;
	for (int i = 0; i < N; i++) {
		H[i]=i;
	}
}

int main() {
	long long ans = -1;
	Input_Data();		//	�Է� �Լ�

	//	�ڵ带 �ۼ��ϼ���

	V[N - 1] = 0;
	ans = 0;
	for (int i = N - 2; i >= 0; i--)
	{
		int j = i + 1;
		
		while(j < N)
		{
			if (H[i] > H[j]) j += V[j] + 1; else break;
		}
		
		int cnt = j - (i + 1);

		V[i] = cnt;
		ans += cnt;
	}

	cout << ans << endl;	//	���� ���
	return 0;
}


/*
6
5
2
4
2
6
1
*/
