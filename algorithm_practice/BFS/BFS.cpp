#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int number = 7;
int c[7]; //checked //방문을 했다
vector<int> a[8];

void bfs(int start)
{
    queue<int> q;
    q.push(start); //방문한 노드를 큐에 삽입
    c[start] = true; //방문 처리의 true 
    while(!q.empty()) //q가 빌때까지 살펴봄
    {
        int x = q.front(); //q의 맨 앞 변수 x에 저장
        q.pop(); //앞부분 제거
        cout << x << " "; //앞부분 출력
        for(int i = 0; i < a[x].size(); i++) //큐에서 꺼낸 인접한 노드들 방문 
        {
            int y = a[x][i]; //인접한 노드
            if(!c[y]) //방문을 한 상태가 아니라면
            {
                q.push(y); 
                c[y] = true;
            }
        }
    }
}

int main(void)
{
    a[1].push_back(2);
    a[2].push_back(1);

    a[1].push_back(3);
    a[3].push_back(1);

    a[2].push_back(3);
    a[3].push_back(2);

    a[2].push_back(4);
    a[4].push_back(2);

    a[2].push_back(5);
    a[5].push_back(2);

    a[3].push_back(6);
    a[6].push_back(3);

    a[3].push_back(7);
    a[7].push_back(3);

    a[4].push_back(5);
    a[5].push_back(4);

    a[6].push_back(7);
    a[7].push_back(6);

    bfs(1);

    return 0;


    

}