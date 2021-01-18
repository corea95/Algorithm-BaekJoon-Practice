#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int Queue_visited[7];
vector<int> a[8];

void BFS(int start)
{
    queue<int> q;
    q.push(start);
    Queue_visited[start] = true;

    while(!q.empty())
    {
        int x = q.front();
        cout << x << " ";
        q.pop();
        for(int i = 0; i < a[x].size(); i++)
        {
            int y = a[x][i];
            if(!Queue_visited[y])
            {
                q.push(y);
                Queue_visited[y] = true;
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

    BFS(1);
    return 0;
}


