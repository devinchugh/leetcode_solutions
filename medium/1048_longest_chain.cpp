#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int longestStrChain(vector<string> &words)
    {
        sort(words.begin(), words.end(), [](string a, string b)
             { return a.size() < b.size(); });

        unordered_map<string, int> mp;
        int ans = 1;

        for (string i : words)
        {
            mp[i] = 1;
            for (int j = 0; j < i.size(); j++)
            {
                string pre = i.substr(0, j) + i.substr(j + 1);
                if (mp.find(pre) != mp.end())
                {
                    mp[i] = max(mp[i], 1 + mp[pre]);
                    ans = max(ans, mp[i]);
                }
            }
        }
        return ans;
    }
};