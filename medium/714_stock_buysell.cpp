#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxProfit(vector<int> &prices, int fee)
    {
        int n = prices.size();
        int prevbuy=-prices[0];
        int prevsell=0;
        for (int i = 1; i < n; i++)
        {
            int a = prevbuy, b=prevsell;
            prevbuy = max(a, b - prices[i]);
            prevsell = max(b, a + prices[i] - fee);
        }
        return prevsell;
    }
};