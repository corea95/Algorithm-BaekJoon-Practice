#include <iostream>
#include <vector>
#include <queue>
#define MAX 10

using namespace std;
/*위상정렬
사이클이 발생하지 않을때 (시작점이 명확할 때)
1) 현재 그래프가 위상정렬이 가능한지
2) 가능하다면 위상정렬 후 결과가 무엇인지
스택 또는 큐 이용(큐를 선호)

진입차수 : 해당 노드로 들어오는 노드 갯수 
시간 복잡도는 O(V + E) 모든 정점에 대해 각 간선을 확인
                        (정점 갯수 + 간선 갯수)
*/

int n, inDegree[MAX]; //inDegree는 진입차수
vector<int> a[MAX]; // 각 정점에 연결되어있는 모든 노드 정보들 담기

void topologySort()
{
    int result[MAX]; //위상정렬을 수행한 결과 값
    queue<int> q;
    
    //진입 차수가 0인 노드를 큐에 삽입
    for(int i = 1; i <= n; i++)
    {
        if(inDegree[i]== 0) q.push(i); 
    }

    //위상 정렬이 완전히 수행되려면 정확히 N개의 노드 방문
    for(int i = 1; i <= n; i++)
    {
        if(q.empty())
        {
            cout<< "사이클 발생!" << "\n";
            return;
        }
        int x = q.front();
        q.pop();
        result[i] = x;

        //꺼낸 원소에 연결되어있는 모든 정점 확인, 간선 제거
        for(int i = 0; i < a[x].size(); i++)
        {
            int y = a[x][i];

            // 새롭게 진입차수가 0이 된 정점을 큐에 삽입 
            if(--inDegree[y] == 0)
            {
                q.push(y);
            }
        }
    }

    for(int i = 1; i <= n; i++)
    {
        cout << result[i] << " ";
    }

}
int main(void)
{
    n = 7;
    a[1].push_back(2);
    inDegree[2]++;
    a[1].push_back(5);
    inDegree[5]++;
    a[2].push_back(3);
    inDegree[3]++;
    a[3].push_back(4);
    inDegree[4]++;
    a[4].push_back(6);
    inDegree[6]++;
    a[5].push_back(6);
    inDegree[6]++;
    a[6].push_back(7);
    inDegree[7]++;
    topologySort();
}