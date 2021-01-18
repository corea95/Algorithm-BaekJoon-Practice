#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#define MAX 10001

using namespace std;

int id, d[MAX]; //각 노드마다 고유한 번호 할당
bool finished[MAX]; // 현재 특정한 노드에 대한 DFS가 끝났는지 확인
//방향 그래프일때만 의미가 있다. (무향그래프면 무조건 SCC)
vector<int> a[MAX]; //인접한 노드를 담는 배열
vector< vector<int> > SCC; //한 그래프 여러개의 SCC가 가능하기 때문에 2차원
stack<int> s;

//DFS는 총 정점의 갯수만큼 실행
int dfs(int x)
{
    d[x] = ++id;
    s.push(x); //스택에 자기자신 삽입
    
    int parent = d[x];
    for(int i = 0; i < a[x].size(); i++)
    {
        int y = a[x][i]; //인접한 노드 
        
        //해당 노드 방문하지 않았으면, 해당 노드로 dfs 수행 (작은값으로 부모를 가르키도록)
        if(d[y] == 0) parent = min(parent, dfs(y));
        //방문은 되어있지만, 처리가 안된 노드(dfs를 수행중인 노드)
        else if(!finished[y]) parent = min(parent, d[y]);
    }

    // 부모노드가 자기 자신인 경우
    if(parent == d[x]) 
    {
        vector<int> scc;
        while(1)
        {
            int t = s.top();
            s.pop();
            scc.push_back(t);
            finished[t] = true;
            if(t == x) break; //자기자신, 즉 부모값이 나올때 나감
        }
        SCC.push_back(scc); //만들어진 scc를 전체 SCC집합안에 삽입
    }
    
    //자신의 부모값 반환
    return parent; 
}

int main(void)
{
    int v = 11;
    a[1].push_back(2);
    a[2].push_back(3);
    a[3].push_back(1);
    a[4].push_back(2);
    a[4].push_back(5);
    a[5].push_back(7);
    a[6].push_back(5);
    a[7].push_back(6);
    a[8].push_back(5);
    a[8].push_back(9);
    a[9].push_back(10);
    a[10].push_back(11);
    a[11].push_back(3);
    a[11].push_back(8);

    //각 정점에 대해서 한번씩 dfs를 수행
    for(int i = 1; i <= v; i++)
    {
        //한번도 방문하지 않은 경우에만 (한번만 수행)
        //결과적으로는 총 정점의 갯수만큼 시행
        if(d[i] == 0) dfs(i);
    }    

    cout << "SCC의 갯수:" << SCC.size() << "\n";
    for(int i = 0; i< SCC.size(); i++)
    {
        cout<< i + 1 << "번째 SCC: " ;
        for(int j = 0; j < SCC[i].size(); j++)
        {
            cout<< SCC[i][j] << " ";
        }
        cout<< "\n";
    }
    return 0;
}