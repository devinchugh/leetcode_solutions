#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> dp;
    int getlines(vector<int> &nums1, vector<int> &nums2, int i, int j)
    {
        if (i >= nums1.size() || j >= nums2.size())
        {
            return 0;
        }
        if (dp[i][j] != -1)
        {
            return dp[i][j];
        }

        if (nums1[i] == nums2[j])
        {
            return dp[i][j] = 1 + getlines(nums1, nums2, i + 1, j + 1);
        }

        return dp[i][j] = max(getlines(nums1, nums2, i, j + 1), getlines(nums1, nums2, i + 1, j));
    }
    int maxUncrossedLines(vector<int> &nums1, vector<int> &nums2)
    {
        for (int i = 0; i <= nums1.size(); i++)
        {
            vector<int> temp(nums2.size() + 1, -1);
            dp.push_back(temp);
        }

        return getlines(nums1, nums2, 0, 0);
    }
};