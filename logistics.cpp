#include <iostream>
#include <limits.h>
using namespace std;

int N, M;                      //공장 수, 도로 정보 수
int A[5000], B[5000], D[5000]; //공장 A, 공장 B, 거리 D

void InputData()
{
    int i;
    cin >> N >> M;
    for (i = 0; i < M; i++)
    {
        cin >> A[i] >> B[i] >> D[i];
    }
}

#include <map>
#include <algorithm>

map<int, int> d_map;

inline int Hash(int s, int e)
{
    if (s > e)
    {
        return (s << 8) | (e);
    }
    else
    {
        return (e << 8) | (s);
    }
}

struct NODE
{
    int dist;
    bool visited;
};

NODE node[100];
int max_dist[100] = {};

void InitNode(int n)
{
    for (int i = 0; i < n; i++)
    {
        node[i].visited = false;
        node[i].dist = INT_MAX;
    }
}

int main()
{
    int ans = -1;
    InputData(); //	입력 함수

    //	코드를 작성하세요

    for (int i = 0; i < M; i++)
    {
        d_map[Hash(A[i]-1, B[i]-1)] = D[i];
    }


    for (int i = 0; i < N; i++)
    {
      
        InitNode(N);

        node[i].dist = 0;

        for(int loop=0;loop<N;loop++)
        {
            int shortest;
            {
                int min_val = INT_MAX;
                for(int j=0;j<N;j++)
                {
                    if(!node[j].visited)
                    {
                        if(min_val > node[j].dist) {
                            min_val = node[j].dist;
                            shortest = j;
                        }
                    }
                }
            }

            node[shortest].visited = true;


            for (int j = 0; j < N; j++)
            {
                if (!node[j].visited)
                {
                    int key = Hash(shortest, j);
                    if (d_map.find(key) != end(d_map))
                    {
                        int dist = d_map[key] + node[shortest].dist;
                        if (dist < node[j].dist)
                        {
                            node[j].dist = dist;
                        }
                    }
                }
            }
        } 

        for(int j=0;j<N;j++)
        {
            if(node[j].dist > max_dist[i])
            max_dist[i] = node[j].dist; 
        }
    }

    ans = INT_MAX;
    for(int i=0;i<N;i++)
    {
        if(ans > max_dist[i])
        {
            ans = max_dist[i];
        }
    }

    cout << ans << endl; //	정답 출력
    return 0;
}