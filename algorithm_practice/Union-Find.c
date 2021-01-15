#include <stdio.h>

int getParent(int parent[], int x)
{
    if(parent[x] == x) return x; //부모노드가 자기 자신이면
    return parent[x] = getParent(parent, parent[x]);
}

//두 부모 노드를 합치는 함수
int unionParent(int parent[], int a, int b)
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

int is_parent_same(int parent[], int a, int b)
{
    printf("%d 와 %d 는 같은 부모를 가지고 있나요?:", a, b);
    return findParent(parent, a, b);
}

int main(void)
{
    int input1;
    int input2;
    int result = 0;

    scanf("%d",&input1);
    scanf("%d",&input2);

    int parent[11];
    for(int i = 0; i < 11; i++)
    {
        parent[i] = i;
    }

    unionParent(parent, 1, 2);
    unionParent(parent, 2, 3);
    unionParent(parent, 3, 4);
    unionParent(parent, 5, 6);
    unionParent(parent, 6, 7);
    unionParent(parent, 7, 8);

    while(!result)
    {
         result = is_parent_same(parent, input1, input2);
        if(result == 1)
            printf("YES");
        else
        {
            printf("NO\n");
            printf("부모노드 합치기 실행중.. \n");
            unionParent(parent, input1, input2);
        }
    }
}