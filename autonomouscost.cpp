#include "pch.h"
#include <iostream>
using namespace std;

int N;			//	���� �ϼ�
int h[31];	//	���� �ð�
int sol;

void InputData() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> h[i];
	}
}

#include <algorithm>

int main() {

	InputData();						//	�Է� �Լ�

	//	���� ��갪�� sol �� ����� �� �ֵ��� �ϼ��ϼ���
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
	cout << sol << endl; 		// ���� ���
	return 0;
}