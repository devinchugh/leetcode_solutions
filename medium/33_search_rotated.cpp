#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int getpivotindex(vector<int> &nums)
    {
        int n = nums.size();

        int l = 0, r = n - 1;

        while (r >= l)
        {
            int mid = (r + l) / 2;

            if ((mid == 0 || nums[mid] < nums[mid - 1]) && (mid == n - 1 || nums[mid] < nums[mid + 1]))
            {
                return mid;
            }
            else if (nums[r] < nums[mid])
            {
                l = mid + 1;
            }
            else
            {
                r = mid - 1;
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
    vector<int> arr = {4,5,6,7,0,1,2};
    Solution x;
    cout << x.getpivotindex(arr);
}