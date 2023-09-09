#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> dp;
    bool getans(string &s1, string &s2, string &s3, int i, int j)
    {
        if (i + j >= s3.size())
        {
            if(i!=s1.size() || j!=s2.size()){
                return false;
            }
            return true;
        }
        char curr = s3[i + j];
        bool a = 0, b = 0;
        if (dp[i][j] != -1)
        {
            return dp[i][j];
        }
        if (i < s1.size() && curr == s1[i])
        {
            a = getans(s1, s2, s3, i + 1, j);
        }
        if (j < s2.size() && curr == s2[j])
        {
            b = getans(s1, s2, s3, i, j + 1);
        }
        dp[i][j] = a || b;
        return  a || b;
    }
    bool isInterleave(string s1, string s2, string s3)
    {
        for (int i = 0; i < 101; i++)
        {
            vector<int> temp(101, -1);
            dp.push_back(temp);
        }

        return getans(s1, s2, s3, 0, 0);
    }
};