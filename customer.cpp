#include "pch.h"
#include <iostream>
#include <string>
using namespace std;

int M;					// �ݺ� ���� ȸ��
char S[100000 + 10];	// ���� ���ڿ�

int main(void)
{
	int i;			// ���ڿ� S�� � ���ڸ� ����
	int len;		// ���ڿ� S�� ����
	char r_char;	// �ݺ��Ǵ� ����
	int r_cnt;		// �ݺ� ȸ��

	// ������ �б�
	cin >> M;
	cin >> S;

	// �ڵ� ���� �� ��� ���

	string s = S;
	len = s.length();

	r_char = S[0];
	r_cnt = 1;

	for (i = 1; i <= len; i++)
	{
		if (S[i] == r_char) {
			r_cnt++;
			continue;
		}
		if (r_cnt >= M)
		{
			cout << r_char << "(" << r_cnt << ")";
		}
		else
		{
			for(int j=0;j<r_cnt;j++) cout << r_char;
		}

		r_char = S[i];
		r_cnt = 1;
	}

  
	return 0;
}

/*
4
ABBBBCCAAAAA

AB(4)CCA(5)
*/
