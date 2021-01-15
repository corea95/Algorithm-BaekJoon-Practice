#include <iostream>

using namespace std;

void constructor(int Number)
{
    bool c = false;
    for(int i = 1; i < Number; i++)
    {
        int sub_Num = 0;
        int tmp;

        sub_Num += i/1000000;
        tmp = i % 1000000;
        sub_Num += tmp/100000;
        tmp = tmp % 100000;
        sub_Num += tmp/10000;
        tmp = tmp % 10000;
        sub_Num += tmp/1000;
        tmp = tmp % 1000;
        sub_Num += tmp/100;
        tmp = tmp % 100;
        sub_Num += tmp/10;
        tmp = tmp % 10;
        sub_Num += tmp;

        if(i + sub_Num == Number)
        {
            cout << i;
            c = true;
            break;
        }
    }
    if(c == false) cout << 0;
}

int main(void)
{
    int N;
    cin>> N;
    
    constructor(N);
}

    