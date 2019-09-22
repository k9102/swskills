#include "pch.h"
#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
using namespace std;

#define MAX_PROJECT (15) 
typedef struct {
	int s; // ������
	int e; // ������
}DATA;

int     N; // ������Ʈ ��
DATA    project_info[MAX_PROJECT]; // ������Ʈ ����

void Data_Input(void) {
	cin >> N; // ������Ʈ �� �Է�
	// ������Ʈ ���� �Է�
	for (int i = 0; i < N; i++) {
		cin >> project_info[i].s >> project_info[i].e;
	}
}

vector<DATA> ps_;

int Traverse(int p_loc, int loc)
{
	int ret;

	cout << p_loc <<  loc << endl;

	auto itr = find_if(begin(ps_)+loc, end(ps_), [p_loc](auto &v) {return p_loc==-1 ? true:(ps_[p_loc].e < v.s);});

	if (itr == end(ps_))
	{
		ret = 0;
	}
	else
	{
		int o, x;
		int n_loc = distance(begin(ps_), itr);
		o = Traverse(n_loc, n_loc +1)+1;
		x = Traverse(p_loc, n_loc +1);
		ret = max(o, x);
	}

	return ret;
}

int main(void) {
	int sol = 0;
	Data_Input(); // �Է� �Լ� ���� 

	ps_ = vector<DATA>(project_info, project_info + N);
	sort(begin(ps_), end(ps_), [](auto &a, auto &b) {return a.s < b.s;});

	sol = Traverse(-1,0);


	cout << sol << endl; // ��� ���
	return 0;
}

/*
3
1 3
2 6
5 7

2
*/