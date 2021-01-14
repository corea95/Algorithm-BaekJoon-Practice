#include <iostream>

using namespace std;

void Selection_Sort(int input, int array[], int min)
{
    int i, j, min, index, temp;

    for(i = 0; i < input; i++)
    {
        for(j = i; j < input; j++)
        {
            if(min > array[j])
            {
                min = array[j];
                index = j;
            }
        }
        temp = array[i];
        array[i] = array[index];
        array[index] = temp;
    }
}