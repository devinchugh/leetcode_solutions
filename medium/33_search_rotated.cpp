#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int getpivotindex(vector<int> &nums) {
    int n = nums.size();
    int l = 0, r = n - 1;

    while (r > l) {
        int mid = l + (r - l) / 2;

        if (nums[mid] > nums[r]) {
            l = mid + 1;
        } else if (nums[mid] < nums[r]) {
            r = mid;
        } else {
            r--; // Move the right pointer to eliminate duplicates
        }
    }

    return l;
}



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
    int search(vector<int> &nums, int target)
    {

        int x = getpivotindex(nums);
        int idx = binarysearch(nums, target, 0, x - 1);
        if (idx != -1)
        {
            return idx;
        }
        idx = binarysearch(nums, target, x, nums.size() - 1);

        return idx;
    }
};


int main()
{
    vector<int> arr = {1,1,8,1,1,1};
    Solution x;
    cout << x.getpivotindex(arr);
}