#include "pch.h"
#include <iostream>
using namespace std;

double S; // 제곱근을 구하려는 수
double X0; // 초기 근사값
int sol;

// 점화식을 최소 몇 회 적용했을 때 가장 가까운 근삿값에 수렴하는지 계산하는 함수
int cnt_sqrt(void)
{
	int cnt = 0;

	// 구현: 입력 받은 S와 X0를 사용하여 코드를 작성하시오
	// 필요 시 로컬 변수를 선언하시오

	double xn=X0;
	double xo;

	do {
		cnt++;
		xo = xn;
		xn = (xn + S / xn) / 2;
	} while (xo != xn);

	return cnt;
}

int main(void)
{
	cin >> S >> X0;

	sol = cnt_sqrt();

	cout << sol;

	return 0;
}