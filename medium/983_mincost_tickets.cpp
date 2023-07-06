#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> dp;
    int getans(vector<int> &days, vector<int> &costs, int curr)
    {
        if (curr >= days.size())
        {
            return 0;
        }
        if(dp[curr]!=-1){
            return dp[curr];
        }
        int cost1 = getans(days, costs, curr + 1) + costs[0];
        int currday = days[curr];
        int day = curr;
        while (day< days.size() && days[day] < currday + 7)
        {
            day++;
        }
        int cost7 = getans(days, costs, day) + costs[1];
        while (day< days.size() && days[day] < currday + 30)
        {
            day++;
        }
        int cost30 = getans(days, costs, day) + costs[2];
        return dp[curr]=min({cost1, cost7, cost30});
    }
    int mincostTickets(vector<int> &days, vector<int> &costs)
    {
        for (int i = 0; i <= days.size(); i++)
        {
            dp.push_back(-1);
        }
        
        return getans(days,costs, 0);
    }
};