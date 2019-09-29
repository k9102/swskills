#include "pch.h"
#include <iostream>
using namespace std;

int N;			//	시험 일수
int h[31];	//	시험 시간
int sol;

void InputData() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> h[i];
	}
}

#include <algorithm>

int main() {

	InputData();						//	입력 함수

	//	최종 계산값이 sol 에 저장될 수 있도록 완성하세요
	int sum=0,sol;
	for (int i = 0; i < N; i++) {

		if (h[i] <3) {
			
		}
		else if (h[i] <= 6) {
			sum += 100;
		}
		else {
			sum += min(500, 50 * (h[i] - 6) + 100);
		}
	}

	if (sum >= 100 * 100)
	{
		sum -= sum / 10;
	}

	sol = sum;
	cout << sol << endl; 		// 정답 출력
	return 0;
}