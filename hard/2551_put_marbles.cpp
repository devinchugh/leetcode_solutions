#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long putMarbles(vector<int> &weights, int k)
    {

        int n = weights.size();
        if (n <= k)
        {
            return 0;
        }
        vector<int> dp(n-1, 0);

        for (int i = 0; i < n - 1; i++)
        {
            dp[i] = weights[i] + weights[i + 1];
        }
        sort(dp.begin(), dp.end());

        long long maxscore = 0;
        long long minscore = 0;

        for (int i = n - 2; i >= n - k; i--)
        {
            maxscore += dp[i];
        }
        for (int i = 0; i < k-1; i++)
        {
            minscore += dp[i];
        }
        return maxscore - minscore;
    }
};