#include "pch.h"
#include <iostream>
#include <algorithm>
using namespace std;

int arr[25];//안테나 커버리지 값을 저장할 배열
int N;//설치할 안테나의 갯수

//작성할 함수
int Antenna_Count(double p1_, double p2_)
{
	int i, cnt = 0;
	double len;
	double sum = 0;

	auto[p1, p2] = minmax(p1_, p2_);

	if (p1 == p2) return -1;
	if (p2 < 0)  return -1;
	if (p1 > 0) return -1;

	len = p2 - p1;


	for (i = 0; i < N; i++)
	{
		sum += arr[i];
	}

	if (len > (double)(sum + 0.3))
		return -1;

	sum = 0;
	for (i = 0; i < N; i++)
	{
		if (sum + 0.3 < len)
		{
			sum += arr[i];
			cnt++;
		}
	}

	return cnt;
}

int main(void)
{
	int sol;
	double point_1, point_2;

	//입력받는부분
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	cin >> point_1 >> point_2;


	//설치갯수 판단
	sol = Antenna_Count(point_1, point_2);

	if (sol == -1)
		cout << "Impossible" << endl;
	else
		cout << sol << endl;

	return 0;
}
