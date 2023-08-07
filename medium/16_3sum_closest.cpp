#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int threeSumClosest(vector<int> &nums, int target)
    {
        sort(begin(nums), end(nums));

        int l = 0, r = nums.size() - 1;
        int diff = 100000;
        int ans = nums[0]+nums[1]+nums[2];

        for (int i = 0; i < nums.size() - 2; i++)
        {
            l = i + 1;
            r = nums.size() - 1;
            while (l < r)
            {
                int x = nums[l] + nums[r] + nums[i];
                if (abs(target - x) < diff)
                {
                    diff = abs(target - x);
                    ans = x;
                }
                if (x < target)
                {
                    l++;
                }
                else
                {
                    r--;
                }
            }
        }
        return ans;
    }
};