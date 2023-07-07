#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxi;
    vector<vector<int>> dp;
    int getans(vector<vector<char>> &matrix, int i, int j)
    {
        if (i >= matrix.size() || j >= matrix[0].size())
        {
            return 0;
        }
        if (dp[i][j] != -1)
        {
            return dp[i][j];
        }
        int left = getans(matrix, i, j + 1);
        int down = getans(matrix, i + 1, j);
        int diagonal = getans(matrix, i + 1, j + 1);
        if (matrix[i][j] == '1')
        {
            int ans = 1 + min({left, down, diagonal});
            maxi = max(ans, maxi);
            return dp[i][j] = ans;
        }
        return dp[i][j] = 0;
    }
    int maximalSquare(vector<vector<char>> &matrix)
    {
        maxi = 0;
        for (int i = 0; i <= matrix.size(); i++)
        {
            vector<int> temp(matrix[0].size() + 1, 0);
            dp.push_back(temp);
        }
        for (int i = matrix.size() - 1; i >= 0; i--)
        {
            for (int j = matrix[0].size() - 1; j >= 0; j--)
            {
                int left = dp[i][j + 1];
                int down = dp[i+1][j];
                int diagonal = dp[i + 1][j + 1];
                if (matrix[i][j] == '1')
                {
                    int ans = 1 + min({left, down, diagonal});
                    maxi = max(ans, maxi);
                    dp[i][j] = ans;
                }
            }
        }
        return maxi * maxi;
    }
};