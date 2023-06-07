#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int pivotIndex(vector<int> &nums)
    {
        int sum = 0;
        for (auto &&i : nums)
        {
            sum += i;
        }
        int currsum = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            sum -= nums[i];
            if (currsum == sum)
            {
                return i;
            }
            currsum += nums[i];
        }
        if (currsum == sum)
        {
            return nums.size() - 1;
        }
        return -1;
    }
};