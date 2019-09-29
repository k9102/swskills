#include "pch.h"
#include <iostream>
#include <string>
using namespace std;

int M;					// 반복 인정 회수
char S[100000 + 10];	// 조사 문자열

int main(void)
{
	int i;			// 문자열 S의 어떤 문자를 지시
	int len;		// 문자열 S의 길이
	char r_char;	// 반복되는 문자
	int r_cnt;		// 반복 회수

	// 데이터 읽기
	cin >> M;
	cin >> S;

	// 코드 구현 및 결과 출력

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
