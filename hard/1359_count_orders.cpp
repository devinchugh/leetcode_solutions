#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countOrders(int n) {
        int mod=1e9+7;
        //vector<long long> dp(n+1, 0);
        long long curr=1;

        //cout<<dp[1]<<endl;
        for (int i = 2; i <= n; i++)
        {
            curr=(((curr*i)%mod)*((2*i-1)%mod))%mod;
            curr=curr%mod;
        }
        return curr;
        
    }
};