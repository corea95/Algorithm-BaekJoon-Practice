#include <iostream>
#include<string>
using namespace std;

void hanoi(int n, int from, int tmp, int to)
{

    if(n==1)
        cout<< from <<" "<< to << "\n";
    else
    {
        hanoi(n-1, from, to, tmp);
        cout<< from <<" "<< to << "\n";
        hanoi(n-1, tmp, from, to);
    }
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int plate1 = 1;
    int plate2 = 2;
    int plate3 = 3;
    int n;
    cin>> n;
    cout<< (1 << n) - 1 << "\n";
    hanoi(n, plate1, plate2, plate3);
}