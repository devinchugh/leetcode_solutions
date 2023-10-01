#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minDeletions(string s)
    {
        vector<int> dic(26, 0);

        for (auto &&i : s)
        {
            dic[i - 'a']++;
        }
        sort(dic.begin(), dic.end());

        int count = 0;
        
        for (int i = 25 - 1; i >= 0; i--)
        {
            if(dic[i]!=0){
                if(dic[i]==dic[i+1]){
                    count++;
                    dic[i]--;
                }
            }
        }
        
        return count;
    }
};