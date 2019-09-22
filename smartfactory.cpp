#include "pch.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
#include <numeric>
#include <limits.h>

using namespace std;

int N; //��
int S; //�������
int C[50010]; //����
int Y[50010]; //�뷮

long long val[50010] = {};


void Input_Data(void) {
	int i;
	cin >> N >> S;
	for (int i = 0; i < N; i++) {
		cin >> C[i] >> Y[i];
	}
}


void Input_Data_(void) {
	int i;
	N = 50000;
	S = 5;
	for (int i = 0; i < N; i++) {
		C[i] = rand() % 5000 + 1;
		Y[i] = rand() % 10000;
	}
}


int main() {
	long long ans = -1;
	Input_Data();		// �Է� �Լ�

	// TODO : �ڵ带 �ۼ��ϼ���


	for (int i = N - 1; i >= 0; i--)
	{
		int loc;
		int min_val = INT_MAX;
		for (int j = 0; j <= i; j++)
		{
			int v = C[i - j] - (C[i] - S * j);
			if (min_val > v)
			{
				loc = i-j;
				min_val = v;
			}
		}
		val[loc] += C[loc]*Y[i]+(long long)S*Y[i]*(i-loc);
	}
	
	ans = accumulate(begin(val), end(val), (long long)0);

	cout << ans << endl;	// ���� ���
	return 0;
}


/*
4 5
88 200
89 400
97 300
91 500

126900
*/