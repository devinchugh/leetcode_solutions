#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int mod = 1e9 + 7;
    vector<char> val = {'a', 'e', 'i', 'o', 'u'};
    vector<vector<int>> dp;
    int getans(int n, int i, int j)
    {

        if (i == n)
        {
            return 1;
        }
        if (j == -1)
        {
            int ans = 0;
            for (int x = 0; x < 5; x++)
            {
                ans += (getans(n, i + 1, x) % mod);
                ans %= mod;
            }
            return ans;
        }

        if (dp[i][j] != -1)
        {
            return dp[i][j];
        }
        if (j == 0)
        {
            return dp[i][j] = getans(n, i + 1, 1);
        }
        else if (j == 1)
        {
            int ans = 0;
            ans += (getans(n, i + 1, 0) % mod);
            ans %= mod;
            ans += (getans(n, i + 1, 2) % mod);
            ans %= mod;
            return dp[i][j] = ans;
        }
        else if (j == 2)
        {
            int ans = 0;
            for (int x = 0; x < 5; x++)
            {
                if (x != 2)
                {
                    ans += (getans(n, i + 1, x) % mod) % mod;
                    ans%=mod;
                }
            }
            return dp[i][j] = ans;
        }
        else if (j == 3)
        {
            int ans = 0;
            ans += (getans(n, i + 1, 2) % mod);
            ans%=mod;
            ans += (getans(n, i + 1, 4) % mod);
            ans%=mod;
            return dp[i][j] = ans;
        }

        return dp[i][j] = getans(n, i + 1, 0) % mod;
    }
    int countVowelPermutation(int n)
    {
        for (int i = 0; i < n; i++)
        {
            vector<int> temp(5, -1);
            dp.push_back(temp);
        }

        return getans(n, 0, -1);
    }
};