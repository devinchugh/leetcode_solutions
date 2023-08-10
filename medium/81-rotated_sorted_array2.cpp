#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    int binarysearch(vector<int> &nums, int target, int l, int r)
    {
        if (l > r)
        {
            return -1;
        }

        while (l <= r)
        {
            int mid = (r + l) / 2;

            if (nums[mid] == target)
            {
                return mid;
            }
            else if (nums[mid] < target)
            {
                l = mid + 1;
            }
            else
            {
                r = mid - 1;
            }
        }
        return -1;
    }
    bool search(vector<int> &nums, int target)
    {
        sort(nums.begin(), nums.end());
        
        int idx = binarysearch(nums, target, 0, nums.size() - 1);
        if (idx != -1)
        {
            return true;
        }
        return false;
    }
    
};