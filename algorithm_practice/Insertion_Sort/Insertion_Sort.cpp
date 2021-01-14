#include <iostream>

using namespace std;

int main(void)
{
    //Selection, Bubble Sort 보다 빠름
    int i, j, temp;
    int array[10] = {1, 10, 5, 8, 7, 6, 4, 3, 2, 9};
    for(i = 0; i < 9; i++)
    {
        j = i;
        while(j >= 0 && array[j] > array[j + 1])
        {
            temp = array[j];
            array[j] = array[j + 1];
            array[j + 1] = temp;
            j--;
        }
    }
    for(i = 0; i<10; i++)
    {
        cout<< array[i] <<"\n";
    }
}