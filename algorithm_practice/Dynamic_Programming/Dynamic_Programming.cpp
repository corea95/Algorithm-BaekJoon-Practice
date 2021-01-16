#include<iostream>

using namespace std;
/*
병합정렬, 퀵정렬은 동일한 문제 다시 푸는 단점이 없다.
BUT 단순 분할정복 기법을 사용하면 비효율적으로 (이전에 계산했던것 또다시 계산)
ex)피보나치 수열 D[i] = D[i - 1] + D[i - 2]계산하게 된다.
다이나믹 프로그래밍이란, 
이러한 비효율을 없애기 위함 (계산했던 결과를 저장하여 추후에 사용 = Memoization)
*/

int d[100];

int dp(int x)
{
    if(x == 1) return 1;
    if(x == 2) return 1;
    if(d[x] != 0) return d[x];
    return d[x] = dp(x - 1) + dp(x - 2);
}

int main(void)
{
    cout << dp(30);
}