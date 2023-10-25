#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int constrainedSubsetSum(vector<int>& nums, int k) {
        int n=nums.size();

        vector<int> dp(n, 0);

        priority_queue<pair<int,int>> pq;
        pq.push({nums[0], 0});

        int res=nums[0];
        for (int i = 1; i < n; i++)
        {
            while (!pq.empty() && i-pq.top().second>k)
            {
                pq.pop();
            }

            dp[i]=max(nums[i], nums[i]+pq.top().first);
            pq.push({dp[i], i});
            res=max(res, dp[i]);
            
        }
        return res;
        
    }
};