#include "pch.h"

#include <iostream>
#include <vector>
#include <stdlib.h>
#include <string.h>

using namespace std;

int N;//테스트 케이스 수
int B;//진법
char S[110];//첫 번째 정수
char D[110];//두 번째 정수

int s[110];
int d[110];
int r[110][220] = {};
int sign;
int tmp_r[220];

int D2N(char d)
{
	if (d >= '0' && d <= '9') return d - '0';
	return (d - 'A') + 10;
}

char N2D(int n)
{
	return "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ"[n];
}

#include <tuple>
pair<int, int> StrD2N(char *d, int *n)
{
	int ret = 1;
	int i = 0;
	if (d[i] == '-') {
		ret = -1;
		i++;
	}

	int j = 0;
	for (; i < strlen(d); i++)
	{
		n[j++] = D2N(d[i]);
	}

	return { ret,j };
}



void InputData() {
	cin >> B >> S >> D;
}

vector<vector<int>> vec_r;
vector<int> vec_s;
int main() {
	int i;
	//scanf("%d", &N);
	cin >> N;
	for (i = 0; i < N; i++) {
		InputData();//입력 함수
		
		memset(r, 0, sizeof(r));
		//	코드를 작성하세요
		auto[sign_s, sl] = StrD2N(S, s);
		auto[sign_d, dl] = StrD2N(D, d);
		sign = sign_s * sign_d;

		
		int ri = 0;
		int row = 0;
		int max_rlen = 0;
		for (int i = dl - 1; i >= 0; i--, row++)
		{
			int t = ri++;
			int c = 0;
			for (int j = sl - 1; j >= 0; j--)
			{
				int tmp = c + s[j] * d[i];
				c = tmp / B;
				r[row][t++] += tmp % B;
			}
			if (c != 0) r[row][t++] = c;

			max_rlen = (t > max_rlen) ? t : max_rlen;
		}

		int c = 0;

		int k=0;
		for (; k < max_rlen; k++)
		{
			int tmp = 0;
			for (int ri = 0; ri < row; ri++)
			{
				tmp += r[ri][k];
			}

			tmp_r[k] = (tmp + c) % B;
			c = (tmp + c) / B;
		}

		if (c != 0) tmp_r[k++] = c;
		vec_r.push_back(vector<int>(tmp_r, tmp_r+k));
		vec_s.push_back(sign_d*sign_s);
	}
	

	for (int i = 0; i < vec_r.size(); i++)
	{
		int k = 0;
		for (; k < vec_r[i].size(); k++)
		{
			if (vec_r[i][k] != 0) break;
		}

		if(k==vec_r[i].size())
		{
			cout << 0;
		}
		else {
			bool leading=true;
			cout << (vec_s[i] >= 0 ? "" : "-");
			for (int j = vec_r[i].size() - 1; j >= 0; j--)
			{
				if (leading && vec_r[i][j] == 0) continue;
				
				leading = false;
				cout << N2D(vec_r[i][j]);
				
			}
		}
		cout << endl;

	}

	return 0;
}

/*
5
10 789 456
16 CBA FED
10 -123 56
10 -3214 -987
10 -12345 0


359784
CAAE32
- 6888
3172218
0
*/