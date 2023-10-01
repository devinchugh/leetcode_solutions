#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minOperations(vector<int> &nums, int x)
    {
        int sum = 0;
        for (auto &&i : nums)
        {
            sum += i;
        }
        if (x > sum)
        {
            return -1;
        }

        int l = 0, r = 0;
        int findsum = sum - x;
        int check = 0;
        int ans = INT_MAX;

        for (r = 0; r < nums.size(); r++)
        {
            check += nums[r];
            
            while (check > findsum)
            {
                check -= nums[l];
                l++;
            }
            if (check == findsum)
            {
                ans = min(ans, (int)nums.size() - (r - l + 1));
            }
        }
        if(ans>INT_MAX/2){
            return -1;
        }
        return ans;
    }
};