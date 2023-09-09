#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> dp;
    bool checkstone(int k, int curr, int last, vector<int> &stones)
    {
        if (curr == last)
        {
            return true;
        }
        if (curr > last)
        {
            return false;
        }
        if (k <= 0)
        {
            return false;
        }

        if (dp[curr][k] != -1)
        {
            return dp[curr][k];
        }

        bool a = 0, b = 0, c = 0;
        int idx = curr + 1;
        while (idx < last && stones[idx] < stones[curr] + k - 1)
        {
            idx++;
        }
        if (stones[idx] == stones[curr] + k - 1)
        {
            a = checkstone(k - 1, idx, last, stones);
        }
        while (idx < last && stones[idx] < stones[curr] + k)
        {
            idx++;
        }
        if (stones[idx] == stones[curr] + k)
        {
            b = checkstone(k, idx, last, stones);
        }
        while (idx < last && stones[idx] < stones[curr] + k + 1)
        {
            idx++;
        }
        if (stones[idx] == stones[curr] + k + 1)
        {
            c = checkstone(k + 1, idx, last, stones);
        }
        return dp[curr][k] = a || b || c;
    }
    bool canCross(vector<int> &stones)
    {
        int n = stones.size();
        for (int i = 0; i < n + 1; i++)
        {
            vector<int> temp(n + 1, -1);
            dp.push_back(temp);
        }

        int last = stones[n - 1];

        if (stones[1] != 1)
        {
            return false;
        }
        return checkstone(1, 1, n - 1, stones);
    }
};