#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long maximumTripletValue(vector<int> &nums)
    {

        int n = nums.size();
        long long ans = 0;
        priority_queue<pair<int, int>> pq;

        for (int i = 2; i < n; i++)
        {
            pq.push({nums[i], i});
        }

        int leftmax = nums[0];
        for (int i = 1; i < n; i++)
        {
            while (!pq.empty() && pq.top().second <= i)
            {
                pq.pop();
            }
            if (!pq.empty())
            {
                long long val = (long long)(leftmax - nums[i]) * (long long)pq.top().first;
                ans = max(ans, val);
            }
            leftmax = max(leftmax, nums[i]);
        }
        return ans;
    }
};