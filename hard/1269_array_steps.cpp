#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int mod= 1e9+7;
    int getways(int steps, int arrlen, int pos, vector<map<int,int>> &dp)
    {
        if (steps == 0)
        {
            if (pos == 0)
            {
                return 1;
            }
            return 0;
        }
        if (pos >= arrlen or pos < 0)
        {
            return 0;
        }
        if(dp[steps][pos]){
            return dp[steps][pos];
        }

        int a = getways(steps-1, arrlen, pos + 1, dp) %mod;
        int b = getways(steps-1, arrlen, pos - 1, dp)%mod;
        int c = getways(steps-1, arrlen, pos, dp)%mod;

        return dp[steps][pos] = (a + b + c)%mod;
    }
    int numWays(int steps, int arrLen)
    {
        vector<map<int,int>> dp(501);
        return getways(steps, arrLen, 0, dp);
    }
};