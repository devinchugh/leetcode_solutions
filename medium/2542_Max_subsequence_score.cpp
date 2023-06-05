#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long maxScore(vector<int> &nums1, vector<int> &nums2, int k)
    {
        priority_queue<pair<int, int>> pq;
        int n = nums1.size();
        for (int i = 0; i < n; i++)
        {
            pq.push({nums2[i], nums1[i]});
        }

        long long ans = 0;
        priority_queue<int, vector<int>, greater<int>> minhp;
        for (int i = 0; i < k - 1; i++)
        {
            ans += pq.top().second;
            minhp.push(pq.top().second);
            pq.pop();
        }
        ans += pq.top().second;
        minhp.push(pq.top().second);
        long long maxi = ans * pq.top().first;
        pq.pop();

        for (int i = k; i < n; i++)
        {
            ans = ans + pq.top().second - minhp.top();
            minhp.pop();
            minhp.push(pq.top().second);
            maxi = max(maxi, ans * pq.top().first);
            pq.pop();
        }
        return maxi;
    }
};