// swskills.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"

#include <iostream>
using namespace std;

int N;//���� ��
int P[150000 + 10];//���� ��

void InputData() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> P[i];
	}
}

int C[2][150000 + 10] = {};

int FindMax(int jmp, int pos)
{
	int s, n;
	if (N <= pos)  return 0;
	if (C[jmp % 2][pos] != 0) return C[jmp % 2][pos];


	s = FindMax(jmp + 1, pos + 1);
	s = s + (jmp % 2 == 0 ? P[pos] : -P[pos]);

	n = FindMax(jmp, pos + 1);

	int max = s > n ? s : n;

	C[jmp % 2][pos] = max;
	return max;
}


int main() {
	int ans = -1;

	InputData();			//	�Է� �Լ�

	//	�ڵ带 �ۼ��ϼ���
	ans = FindMax(0, 0);

	cout << ans << endl;	//	���� ���
	return 0;
}


