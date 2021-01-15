#include <iostream>

using namespace std;

void Selection_Sort(int input, int array[], int min)
{
    int i, j, index, temp;

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
int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int input; //주어지는 수의 총 길이
    int array[1001]; //주어지는 수를 넣기위한 배열
    int min = 1001; //최소값 지정

    cin>> input;
    for(int i = 0; i<input; i++)
    {
        cin>> array[i];
    }

    Selection_Sort(input, array, min); //선택정렬 실행

    for(int i= 0; i<input; i++)
    {
        cout<< array[i] <<"\n";
    }
}