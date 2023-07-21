#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findMaxForm(vector<string> &strs, int m, int n)
    {
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

        for (auto &&str : strs)
        {
            int count0 = 0, count1 = 0;
            for (auto &&i : str)
            {
                if (i == '0')
                {
                    count0++;
                }
                else
                {
                    count1++;
                }
            }

            for (int i = m; i >= count0; i--)
            {
                for (int j = n; j >= count1; j--)
                {
                    dp[i][j] = max(dp[i][j], 1 + dp[i - count0][j - count1]);
                }
            }
        }
        return dp[m][n];
    }
};