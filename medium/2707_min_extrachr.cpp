#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    map<string, int> mp;
    vector<vector<int>> dp;
    int getans(string &s, int i, int j)
    {
        if (j >= s.size())
        {
            return j - i ;
        }
        if (dp[i][j] != -1)
        {
            return dp[i][j];
        }
        string word = "";
        for (int x = i; x <= j; x++)
        {
            word += s[x];
        }

        int mini = INT_MAX / 2;
        if (mp[word])
        {
            mini = getans(s, j + 1, j + 1);
        }
        int a = getans(s, i, j + 1);
        int b = word.size() + getans(s, j + 1, j + 1);
        return dp[i][j] = min({mini, a, b});
    }
    int minExtraChar(string s, vector<string> &dictionary)
    {
        for (auto &&i : dictionary)
        {
            mp[i] = 1;
        }
        for (int i = 0; i < s.size() + 1; i++)
        {
            vector<int> temp(s.size() + 1, -1);
            dp.push_back(temp);
        }

        return getans(s, 0, 0);
    }
};