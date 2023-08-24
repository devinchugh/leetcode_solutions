#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> dp;
    bool check(vector<int> &nums, int idx)
    {
        int n = nums.size();
        if (idx == n)
        {
            return true;
        }
        if (dp[idx] != -1)
        {
            return dp[idx];
        }
        if (idx + 1 < n && nums[idx] == nums[idx + 1])
        {
            if (check(nums, idx + 2))
            {
                return true;
            }
            if (idx + 2 < n && nums[idx] == nums[idx + 2])
            {
                if (check(nums, idx + 3))
                {
                    return true;
                }
            }
        }
        if (idx + 2 < n && nums[idx] == nums[idx + 2] - 2 && nums[idx] == nums[idx + 1] - 1)
        {
            if (check(nums, idx + 3))
            {
                return true;
            }
        }
        return dp[idx] = false;
    }
    bool validPartition(vector<int> &nums)
    {
        for (int i = 0; i < nums.size(); i++)
        {

            dp.push_back(-1);
        }
        return check(nums, 0);
    }
};