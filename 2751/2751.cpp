#include <iostream>
#include <algorithm>

using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int number, i, input;
    int array[1000000];
    
    cin>> number;
    for(i = 0; i< number; i++)
    {
        cin>> array[i];
    }
    std::sort(array, array + number);
    for(int i = 0; i < number; i++)
    {
        cout<< array[i] <<"\n";
    }
}