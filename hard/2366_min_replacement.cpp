#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long minimumReplacement(vector<int> &nums)
    {
        long long ans = 0;
        for (int i = nums.size() - 2; i >= 0; i--)
        {
            if (nums[i] > nums[i + 1])
            {
                int steps = (nums[i] - 1) / nums[i + 1];
                if (steps > 0)
                {
                    ans += steps;
                    nums[i] = nums[i] / (steps + 1);
                }
            }
        }
        return ans;
    }
};