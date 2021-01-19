#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
// 탐욕적인 알고리즘, 눈 앞에 있는 가장 가치높은것을 고르는 것
int main(void)
{
    vector<pair<int, int> > Coins;
    int n, result = 0; // n = 거슬러 줘야하는 거스름돈의 양
    cin >> n;
    result += n / 500;
    Coins.push_back(make_pair(n / 500, 500));
    n %= 500; 
    result += n / 100;
    Coins.push_back(make_pair(n / 100, 100));
    n %= 100;
    result += n / 50;
    Coins.push_back(make_pair(n / 50, 50));
    n %= 50;
    result += n / 10;
    Coins.push_back(make_pair(n / 10, 10));

    cout << result <<"개의 동전" <<"\n";
    for(int i = 0; i < Coins.size(); i++)
    {
        cout << Coins[i].second << "원: "<< Coins[i].first <<"개\n";
    }
    return 0;
}