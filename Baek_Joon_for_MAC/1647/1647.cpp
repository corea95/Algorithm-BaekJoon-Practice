#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int getParent(int parent[], int x)
{
    if(parent[x] == x) return x; //부모노드가 자기 자신이면
    return parent[x] = getParent(parent, parent[x]);
}

//두 부모 노드를 합치는 함수
void unionParent(int parent[], int a, int b)
{
    a = getParent(parent, a);
    b = getParent(parent, b);
    if (a < b) parent[b] = a;
    else parent[a] = b;
}

// 같은 부모를 가지는지 확인 (같은 그래프인지)
int findParent(int parent[], int a, int b)
{
    a = getParent(parent, a);
    b = getParent(parent, b);
    if(a == b) return 1;
    else return 0;
}

//간선을 담는 클래스
class Edge
{
    public:
        int node[2];
        int distance;
        Edge(int distance, int a, int b)
        {
            this->distance = distance;
            this->node[0] = a;
            this->node[1] = b;
        }
        bool operator < (Edge &edge)
        {
            return this->distance < edge.distance;
        }
};

int main(void)
{
    vector<Edge> v;
    int N, M, i, a, b, c, sum;
    cin>> N;
    cin>> M;

    for(i = 0; i < M; i++)
    {
        cin>> a >> b >> c;
        v.push_back(Edge(a, b, c));
    }

    int parent[N];
    for(i = 0; i < N; i++)
    {
        parent[i] = i;
    }

    sort(v.begin(), v.end());

    for(i = 0; i <v.size(); i++)
    {
        //사이클이 발생하지 않을때만 
        if(!findParent(parent, v[i].node[0] - 1, v[i].node[1] - 1) )
            sum += v[i].distance;
            unionParent(parent, v[i].node[0] - 1, v[i].node[1] - 1);
    }

    cout<< sum;

    return 0;
}