#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> findDifference(vector<int> &nums1, vector<int> &nums2)
    {
        map<int, int> mp1, mp2;

        for (auto &&i : nums1)
        {
            mp1[i]++;
        }
        for (auto &&i : nums2)
        {
            mp2[i]++;
        }
        vector<vector<int>> ans(2);
        for (auto &&i : mp1)
        {
            if (mp2[i.first] == 0)
            {
                ans[0].push_back({i.first});
            }
        }
        for (auto &&i : mp2)
        {
            if (mp1[i.first] == 0)
            {

                ans[1].push_back({i.first});
            }
        }
        return ans;
    }
};