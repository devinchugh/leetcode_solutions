#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int numberOfArithmeticSlices(vector<int> &nums)
    {
        int n = nums.size();
        if (nums.size() < 3)
        {
            return 0;
        }

        int count = 0;

        vector<int> dp(n, 0);

        if(nums[2]-nums[1]==nums[1]-nums[0]){
            dp[2]=1;
        }

        for (int i = 2; i < n; i++)
        {
            if(nums[i]-nums[i-1]==nums[i-1]-nums[i-2]){
                dp[i]=dp[i-1]+1;
            }
            count+=dp[i];
        }
        
        return count;
    }
};