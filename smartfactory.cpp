#include "pch.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
#include <numeric>

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

int main() {
	long long ans = -1;
	Input_Data();		// 입력 함수

	// TODO : 코드를 작성하세요


	for (int i = N - 1; i >= 0; i--)
	{
		vector<int> cs(C, C + i + 1);
		
		for (int j = 0; j <= i; j++)
		{
			cs[i - j] -= (C[i] - S*j);
		}

		auto itr = min_element(begin(cs), end(cs));
		
		int loc = distance(begin(cs),itr);
		val[loc] += C[loc]*Y[i]+(long long)S*Y[i]*(i-loc);
	}
	
	ans = accumulate(begin(val), end(val), 0l);

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