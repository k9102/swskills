#include "pch.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
#include <numeric>
#include <limits.h>

using namespace std;

int N; //일
int S; //보관비용
int C[50010]; //가격
int Y[50010]; //용량

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
	Input_Data();		// 입력 함수

	// TODO : 코드를 작성하세요


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

	cout << ans << endl;	// 정답 출력
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