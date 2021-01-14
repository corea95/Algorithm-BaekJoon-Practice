#include <iostream>

using namespace std;

int number;
int a[10001];

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>> number;
    for(int i = 0; i < number; i++)
    {
        int x;
        cin>> x;
        a[x]++;
    }
    for(int i = 0; i < 10001; i++)
    {
        while(a[i] != 0)
        {
            cout<< i<< "\n";
            a[i]--;
        }
    }

}