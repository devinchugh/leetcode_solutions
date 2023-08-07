#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void getans(vector<int> &nums, int ind, set<vector<int>> &myans)
    {
        if (ind == nums.size())
        {
            myans.insert(nums);
        }

        for (int i = ind; i < nums.size(); i++)
        {
            if (i != ind && nums[i] == nums[ind])
            {
                continue;
            }
            swap(nums[i], nums[ind]);
            getans(nums, ind + 1, myans);
            swap(nums[i], nums[ind]);
        }
    }
    vector<vector<int>> permuteUnique(vector<int> &nums)
    {
        // remove duplicates
        // backtracking:
        sort(nums.begin(), nums.end());
        set<vector<int>> myans;
        getans(nums,0,myans);
        vector<vector<int>> ans(myans.begin(), myans.end());
        return ans;
    }
};