#include "pch.h"
#include <iostream>
#include <algorithm>
#include <limits.h>
#include <tuple>

using namespace std;
int H;//세로크기
int W;//가로크기
char map[500][510];//지도
int cost[500][510]={};

//#define DEBUG

void input_data(){
	int i;
	cin >> H >> W;
	for(i=0 ; i<H ; i++){
		cin >> map[i];
	}
}


char GetM(int x,int y)
{
    if(x>=W || y>=H || x<0 || y<0)
    {
        return 'X';
    }
    else
    {
        return map[y][x];
    }
}

int called=0;

int mv[4][2] = { {-1,0},{0,1},{1,0},{0,-1} };

#include <stack>

stack<tuple<int, int, int>> stk;

void Traverse()
{
	while (!stk.empty())
	{
		int x, y, i;
		tie(x, y, i) = stk.top(); stk.pop();
		
		for(;i < 4;i++)
		{
			int nx = x + mv[i][0];
			int ny = y + mv[i][1];

			if (GetM(nx, ny) == 'X') continue;
			int ncost = cost[y][x] + 1;
			if (cost[ny][nx] > ncost)
			{
				cost[ny][nx] = ncost;
				if (ncost < cost[H - 1][W - 1])
				{
					stk.push({ x,y,i+1});
					
					i = -1;
					x = nx;
					y = ny;
				}
			}
		}
	}
}

int main(){
	int ans = 0;

    fill_n((int*)cost,500*510,INT_MAX);

	input_data();
	//	코드를 작성하세요

	cost[0][0] = 0;
	stk.push({ 0,0,0});
    Traverse();

    ans = cost[H-1][W-1];
    if(ans==INT_MAX) ans = -1;
	cout << ans << endl;

	return 0;
}


/*
20 30
.......X....XXXX.XX..XX.X.XX..
X.XX....X.XX..X.X.X....XXXX..X
..X.X..XX..X.....XX.X..X.XX...
....X.X.X.XXX.X..X..X.X..XX.X.
..XXX.XX...X.X....X.X..X..X...
..X...........X.X...X...XX...X
.X.X....X..XX..XX........X....
..X....X........X......X......
....XXX.X...XX.X.....X.X..X.X.
.....XXX..X....X.X.......X..X.
.....XX..X.X..X....X...XXX....
..X...X.X....X....X..X..X.....
XXXXXXXX.X.XX..XX..XX.......X.
.....X..............XX.XXX.X.X
..X.....X..X..XX.XX..X.X...XX.
...X..X.XXX.XX......X...X..XXX
.X.XX.X.........X.X...X...X..X
..X...X..X..XX..XXX..X.XX...X.
X....X.X....X...X.X..XX.XX..X.
...X.X..X........X.X..........

52
*/