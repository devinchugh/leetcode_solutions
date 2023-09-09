#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int longestArithSeqLength(vector<int> &nums)
    {
        int n = nums.size();
        int ans = 0;
        vector<vector<int>> dp(n, vector<int>(2000, 0));
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                int d = nums[j] - nums[i] + 1000;
                dp[j][d] = max(2, dp[i][d] + 1);
                ans = max(ans, dp[j][d]);
            }
        }
        return ans;
    }
};