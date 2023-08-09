#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool checkarr(vector<int> &nums, int p, int diff)
    {

        int st = 0;
        int count = 0;
        while (st + 1 < nums.size())
        {
            if (abs(nums[st] - nums[st + 1]) <= diff)
            {
                count++;
                st += 2;
            }
            else{
                st++;
            }

            if (count >= p)
            {
                return true;
            }

        }
        return false;
    }
    int minimizeMax(vector<int> &nums, int p)
    {
        sort(nums.begin(), nums.end());
        int n = nums.size();

        int l = 0, r = nums[n - 1] - nums[0];
        int mid;
        while (l < r)
        {
            mid = (r+l)/2;
            if (checkarr(nums, p, mid))
            {
                r = mid;
            }
            else
            {
                l = mid+1;
            }
        }
        return l;
    }
};