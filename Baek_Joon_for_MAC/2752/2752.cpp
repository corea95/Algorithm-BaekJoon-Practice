#include <iostream>

using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int i, j, min, index, temp;
    int array[3];
    for(i = 0; i < 3; i++)
    {
        cin>> array[i];
    }

    for(i = 0; i < 3; i++)
    {
        min = 1000001;
        for(j = i; j < 3; j++)
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

    
    for(i = 0; i < 3; i++)
    {
            cout<< array[i]<< " ";
    }
}