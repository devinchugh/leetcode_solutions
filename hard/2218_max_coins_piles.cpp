#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int getans(vector<vector<int>> &arr, int k, int curr_ind, vector<vector<int>> &dp)
    {
        if (curr_ind >= arr.size())
        {
            return 0;
        }
        if (dp[curr_ind][k] != -1)
        {
            return dp[curr_ind][k];
        }
        if (k <= 0)
        {
            return 0;
        }
        int maxi = getans(arr, k, curr_ind + 1, dp);
        int sum = 0;
        for (int i = 0; i < arr[curr_ind].size(); i++)
        {
            sum += arr[curr_ind][i];
            if (k - i - 1 > 0)
            {
                maxi = max(maxi, sum + getans(arr, k - i - 1, curr_ind + 1, dp));
            }
        }

        return dp[curr_ind][k] = maxi;
    }
    int maxValueOfCoins(vector<vector<int>> &piles, int k)
    {
        vector<vector<int>> dp(piles.size() + 1, vector<int>(k + 1, -1));
        return getans(piles, k, 0, dp);
    }
};