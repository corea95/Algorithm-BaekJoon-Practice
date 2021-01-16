#include <iostream>

int number = 100000;
int a[100001];

using namespace std;

void primeNumberSieve()
{
    for(int i = 2; i <= number; i++)
    {
        a[i] = i;
    }
    for(int i = 2; i <= number; i++)
    {
        if(a[i] == 0) continue;
        for(int j = i + i; j <= number; j += i) //지워진게 아니면 그 배수부터 시작
        {
            a[j] = 0;
        }
    }
    for(int i = 2; i <= number; i++)
    {
        if(a[i] != 0) 
            cout << a[i] <<" ";
    }

}

int main(void)
{
    primeNumberSieve();
}