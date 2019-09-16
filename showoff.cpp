#include "pch.h"
#include <iostream>

#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

int N;//���� ��
int S;//���� ���� ��ȣ
int M;

void InputData() {
	cin >> N >> S >> M;
}

int main() {

	InputData();//	�Է� �Լ�

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


	//	�ڵ带 �ۼ��ϼ���


	return 0;
}

/*
7 1 4

4 1 6 5 7 3 2
*/