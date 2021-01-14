#include <iostream>

using namespace std;

int main(void) // Counting_Sort 전체 데이터 크기가 한정되어있을때 정렬을 수행 O(N)
{
    int temp;
    int count[5];
    int array[30] =
    {
        1, 3 ,2, 4, 3, 2, 5, 3, 1, 2,
        3, 4, 4, 3, 5, 1, 2, 3, 5, 2,
        3, 1, 4, 3, 5, 1, 2, 1, 1, 1
    };

    for(int i = 0; i < 5; i++)
        count[i] = 0;
    for(int i = 0; i < 30; i++)
    {
        //array배열 값에서 1을 감소시키고(0~4까지라서) count를 증가
        count[array[i] - 1]++;  
    }
    for(int i = 0; i < 5; i++)
    {
        if(count[i] != 0)
        {
            for(int j = 0; j < count[i]; j++)
            {
                cout<< i + 1 << " ";
            }
        }
    }

}