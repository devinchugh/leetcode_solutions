#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<long long> dp;
    long long getpoints(vector<vector<int>> &questions, int idx)
    {
        if (idx >= questions.size())
        {
            return 0;
        }
        if (dp[idx] != -1)
        {
            return dp[idx];
        }
        long long a = getpoints(questions, idx + 1);
        long long b = questions[idx][0] + getpoints(questions, idx + questions[idx][1] + 1);

        return dp[idx] = max(a, b);
    }
    long long mostPoints(vector<vector<int>> &questions)
    {
        for (int i = 0; i <= questions.size(); i++)
        {
            dp.push_back(-1);
        }

        return getpoints(questions, 0);
    }
};