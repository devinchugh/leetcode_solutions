#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool check(vector<int> &nums, int sum1, int sum2, int curridx, vector<vector<int>> &dp)
    {
        if (curridx >= nums.size())
        {
            return sum1 == sum2;
        }

        if (dp[curridx][sum1] != -1)
        {
            return dp[curridx][sum1];
        }

        bool canPartition = check(nums, sum1 + nums[curridx], sum2, curridx + 1, dp) || check(nums, sum1, sum2 + nums[curridx], curridx + 1, dp);
        dp[curridx][sum1] = canPartition;

        return dp[curridx][sum1];
    }

    bool canPartition(vector<int> &nums)
    {
        int totalSum = 0;
        for (int num : nums)
        {
            totalSum += num;
        }

        if (totalSum % 2 != 0)
        {
            return false;
        }

        int targetSum = totalSum;
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(targetSum + 1, -1));
        // cout<<totalSum<<endl;
        return check(nums, 0, 0, 0, dp);
    }
};