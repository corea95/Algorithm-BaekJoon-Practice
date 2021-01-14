#include <iostream>
#include <vector>

using namespace std;
//Heap Sort 병합정렬, 퀵정렬 만큼 빠른 알고리즘 O(N*log n) 항상 보장 
//완전 이진트리를 이용하는 트리 

int main(void)
{
    int number = 9;
    int heap[9] = {9, 4, 2, 1, 5, 3, 7, 8, 6};

    //먼저 전체 트리를 최대 힙 구조로 변경 
    for(int i = 1; i < number; i++)
    {
        int c = i;
        do
        {
            int root = (c - 1) / 2 ; //부모노드 찾는 식 
            if(heap[root] < heap[c]) //부모노드보다 자식노드의 수가 클 때 스왑 
            {
                int temp = heap[root];
                heap[root] = heap[c];
                heap[c] = temp;
            }
            c = root; //부모노드로 올라가서 반복
        } while (c != 0);
    }
        //크기를 줄여가며 반복적으로 힙 구성 
        for(int i = number - 1; i >= 0; i--) //루트 노드와 가장 마지막 원소 스왑
        {
            int temp = heap[0];
            heap[0] = heap[i];
            heap[i] = temp;
            int root = 0;
            int c = 1;
            do
            {
                c = 2 * root + 1;
                // 자식 중에 더 큰 값 찾기 
                if (heap[c] < heap[c + 1] && c < i - 1)
                {
                    c++; //더 큰 값이 오른쪽 자식노드면 오른쪽으로 이동 
                }
                //루트보다 자식이 더 크다면 교환
                if(heap[root] < heap[c] && c < i)
                {
                    int temp = heap[root];
                    heap[root] = heap[c];
                    heap[c] = temp;
                }
                root = c; // 한번 끝나면 다시 루트로 
                
            } while (c < i);
        }
        for(int i = 0; i < number; i++)
        {
            cout << heap[i] <<" ";
        }
}