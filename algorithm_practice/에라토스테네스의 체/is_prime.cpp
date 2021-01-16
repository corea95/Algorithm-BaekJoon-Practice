#include <iostream>
#include <math.h>

using namespace std;

bool isPrime(int x)
{
    int end = (int) sqrt(x);
    for(int i = 2; i <= end; i++)
    {
        if(x % i == 0) return false; //약수이면 false 
    }
    return true; //소수일때 true
}

int main(void)
{
    cout<< isPrime(97);
}