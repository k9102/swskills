#include <iostream>
using namespace std;

int N,Q;
int T[101];
int engineer[6] = {};

void Input_Data(void){	
	cin >> N >> Q;				// 엔지니어의 수, 고객의 수
	for(int i=1;i<=Q;i++){
		cin >> T[i];				// 고객의 업무처리 시간
	}
}
#include <algorithm>

int main(void){
	int sol;

	Input_Data();				// 입력 함수

	//	코드를 작성하세요

    for(int i=1;i<=Q;i++)
    {
        auto itr = min_element(engineer,engineer+N);
        *itr += T[i];        
    }

	auto itr = max_element(engineer,engineer+N);
    sol = *itr;

	cout << sol << endl;	// 정답 출력
	return 0;
}

/*
3 5
1 5 3 6 1 

7
*/