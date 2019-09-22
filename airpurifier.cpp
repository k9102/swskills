#include "pch.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>

using namespace std;

int H;		// ���� ũ��
int W;		// ���� ũ��
int map[50][50];	//����
int cubic[50][50] = {};


struct ANS {
	int count;	// room ����
	int area;		// ���� ���� room ����
};

void InputData() {
	int i, j;
	cin >> H;
	cin >> W;
	for (i = 0; i < H; i++) {
		for (j = 0; j < W; j++) {
			cin >> map[i][j];
		}
	}
}

int cnt_ = 0;
int tag_ = 0;
int mv[4][2] = { {-1,0},{0,-1},{1,0},{0,1} };
int dir[4] = { 1,2,4,8 };

void Traverse(int x,int y)
{

	if (cubic[y][x] != 0) return;

	cubic[y][x] = tag_;
	cnt_++;

	for (int i=0;i<4;i++)
	{
		if ((map[y][x] & dir[i])==0)
		{
			int nx = x + mv[i][0];
			int ny = y + mv[i][1];

			Traverse(nx, ny);
		}
	}
}

int main() {

	vector<tuple<int, int>>  rooms;
	ANS ans = { 0, 0 };

	InputData();			//	�Է� �Լ�

	//	�ڵ带 �ۼ��ϼ���

	for(int y=0;y<H;y++)
	for (int x = 0; x < W; x++)
	{
		if (cubic[y][x] == 0)
		{
			cnt_ = 0;
			tag_++;

			Traverse(x, y);
			
			rooms.push_back({ tag_,cnt_ });
		}
	}



	sort(begin(rooms), end(rooms), [](auto &a,auto &b) {
		return get<1>(a) > get<1>(b);
	});

	ans.count = rooms.size();
	ans.area = get<1>(rooms[0]);
	cout << ans.count << endl;	//	���� ���
	cout << ans.area << endl;		//	���� ���
	return 0;
}

/*
4
7
11 6 11 6 3 10 6
7 9 6 13 5 15 5
1 10 12 7 13 7 5
13 11 10 8 10 12 13

5
9
*/