#include <iostream>
#include <vector>
using namespace std;

void best_result(int N, int maximum, vector<int> cards)
{
    int result = 0;
    int sum = 0;
    for(int i = 0; i < N-2; i++){
        for(int j = i+1; j < N-1; j++){
            for(int k = j+1; k < N; k++){
               sum = cards[i] + cards[j] + cards[k];
               if(sum <= maximum && maximum -sum < maximum - result)
                    result = sum;
            }
        }
    }
 cout << result;
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int> input;
    int N, card_maximum;
    cin>> N >> card_maximum;
    for(int i = 0; i < N; i++)
    {
        int a;
        cin >> a;
        input.push_back(a);
    }
    best_result(N, card_maximum, input);
}