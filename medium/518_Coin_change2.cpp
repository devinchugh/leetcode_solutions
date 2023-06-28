#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int ans;
    map<int, int> mp;
    void findans(int amount, vector<int> &coins, int curr)
    {
        if (amount == 0)
        {
            ans++;
            return;
        }
        if (amount < 0 || curr >= coins.size())
        {
            return;
        }
        if (mp[amount])
        {
        }
        if (amount - coins[curr] == 0)
        {
            ans++;
            findans(amount, coins, curr + 1);
            cout << curr << endl;
            return;
        }
        findans(amount - coins[curr], coins, curr);
        findans(amount, coins, curr + 1);
    }
    int change(int amount, vector<int> &coins)
    {
        vector<int> dp(amount + 1, 0);

        for (int j = 0; j < coins.size(); j++)
        {
            for (int i = 1; i <= amount; i++)
            {
                if (i - coins[j] >= 0)
                {
                    dp[j] += dp[i - coins[j]];
                }
            }
        }

        return dp[amount];
    }
};