#include <iostream>

/*
1) 전위 순회 : 자기 자신을 처리 -> 왼쪽 -> 오른쪽
2) 중위 순회 : 왼쪽 처리 -> 자기자신 -> 오른쪽
3) 후위 순회 : 왼쪽 -> 오른쪽 -> 자기자신
*/

int node_number = 15;

using namespace std;


typedef struct node *treePointer;
typedef struct node 
{
    int data;
    treePointer leftChild, rightChild;
} node;

//전위 순회
void preorder(treePointer ptr)
{
    if(ptr)
    {
        cout << ptr->data << ' ';
        preorder(ptr->leftChild);
        preorder(ptr->rightChild);
    }
}

void inorder(treePointer ptr)
{
    if(ptr)
    {
        inorder(ptr->leftChild);
        cout << ptr->data << ' ';
        inorder(ptr->rightChild);
    }
}

void postorder(treePointer ptr)
{
    if(ptr)
    {
        postorder(ptr->leftChild);
        postorder(ptr->rightChild);
        cout << ptr->data << ' ';
    }
}

int main(void)
{
    //노드 생성
    node nodes[node_number + 1];

    //각 노드 초기화 
    for(int i = 1; i<= node_number; i++)
    {
        nodes[i].data = i;
        nodes[i].leftChild = NULL;
        nodes[i].rightChild = NULL;
    }

    //이진 트리 만들어 주기
    for(int i = 1; i<= node_number; i++)
    {
        //i가 짝수일때 부모노드의 leftChild에 본인 삽입
        if(i % 2 == 0)
        {
            nodes[i / 2].leftChild = &nodes[i];
        }
        //i가 홀수일때 부모노드의 rightChild에 본인 삽입
        else
        {
            nodes[i / 2].rightChild = &nodes[i];
        }
    }
 
    inorder(&nodes[1]);
    return 0;

}