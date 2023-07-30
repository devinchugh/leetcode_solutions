#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    double getans(int na, int nb, vector<vector<double>> &dp)
    {
        if (na <= 0 && nb <= 0)
        {
            return 0.5;
        }
        if (na <= 0)
        {
            return 1;
        }
        if (nb <= 0)
        {
            return 0;
        }
        if(na>=4800){
            return 1.0;
        }
        if(na>=4800 || nb>=4800){
            return 1.0;
        }

        if (dp[na][nb] >= 0)
        {
            return dp[na][nb];
        }
        double prob = 0;
        prob += 0.25 * getans(na - 100, nb, dp);
        prob += 0.25 * getans(na - 75, nb - 25, dp);
        prob += 0.25 * getans(na - 50, nb - 50, dp);
        prob += 0.25 * getans(na - 25, nb - 75, dp);

        return dp[na][nb] = prob;
    }
    double soupServings(int n)
    {
        vector<vector<double>> dp(4800 + 1, vector<double>(4800 + 1, -1.0));
        return getans(n, n, dp);
    }
};