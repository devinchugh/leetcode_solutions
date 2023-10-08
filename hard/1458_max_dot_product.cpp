#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int getans(vector<int> &nums1, vector<int> &nums2, int i, int j, vector<vector<int>> &dp)
    {
        if (i >= nums1.size() or  j >= nums2.size())
        {
            return 0;
        }
        if(dp[i][j]>INT_MIN){
            return dp[i][j];
        }
        // make the product
        int a = nums1[i] * nums2[j] + getans(nums1, nums2, i + 1, j + 1, dp);

        int b = getans(nums1, nums2, i, j + 1, dp);
        int c = getans(nums1, nums2, i + 1, j, dp);

        return dp[i][j]=max({a, b, c});
    }
    int maxDotProduct(vector<int> &nums1, vector<int> &nums2)
    {

        int firstMax = INT_MIN;
        int secondMax = INT_MIN;
        int firstMin = INT_MAX;
        int secondMin = INT_MAX;

        for (int num : nums1)
        {
            firstMax = max(firstMax, num);
            firstMin = min(firstMin, num);
        }

        for (int num : nums2)
        {
            secondMax = max(secondMax, num);
            secondMin = min(secondMin, num);
        }

        if (firstMax < 0 && secondMin > 0)
        {
            return firstMax * secondMin;
        }

        if (firstMin > 0 && secondMax < 0)
        {
            return firstMin * secondMax;
        }
        vector<vector<int>> dp(nums1.size() + 1, vector<int>(nums2.size()+1, INT_MIN));
        return getans(nums1, nums2, 0, 0, dp);
    }
};