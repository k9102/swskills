#include "pch.h"
#include <iostream>
using namespace std;

double S; // �������� ���Ϸ��� ��
double X0; // �ʱ� �ٻ簪
int sol;

// ��ȭ���� �ּ� �� ȸ �������� �� ���� ����� �ٻ񰪿� �����ϴ��� ����ϴ� �Լ�
int cnt_sqrt(void)
{
	int cnt = 0;

	// ����: �Է� ���� S�� X0�� ����Ͽ� �ڵ带 �ۼ��Ͻÿ�
	// �ʿ� �� ���� ������ �����Ͻÿ�

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