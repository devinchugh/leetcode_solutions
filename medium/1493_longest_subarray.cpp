#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        int k=1;
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
            maxi = max(maxi, r - l + 1);
        }
        return maxi;
    }
};