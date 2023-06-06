#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool increasingTriplet(vector<int> &nums)
    {
        int mini = INT_MAX;
        int nextmini = INT_MAX;
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            if (nums[i] > nextmini)
                return true;
            mini = min(nums[i], mini);
            if (nums[i] < nextmini && nums[i] > mini)
            {
                nextmini = nums[i];
            }
        }
        return false;
    }
};