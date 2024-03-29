#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> sortArrayByParity(vector<int> &nums)
    {
        int left = 0, right = nums.size() - 1;
        while (left < right)
        {
            if (nums[left] % 2 == 0)
            {
                left++;
            }
            else if (nums[right] % 2 == 1)
            {
                right--;
            }
            else
            {
                swap(nums[left], nums[right]);
                left++;
                right--;
            }
        }
        return nums;
    }
};