#include "pch.h"
#include <cstring>
#include <iostream>
using namespace std;

// ��Ŷ Ÿ���� ���� ����
#define TYPE_START 0
#define TYPE_DATA 1
#define TYPE_END 2

int N; // ���ڿ��� ����
int M; // �������� �ִ� ����
unsigned char str[10 + 10][64 + 10]; // ���ڿ����� ������ �迭
unsigned char pkt[4 + 64 + 10]; // ��Ŷ �迭
int sol; // ���۵� ��� ��Ŷ���� ����Ʈ ������ ���� ��

// ��Ŷ�� �����ϴ� �Լ�
// ���� ������ �̷������ �ʰ� ��� ��Ŷ�� �� ����Ʈ�� ���� ���� ��� �� ������
// len�� ������ ��Ŷ�� ����
int send_pkt(int len)
{
	int i;
	int sum = 0;

	for (i = 0; i < len; i++) {
		sum += pkt[i];
	}

	return sum;
}

// ��Ŷ�� ����� �Լ�
// type�� ��Ŷ Ÿ��
// num�� ���ڿ��� ��ȣ
int make_pkt(int type, int num)
{
	int i;
	int idx = 0; // ��Ŷ �迭�� ��� ��ȣ
	int len; // ���� ���ڿ��� ����
	int len2; // 4�� ����� ������ ���ڿ��� ����
	static int seq; // ��Ŷ ��ȣ

	pkt[1] = type; // ��Ŷ Ÿ��
	pkt[3] = 0; // RSV

	idx = 4;
	int al;

	switch (type) {
	case TYPE_START:
		seq = 0; // ��Ŷ ��ȣ �ʱ�ȭ
		pkt[2] = 0; // ������ ����: ������ 0
		break;

	case TYPE_DATA:
		seq++; // ��Ŷ ��ȣ ����
		len = strlen((char *)str[num]); // ������ ���� = ���ڿ��� ����

		if (len > M)
		{
			len = M;
		}

		al = 0;
		if (len % 4 != 0)
		{
			al = 4 - (len % 4);
		}


		// ���ڿ� ����
		for (i = 0; i < len; i++) {
			pkt[idx++] = str[num][i];
		}

		for (int j = 0; j < al; j++) {
			pkt[idx++] = 0xff;
		}

		pkt[2] = len + al;

		break;

	case TYPE_END:
		seq++; // ��Ŷ ��ȣ ����
		pkt[2] = 0; // ������ ����: ������ 0
		break;

	default:
		break;
	}

	pkt[0] = seq; // ��Ŷ ��ȣ
	return idx; // ��Ŷ ���� ����
}

// ��Ŷ�� ����� �����ϴ� �Լ�
int handle_pkt(void)
{
	int i;
	int len;
	int sum;

	// START ��Ŷ
	len = make_pkt(TYPE_START, 0);
	sum = send_pkt(len);

	// DATA ��Ŷ
	for (i = 0; i < N; i++) {
		len = make_pkt(TYPE_DATA, i);
		sum += send_pkt(len);
	}

	// END ��Ŷ
	len = make_pkt(TYPE_END, 0);
	sum += send_pkt(len);

	return sum;
}

int main(void)
{
	int i;

	cin >> N >> M;
	for (i = 0; i < N; i++) {
		cin >> str[i];
	}

	sol = handle_pkt();


	cout << "0x" << hex << sol;

	return 0;
}
