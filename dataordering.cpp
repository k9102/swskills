
#include "pch.h"
#include <iostream>

using namespace std;

unsigned int Make_Data(unsigned int rcv);

int mask[] =
{
	0b0,
	0b1,
	0b11,
	0b111,
	0b1111,
	0b1'1111,
	0b11'1111
};


int tbl[8][3] = {
{26,6,18},
{23,3,13},
{19,4,0},
{15,4,24},
{11,4,4},
{9,2,16},
{4,5,8},
{0,4,28}
};

// 작성할 함수
unsigned int Make_Data(unsigned int rcv)
{
	unsigned sol = 0;

	unsigned tmp;

	for (int i = 0; i < 8; i++)
	{
		auto [rs, m, ss] = tbl[i];
		tmp = (rcv >> rs) & mask[m];
		sol |= tmp << ss;
	}
	
	return sol;
}

int main(void)
{
	unsigned int rcv = 0, sol;

	// 입력 받는 부분
	cin >> hex >> uppercase >> rcv;

	sol = Make_Data(rcv);

	cout << hex << uppercase << sol;
}