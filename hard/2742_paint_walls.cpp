#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int getans(vector<int> &cost, vector<int> &time, int i, int rem, vector<vector<int>> &dp)
    {
        if (rem <= 0)
        {
            return 0;
        }
        if (i >= cost.size())
        {
            return INT_MAX / 2;
        }
        if(dp[i][rem]!=-1){
            return dp[i][rem];
        }

        // painter paints
        int ans1 = cost[i] + getans(cost, time, i + 1, rem - 1 - time[i], dp);
        int ans2 = getans(cost, time, i + 1, rem, dp);

        return dp[i][rem]=min(ans1, ans2);
    }
    int paintWalls(vector<int> &cost, vector<int> &time)
    {
        int n = cost.size();
        vector<vector<int>> dp(n+1, vector<int>(n+1,-1));
        return getans(cost, time, 0, n, dp);
    }
};