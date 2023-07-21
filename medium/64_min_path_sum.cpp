#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> dp;
    int minsum(vector<vector<int>> &grid, int i, int j)
    {
        int m = grid.size();
        int n = grid[0].size();
        if (i == m - 1 && j == n - 1)
        {
            return grid[i][j];
        }
        if (i >= m || j >= n)
        {
            return INT_MAX / 2;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int a = minsum(grid, i + 1, j) + grid[i][j];
        int b = minsum(grid, i, j + 1) + grid[i][j];
        return dp[i][j]=min(a, b);
    }
    int minPathSum(vector<vector<int>> &grid)
    {
        for (int i = 0; i < grid.size(); i++)
        {
            vector<int> temp(grid[0].size(), -1);
            dp.push_back(temp);
        }
        
        return minsum(grid, 0, 0);
    }
};