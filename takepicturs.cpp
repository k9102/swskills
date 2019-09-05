
#include "pch.h"

#include <iostream>
#include <algorithm>
#include <set>
#include <map>


using namespace std;

int N;//��ǰ ��
struct st {
	int X, ID;//��ġ, ���̵�
};
st A[50010];

void InputData() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> A[i].X >> A[i].ID;
	}
}


set<int> ids;
map<int, int> m;

int GetSize(int start)
{
	set<int> rec;

	for (int i = start; i < N;i++)
	{
		rec.insert(A[i].ID);
		if (rec.size() == ids.size())
		{
			return A[i].X - A[start].X;
		}
	}

	return INT16_MAX;
}

int main() {
	int ans = -1;

	InputData();			//	�Է� �Լ�

	//	�ڵ带 �ۼ��ϼ���

	sort(A, A+N, [](const st& a, const st& b) { return (a.X < b.X);  });
	
	//for (int i = 0; i < N; i++)
	//{
	//	cout << A[i].X << endl;
	//}

	for (int i = 0; i < N; i++)
	{
		ids.insert(A[i].ID);
	}

	for (int i : ids)
	{
		m[i] = 0;
	}


	int min = INT16_MAX;
	for (int i=0;i<N;i++)
	{
		int size = GetSize(i);
		if (min > size)
		{
			min = size;
		}
	}

	ans = min;

	cout << ans << endl;	//	���� ���
	return 0;
}

/*
6
25 7
26 1
15 1
22 3
20 1
30 1
*/