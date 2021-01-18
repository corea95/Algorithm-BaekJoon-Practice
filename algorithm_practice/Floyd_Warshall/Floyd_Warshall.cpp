#include <iostream>
#include <vector>

using namespace std;
/*플로이드 와샬 -> 모든 노드에서 모든 노드로 가는 최소 비용 
삼중 for문이 들어가기 때문에 시간복잡도 :O(n^3) */

int number = 4;
int INF = 100000000;

int a[4][4] =
{
    {0, 5, INF, 8},
    {7, 0, 9, INF},
    {2, INF, 0, 4},
    {INF, INF, 3, 0}
};

void Floyd_warshall()
{
 //결과 그래프 초기화
       int d[number][number];

       for(int i = 0; i < number; i++)
       {
           for(int j = 0; j < number; j++)
           {
               d[i][j] = a[i][j];
           }
       }

       // k = 거쳐가는 노드
        for(int k = 0; k < number; k++)
        {
            // i = 출발 노드
            for(int i = 0; i < number; i++)
            {
                // j = 도착 노드
                for(int j = 0; j <number; j++)
                {
                    /*i에서 k를 거쳐서 j로 가는 경우가
                    i에서 직접 k로 가는 경우보다 작을 경우 교체
                    */
                    if(d[i][k] + d[k][j] < d[i][j])
                    {
                     d[i][j] = d[i][k] + d[k][j];   
                    }
                }
            }
        }
        for(int i = 0; i < number; i++)
        {
            for(int j = 0; j < number; j++)
            {
                cout << d[i][j] << " ";
            }
            cout << "\n";
        }
}
int main(void)
{
    Floyd_warshall();   
}