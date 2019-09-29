#include "pch.h"
#include <iostream>

using namespace std;

int GCD(int m, int n);

// �ۼ��ؾ� �� �Լ�
int GCD(int m, int n)
{
	int r;
	if (n == 0) return m;

	while (1)
	{
		r = m % n;
		if (r == 0) 	return n;
		else { m = n; n = r; }
	}

	return 0;
}

int main(void)
{
	int m, n, r;

	// �Է� �޴� �κ�
	cin >> m >> n;

	// ū���� ���� m�� ����
	if (m < n)
	{
		r = m; m = n; n = r;
	}

	r = GCD(m, n);

	cout << r;
}