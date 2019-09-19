#include <iostream>
#include <algorithm>
#include <limits.h>
using namespace std;
int H;//세로크기
int W;//가로크기
char map[500][510];//지도
int cost[500][510]={};

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

int dir[4][2]={{-1,0},{1,0},{0,-1},{0,1}};
void Traverse(int x,int y,int c)
{
    called ++;
    cost[y][x] = c;
    for(int i=0;i<4;i++)
    {
        int nx = x+dir[i][0];
        int ny = y+dir[i][1];
        if(GetM(nx,ny)!='X' && cost[ny][nx] > c+1)
        {
            Traverse(nx,ny,c+1);
        }
    }
}

int main(){
	int ans = 0;

    fill_n((int*)cost,500*510,INT_MAX);

	input_data();
	//	코드를 작성하세요

    Traverse(0,0,0);

    ans = cost[H-1][W-1];
    if(ans==INT_MAX) ans = -1;
	cout << ans << endl;
    //cout << called << endl;
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