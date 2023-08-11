#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> dp;
    const int mod = 1e9 + 7;
    int getroutes(vector<int> &locations, int curr, int finish, int fuel)
    {
        if (fuel < 0)
        {
            return 0;
        }
        if (dp[curr][fuel] != -1)
        {
            return dp[curr][fuel];
        }

        dp[curr][fuel] = 0;
        if (curr == finish)
        {
            dp[curr][fuel]++;
        }

        for (int i = 0; i < locations.size(); i++)
        {
            if (i != curr)
                dp[curr][fuel] += getroutes(locations, i, finish, fuel - abs(locations[curr] - locations[i])) % mod;
            dp[curr][fuel] %= mod;
        }
        return dp[curr][fuel];
    }
    int countRoutes(vector<int> &locations, int start, int finish, int fuel)
    {

        for (int i = 0; i < 101; i++)
        {
            vector<int> temp(201, -1);
            dp.push_back(temp);
        }
        int ans = 0;
        getroutes(locations, start, finish, fuel);
        for (auto &&val : dp[start])
        {
            if (val > 0)
            {
                ans += val % mod;
                ans %= mod;
            }
        }
        return dp[start][fuel];
    }
};