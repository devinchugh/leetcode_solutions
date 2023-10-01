#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> groupThePeople(vector<int> &groupSizes)
    {
        vector<vector<int>> ans;
        int n = groupSizes.size();

        map<int, vector<int>> mp;

        for (int i = 0; i < n; i++)
        {
            mp[groupSizes[i]].push_back(i);
        }

        for (auto &&i : mp)
        {
            int grp_sz = i.first;
            int sz = i.second.size();
            int idx = 0;
            for (int _ = 0; _ < sz / grp_sz; _++)
            {
                vector<int> temp;
                for (int x = 0; x < grp_sz; x++)
                {
                    temp.push_back(i.second[idx]);
                    idx++;
                }
                ans.push_back(temp);
            }
        }
        return ans;
    }
};