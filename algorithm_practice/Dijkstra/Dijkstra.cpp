#include <iostream>
#include <vector>

using namespace std;

int number = 6;
int INF = 1000000000; //int 21억보다 낮게

int a[6][6] = 
{
    {0, 2, 5, 1, INF, INF},
    {2, 0, 3, 2, INF, INF},
    {5, 3, 0, 3, 1, 5},
    {1, 2, 3, 0, 1, INF},
    {INF, INF, 1, 1, 0, 2},
    {INF, INF, 5, INF, 2, 0}
};
bool v[6]; //방문한 노드 visited
int d[6]; //최단 거리

//가장 최소 거리를 가지는 정점 반환
int getSmallIndex()
{
    int min = INF;
    int index = 0;
    for(int i = 0; i < number; i++)
    {
        if(d[i] < min && !v[i]) // 방문하지 않은 노드이며, 이전 min값보다 작은 값이면
        {
            min = d[i]; // 해당 노드의 값을 min으로
            index = i; //최단거리 정점 인덱스 저장
        }
    }
    return index; //최단거리 노드 인덱스값 반환
}

//다익스트라 함수
void dijkstra(int start)
{
    for(int i = 0; i < number; i++)
    {
        d[i] = a[start][i]; //시작점으로 출발, 모든 경로의 값 담기
    }
    v[start] = true; //방문처리
    for(int i = 0; i < number - 2; i++)
    {
        int current = getSmallIndex(); //현재 최소거리 가진 노드
        v[current] = true; //방문처리 해주고
        for(int j = 0; j < 6; j++)
        {
            if(!v[j]) //현재 해당 노드를 방문하지 않았다면
            {
                /*현재 최소거리 가진 노드 + 해당 노드까지의 거리가
                  원래 저장된 해당 노드까지의 거리보다 작으면 
                  갱신해준다*/
                if(d[current] + a[current][j] < d[j])
                {
                    d[j] = d[current] + a[current][j];
                }

            }
        }
    }
    

}
int main(void)
{
    dijkstra(0);
    for(int i = 0; i < number; i++)
        cout<< d[i] << " ";

}