#include "pch.h"
#include <iostream>

#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

int N;//직원 수
int S;//시작 직원 번호
int M;

void InputData() {
	cin >> N >> S >> M;
}

int main() {

	InputData();//	입력 함수

	vector<int> bin(N);
	std::iota(begin(bin), end(bin),1);

	int m = M - 1;
	int s = S-1;
	int n;
	while ((n=bin.size()) != 0)
	{
		s = (s + m) % n;
		cout << bin[s] << " ";
		bin.erase(begin(bin) + s);
		s %= n;
	}


	//	코드를 작성하세요


	return 0;
}

/*
7 1 4

4 1 6 5 7 3 2
*/