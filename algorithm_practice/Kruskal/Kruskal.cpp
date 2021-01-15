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
    int n = 7;
    int m = 11;
    int sum = 0;
    int parent[n];

    vector<Edge> v;
    v.push_back(Edge(12, 1, 7));
    v.push_back(Edge(13, 4, 7));
    v.push_back(Edge(17, 1, 5));
    v.push_back(Edge(20, 3, 5));
    v.push_back(Edge(24, 2, 4));
    v.push_back(Edge(28, 1, 4));
    v.push_back(Edge(37, 3, 6));
    v.push_back(Edge(45, 5, 6));
    v.push_back(Edge(62, 2, 5));
    v.push_back(Edge(67, 1, 2));
    v.push_back(Edge(73, 5, 7));

    // 간선의 비용을 기준으로 오름차순으로 정렬
    sort(v.begin(), v.end());

    for(int i = 0; i < n; i++)
    {
        parent[i] = i;
    }

    for(int i = 0; i < v.size(); i++)
    {
        //사이클이 발생하지 않는 경우에만 그래프에 포함 
        if(!findParent(parent, v[i].node[0] - 1, v[i].node[1] - 1))
        {
            sum += v[i].distance;
            unionParent(parent, v[i].node[0] - 1, v[i].node[1] - 1);
        }
    }
    cout << sum << " ";

}