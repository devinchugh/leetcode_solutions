#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> kSmallestPairs(vector<int> &nums1, vector<int> &nums2, int k)
    {
        vector<vector<int>> ans;
        int i = 0, j = 0;
        int n = nums1.size(), m = nums2.size();
        priority_queue<vector<int>, vector<vector<int>>, greater<> > pq;
        for (int i = 0; i < n; i++)
        {
            pq.push({nums1[i] + nums2[0], i, 0});
            //cout<<pq.size();
        }

        for (int i = 0; i < k; i++)
        {
            if(pq.empty()){
                continue;
            }
            vector<int> temp = pq.top();
            pq.pop();
            //cout<<pq.size();
            ans.push_back({nums1[temp[1]], nums2[temp[2]]});
            if (temp[2] < m - 1)
            {
                pq.push({nums1[temp[1]] + nums2[temp[2] + 1], temp[1], temp[2] + 1});
            }
        }
        return ans;
    }
};