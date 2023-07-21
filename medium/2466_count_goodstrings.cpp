#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int countGoodStrings(int low, int high, int zero, int one)
    {
        int mod = 1e9 + 7;
        vector<int> dp(high + 1, 0);
        dp[0] = 1;
        int count = 0;

        for (int i = 1; i <= high; i++)
        {
            if (i - zero >= 0)
            {
                dp[i] += dp[i - zero];
            }
            if (i - one >= 0)
            {
                dp[i] += dp[i - one];
            }
            dp[i] = dp[i] % mod;
            if (i >= low)
            {
                count += dp[i];
                count = count % mod;
            }
        }
        return count;
    }
};