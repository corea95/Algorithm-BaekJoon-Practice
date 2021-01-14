#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main(void)
{
    vector<pair<int, string> > v;
    v.push_back(pair<int, string>(90, "박한울"));
    v.push_back(pair<int, string>(85, "김민수"));
    v.push_back(pair<int, string>(70, "이명박"));
    v.push_back(pair<int, string>(50, "강종구"));
    v.push_back(pair<int, string>(90, "박혁거세"));

    sort(v.begin(), v.end());

    for(int i = 0; i< v.size(); i++)
    {
        cout << v[i].second << "\n";
    }
    return 0;
}