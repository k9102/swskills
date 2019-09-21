#include "pch.h"
#include <iostream>
#include <map>
#include <algorithm>
#include <iterator>
#include <limits.h>

using namespace std;

int N;//직원 수
int T;//산책 시간(분단위)
int P[100000 + 10];//직원 출발 위치
int S[100000 + 10];//직원 산책 속도(분당)

map<int, int> spd_;

void InputData() {
	cin >> N >> T;
	for (int i = 0; i < N; i++) {
		cin >> P[i] >> S[i];
	}
}

int main() {
	int ans = -1;

	InputData();			//	입력 함수

	//	코드를 작성하세요

	for (int i = 0; i < N; i++)
	{
		if (spd_.find(P[i]) == end(spd_))
		{
			spd_[P[i]] = S[i];
		}
		else
		{
			spd_[P[i]] = min(S[i], spd_[P[i]]);
		}
	}
	
	long long nearest_loc = LLONG_MAX;
	int grp = 0;
	for_each(rbegin(spd_), rend(spd_), [&nearest_loc,&grp](auto speed) {
		auto[p, s] = speed;
		long long loc = p + (long long)s * T;

		if (loc < nearest_loc)
		{
			grp++;
			nearest_loc = loc;
		}

	});

	ans = grp;

	cout << ans << endl;	//	정답 출력
	return 0;
}

/*
5 3
0 1
1 2
2 3
3 2
6 1

3*/