#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> topKFrequent(vector<int> &nums, int k)
    {
        unordered_map<int, int> mp;
        if (k == nums.size())
        {
            return nums;
        }
        for (auto &&i : nums)
        {
            mp[i]++;
        }
        vector<int> ans;
        vector<pair<int, int>> arr(mp.begin(), mp.end());

        sort(begin(arr), end(arr), [](pair<int, int> a, pair<int, int> b)
             { return a.second > b.second; });

        for (int i = 0; i < k; i++)
        {
            ans.push_back(arr[i].first);
        }

        return ans;
    }
};