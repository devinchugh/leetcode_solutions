#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        if(n==2){
            return min(cost[0],cost[1]);
        }
        int prev1=0, prev2=0;
        int curr;
        for (int i = 2; i <= n; i++)
        {
            curr=min(prev1+cost[i-1], prev2+cost[i-2]);
            prev2=prev1;
            prev1=curr;
        }
        return prev1;
    }
};