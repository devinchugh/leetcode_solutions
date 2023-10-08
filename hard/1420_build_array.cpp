#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int N, M, K, mod = 1e9 + 7;
    int dp[51][101][51];
    int solve(int idx, int lar, int lis)
    {
        if (idx == N)
        {
            if (lis == K)
            {
                return 1;
            }
            return 0;
        }
        int ans = 0;
        if(dp[idx][lar][lis]!=-1){
            return dp[idx][lar][lis];
        }

        for (int i = 1; i <= M; i++)
        {
            if (i > lar)
            {
                ans += solve(idx + 1, i, lis + 1);
            }
            else
            {
                ans += solve(idx + 1, lar, lis);
            }
            ans%=mod;
        }
        return dp[idx][lar][lis]=ans;
    }
    int numOfArrays(int n, int m, int k)
    {
        memset(dp,-1,sizeof(dp));
        return solve(0,-1,0);
    }
};