#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minSubArrayLen(int target, vector<int> &nums)
    {
        int left = 0, right = 0;
        int currsum = nums[0];
        int maxi = INT_MAX;
        while (right < nums.size())
        {
            if (currsum < target)
            {
                right++;
                currsum += nums[right];
            }
            else
            {
                currsum -= nums[left];
                left++;
            }
            if (currsum > target)
                maxi = min(maxi, right - left + 1);
        }
        if (left == 0 && right >= nums.size())
        {
            return 0;
        }
        while (left <= right)
        {
            currsum -= nums[left];
            left++;

            if (currsum > target)
                maxi = min(maxi, right - left + 1);
        }
        return maxi;
    }
};