#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    double findMaxAverage(vector<int> &nums, int k)
    {
        double ans = 0;
        const int n = nums.size();
        for (int i = 0; i < k; i++)
        {
            ans += nums[i];
        }
        double maxi = ans / k;
        for (int i = k; i < n; i++)
        {
            ans -= nums[i - k];
            ans += nums[i];
            maxi = max(maxi, ans / k);
        }
        return maxi;
    }
};