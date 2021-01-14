#include <iostream>

using namespace std;

int main(void)
{
    //가장 큰 값이 뒤로 먼저 가게된다. *정렬 알고리즘 중 가장 느린 정렬.
    int i, j, temp;
    int array[10] = {1, 10, 5, 8, 7, 6, 4, 3, 2, 9};
    for(i = 0; i < 10; i++)
    {
        for(j = 0; j < 9 - i; j++)
        {
            if(array[j] > array[j + 1])
            {
                temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
    for(i = 0; i< 10; i++)
    {
        cout << array[i] <<"\n";
    }
}