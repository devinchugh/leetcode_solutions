#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int lcs(string &text1, string &text2, int i, int j, vector<vector<int>> &dp)
    {
        int m = text1.size();
        int n = text2.size();

        if (i >= m || j >= n)
        {
            return 0;
        }
        if (dp[i][j] != -1)
        {
            return dp[i][j];
        }

        int ans = 0;
        if (text1[i] == text2[j])
        {
            ans = max(ans, 1 + lcs(text1, text2, i + 1, j + 1, dp));
        }
        else
        {
            ans = max(ans, lcs(text1, text2, i, j + 1, dp));
            ans = max(ans, lcs(text1, text2, i + 1, j, dp));
        }

        return dp[i][j] = ans;
    }
    int longestCommonSubsequence(string text1, string text2)
    {
        vector<vector<int>> dp(text1.size() + 1, vector<int>(text2.size() + 1, -1));
        return lcs(text1, text2, 0, 0, dp);
    }
};