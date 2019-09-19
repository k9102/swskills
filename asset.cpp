#include "pch.h"
#include <iostream>
#include <algorithm>
#include <tuple>
using namespace std;

int N;						//	문화재의 개수
int L[1010] = {};
int H[1010] = {};

int FindTallest(int s) 
{
	auto itr = max_element(H + s, H + N);

	return distance(H, itr);
}	

int FindTaller(int ver,int s) 
{
	for (int i = s; i < N; i++)
	{
		if (H[i] > ver)
		{
			return i;
		}
	}

	return -1;
}

#include <vector>
vector<pair<int, int>> vec;

int Solve(void) {
	int area = 0;

	cin >> N;							// 문화재의 개수 입력
	N++;
	
	vec.emplace_back(0, 0);
	for (int i = 1; i < N; i++)
	{
		int h, l;
		cin >> l >> h;
		vec.emplace_back(l, h);
	}

	sort(begin(vec), end(vec), [](auto &a, auto &b) 
	{
		return a.first < b.first;
	});


	for (int i = 0; i < N; i++)
	{
		tie(L[i], H[i]) = vec[i];
	}


	//	코드를 작성하세요

	int her = 0; /*current loc*/
	int ver = 0; /*current height*/
	int s = 0;

	while (s < N)
	{
		int n = FindTaller(ver, s); /*s inclusive*/
		if (n >= 0) 
		{
			area += ver * (L[n]-her);
		}
		else /*not found*/
		{
				n = FindTallest(s);  /*s inclusive*/
				area +=  ver * (L[n] - her);
				area -= (ver - H[n])*(L[n] - her - 1);
		}

		ver = H[n];
		her = L[n];
		s = n+1;
	}

	area += ver;

	return area;
}

int main(void) {
	int area;

	area = Solve(); 				// 문제 풀이

	cout << area << endl;		// 정답 출력
	return 0;
}

/*
6
2 3
9 4
7 7
4 5
5 2
12 6

58
*/

/*
7
2 4
4 6
5 3
8 10
11 4
13 6
15 8

98
*/