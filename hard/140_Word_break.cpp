#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<string> ans;
    void getans(string s, map<string, bool> &mp, int currpos, string currstr)
    {
        if (currpos == s.size())
        {
            currstr.pop_back();
            ans.push_back(currstr);
            return;
        }
        string temp = "";
        for (int i = currpos; i < s.size(); i++)
        {
            temp += s[i];
            if (mp[temp])
            {
                getans(s, mp, i + 1, currstr + temp + " ");
            }
        }
        return;
    }
    vector<string> wordBreak(string s, vector<string> &wordDict)
    {
        map<string, bool> mp;
        for (auto &&i : wordDict)
        {
            mp[i] = 1;
        }
        getans(s, mp, 0, "");
        return ans;
    }
};
