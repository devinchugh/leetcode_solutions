#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> dp;
    // next non-conflicting house range index that can be sold
    int search(vector<vector<int>> &offers, int end, int idx)
    {
        int n = offers.size();
        int l = idx, r = n - 1;
        int i = -1;
        while (l <= r)
        {
            int m = l + (r - l) / 2;
            int start = offers[m][0];
            if (start > end)
            {
                i = m;
                r = m - 1;
            }
            else
            {
                l = m + 1;
            }
        }
        return i;
    }
    int getprofit(vector<vector<int>> &offers, int pos)
    {
        if (pos == offers.size())
        {
            return 0;
        }

        if (dp[pos] != -1)
        {
            return dp[pos];
        }
        int profit = 0;
        int nottaken = getprofit(offers, pos + 1);
        int nextidx = search(offers, offers[pos][1], pos);
        if (nextidx != -1)
        {
            profit += getprofit(offers, nextidx);
            
        }
        profit += offers[pos][2];

        return dp[pos] = max(profit, nottaken);
    }
    int maximizeTheProfit(int n, vector<vector<int>> &offers)
    {
        for (int i = 0; i < offers.size(); i++)
        {

            dp.push_back(-1);
        }

        // start, end, gold;
        sort(offers.begin(), offers.end());
        int profit = getprofit(offers, 0);

        return profit;
    }
};
