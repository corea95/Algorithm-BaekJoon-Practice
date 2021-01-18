#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int findString(string parent, string pattern)
{
    int parentSize = parent.size(); //전체 문자열 
    int patternSize = pattern.size(); //찾고자 하는 문자열

    for(int i = 0; i <= parentSize - patternSize; i++)
    {
        bool found = true;
        for(int j = 0; j < patternSize; j++)
        {
            if(parent[i + j] != pattern[j])
            {
                found = false;
                break;
            }
        }
        if(found)
        {
            return i;
        }
    }
    return -1;
}

int main(void)
{
    string parent = "Hello World";
    string pattern = "llo W";
    int result = findString(parent, pattern);
    if(result == -1)
    {
        cout << "찾을 수 없습니다.";
    }
    else
    {
        cout << result + 1 << "번째에서 찾았습니다.";
    }
    return 0;
}