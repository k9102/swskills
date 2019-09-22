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
	Input_Data_();		// 입력 함수

	// TODO : 코드를 작성하세요


	int min_loc;
	int min_val = INT_MAX - S;

	for (int i = 0; i < N; i++)
	{

		min_val = min_val + S;
		if (min_val >= C[i])
		{
			min_val = C[i];
			min_loc = i;
		}
		val[min_loc] += min_val * Y[i];
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