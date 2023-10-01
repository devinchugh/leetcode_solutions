#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> intersection(vector<vector<int>> &nums)
    {
        vector<set<int>> arr;
        for (int i = 0; i < nums.size(); i++)
        {
            set<int> temp(nums[i].begin(), nums[i].end());
            arr.push_back(temp);
        }
        vector<int> ans;
        for (auto num : arr[0])
        {
            bool chk = 1;
            for (int i = 1; i < arr.size(); i++)
            {
                if (arr[i].find(num) == arr[i].end())
                {
                    chk = 0;
                    break;
                }
            }
            if (chk)
            {
                ans.push_back(num);
            }
        }
        return ans;
    }
};