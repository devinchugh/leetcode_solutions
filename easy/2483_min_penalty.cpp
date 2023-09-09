#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> dp;
    int getans(int pos, string &customers, int prev, int nextloss)
    {
        if (pos == customers.size())
        {
            dp[pos] = prev;
            return 0;
        }

        int currpenalty = prev + nextloss;
        dp[pos] = currpenalty;
        if (customers[pos] == 'N')
        {
            prev++;
        }
        if (customers[pos] == 'Y')
        {
            nextloss--;
        }
        getans(pos + 1, customers, prev, nextloss);
        return 0;
    }
    int bestClosingTime(string customers)
    {
        vector<int> temp(customers.size() + 1, 0);
        dp = temp;
        int n = customers.size();
        int rightloss = 0;
        for (int i = 0; i < n; i++)
        {
            if (customers[i] == 'Y')
            {
                rightloss++;
            }
        }

        getans(0, customers, 0, rightloss);
        int idx, maxi = INT_MAX;
        for (int i = 0; i <= customers.size(); i++)
        {
            // cout<<dp[i]<<" ";
            if (maxi > dp[i])
            {
                maxi = dp[i];
                idx = i;
            }
        }
        return idx;
    }
};