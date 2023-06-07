#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int longestOnes(vector<int> &nums, int k)
    {
        int n = nums.size();
        if (k == n)
        {
            return n;
        }
        int maxi = 0, curr = 0;
        int l = 0, r = 0;
        int count = 0;
        while (r < n)
        {
            if (nums[r])
            {
                r++;
            }
            else if (count < k)
            {
                count++;
                r++;
            }
            else
            {
                while (l < r && nums[l])
                {
                    l++;
                }
                l++;
                r++;
            }
            maxi = max(maxi, r - l);
        }
        return maxi - 1;
    }
};