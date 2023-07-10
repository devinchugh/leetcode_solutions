#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>>dp;
    int getans(vector<int> &values, int i, int j)
    {
        if (i == j - 1)
        {
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int mini = INT_MAX / 2;

        for (int k = i + 1; k < j; k++)
        {
            int curr = values[i] * values[j] * values[k];
            mini = min(mini, curr + getans(values, i , k) + getans(values, k, j ));
        }
        return dp[i][j]=mini;
    }
    int minScoreTriangulation(vector<int> &values)
    {
        int n=values.size();
        for (int i = 0; i < n; i++)
        {
            vector<int> temp(n,-1);
            dp.push_back(temp);
        }
        
        return getans(values,0,values.size()-1);
    }
};