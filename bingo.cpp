#include "pch.h"
#include <iostream>
using namespace std;

int a[5 + 10][5 + 10];	// ������
int b[25 + 10];	// ��ȸ�ڰ� �θ��� ��
int sol;	// �����

int check(void)
{
	int i, j;
	int count = 0;

	//���μ�üũ
	for (i = 0; i < 5; i++)
	{
		for (j = 0; j < 5; j++)
		{
			if (a[i][j] != 0) break;
		}
		if (j == 5) count++;
	}

	// ���μ� üũ
	for (j = 0; j < 5; j++)
	{
		for (i = 0; i < 5; i++)
		{
			if (a[i][j] != 0) break;
		}
		if (i == 5) count++;
	}

	// �� �밢��(�����ϴ�) üũ

	// �� �밢��(�����ϴ�) üũ
	
	for (i = 0; i < 5; i++)
	{
		if (a[i][i] != 0) break;
	}
	if (i == 5) count++;

	for (i = 0; i < 5; i++)
	{
		if (a[i][4-i] != 0) break;
	}
	if (i == 5) count++;

	return count;
}

void recording_bingo(int k)
{	// �������� ������� ��ĵ�Ͽ� k�� ���� ���� ���� ��ġ�� 0���� �ٲ㼭 ǥ��
	int i, j;
	for (i = 0; i < 5; i++)
	{
		for (j = 0; j < 5; j++)
		{
			if (a[i][j] == k)
			{
				a[i][j] = 0;
				return;
			}
		}
	}
}

int solve(void)
{
	int i;
	for (i = 0; i < 25; i++)
	{
		recording_bingo(b[i]);	// ��ȸ�ڰ� �θ� ���� �����ǿ� ǥ��

		if (check() >= 3) break;	// ���� ���� �밢���� üũ 3�� �̻��̸� ����
	}
	return i + 1;	// ���� �� ������ �θ� ��(0���� ���������Ƿ� +1�� ��)
}

int main(void)
{
	int i, j;

	// ������ �Է�
	for (i = 0; i < 5; i++)
	{
		for (j = 0; j < 5; j++)
		{
			cin >> a[i][j];
		}
	}

	// ��ȸ�ڰ� �θ� �� �Է�
	for (i = 0; i < 25; i++)
	{
		cin >> b[i];
	}

	sol = solve();

	cout << sol;

	return 0;
}