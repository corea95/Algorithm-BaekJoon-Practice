#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
//이중 페어 (정렬한 기준이 2개인 경우, pair를 2중으로 쓰면 편하다)
bool compare(pair<string, pair<int, int> > a,
             pair<string, pair<int, int> > b)
             {
                 if(a.second.first == b.second.first)
                 {
                     return a.second.second > b.second.second;
                 }
                 else
                 {
                     return a.second.first > b.second.first;
                 }
                 

             }

int main(void)
{
    vector<pair<string, pair<int, int> > > v;
    v.push_back(pair<string, pair<int, int> > ("나동빈", pair<int, int>(90, 19961112)) );
    v.push_back(pair<string, pair<int, int> > ("김동빈", pair<int, int>(90, 19931222)) );
    v.push_back(pair<string, pair<int, int> > ("박동빈", pair<int, int>(90, 19921018)) );
    v.push_back(pair<string, pair<int, int> > ("이동빈", pair<int, int>(90, 19991010)) );
    v.push_back(pair<string, pair<int, int> > ("정동빈", pair<int, int>(90, 19901022)) );

    sort(v.begin(), v.end(), compare);

    for(int i = 0; i< v.size(); i++)
    {
        cout << v[i].first << "\n";
    }
    return 0;
}