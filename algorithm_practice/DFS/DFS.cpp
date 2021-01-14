#include <iostream>
#include <vector>

using namespace std;

int number = 7;
int c[7];
vector<int> a[8];

void dfs(int x)
{
    if(c[x]) return; //현재 그 노드를 이미 방문했다면.
    c[x] = true; //방문처리
    cout << x << ' '; //방문처f리한 노드요소 출력
    for(int i = 0; i < a[x].size(); i++)
    {
        //인접노드를 방문하면서 해당 인접노드를 대상으로 dfs를 수행
        int y = a[x][i];
        dfs(y);
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

    dfs(1);
    
    return 0;
}