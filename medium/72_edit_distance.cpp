#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minDistance(string word1, string word2)
    {
        vector<vector<int>> dp(word1.size() + 1, vector<int>(word2.size(), -1));
        int m = word1.size();
        int n = word2.size();
        for (int j = 0; j <= n; j++)
        {
            dp[0][j]=j;
        }
        for (int i = 0; i <= m; i++)
        {
            dp[i][0]=i;
        }
        for (int i = 1; i <= m; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if(word1[i-1]==word2[j-1]){
                    dp[i][j]=dp[i-1][j-1];
                }
                else{
                    int insert = 1+dp[i-1][j];
                    int update = 1+dp[i-1][j-1];
                    int del = 1+dp[i][j-1];
                    dp[i][j] = min({insert, update, del});
                }
            }
        }

        return dp[m][n];
    }
};