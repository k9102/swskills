
#include "pch.h"

#include <iostream>
#include <algorithm>
#include <set>
#include <map>


using namespace std;

int N;//제품 수
struct st {
	int X, ID;//위치, 아이디
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

pair<int,int> FirstRound()
{
	set<int> rec;

	for (int i = 0; i < N;i++)
	{
		m[A[i].ID]++;
		rec.insert(A[i].ID);
		if (rec.size() == ids.size())
		{
			return { i,A[i].X - A[0].X };
		}
	}

	return { -1,INT16_MAX };
}

pair<int, int> NextRound(int s,int e)
{
	m[A[s].ID]--;
	if (m[A[s].ID] == 0)
	{
		for (int i=e+1; i < N; i++)
		{
			m[A[i].ID]++;
			if (A[i].ID == A[s].ID)
			{
				return { i,A[i].X - A[s + 1].X };
			}
		}

		return { -1,INT16_MAX };
	}
	else
	{
		return { e, A[e].X - A[s+1].X };
	}
}



int main() 
{
	int ans = -1;

	InputData();


	sort(A, A+N, [](const st& a, const st& b) { return (a.X < b.X);  });
	

	for (int i = 0; i < N; i++)
	{
		ids.insert(A[i].ID);
	}

	int min = INT16_MAX;

	int e, dist;
	tie(e,dist) = FirstRound();
	min = dist;
	for (int i=0;i<N;i++)
	{
		tie(e, dist) = NextRound(i,e);
		if (e == -1)
			break;
		else
		{
			if (min > dist) min = dist;
		}
	}

	ans = min;

	cout << ans << endl;	//	정답 출력
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