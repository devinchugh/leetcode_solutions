#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string longestCommonPrefix(vector<string> &strs)
    {
        sort(strs.begin(), strs.end());
        if (strs.size() == 1)
        {
            return strs[0];
        }
        vector<pair<char, bool>> mp;
        for (auto &&i : strs[0])
        {
            mp.push_back({i, 1});
        }
        for (int i = 1; i < strs.size(); i++)
        {
            string temp = strs[i];
            int x = 0;
            for (int j = 0; j < mp.size(); j++)
            {
                if (temp[x] != mp[j].first)
                {
                    mp[j].second = 0;
                }
                x++;
            }
        }
        string ans="";
        int x=0;
        while(x<mp.size() && mp[x].second){
            ans+=mp[x].first;
            x++;
        }
        return ans;
    }
};