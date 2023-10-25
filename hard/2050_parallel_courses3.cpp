#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int calculate_time(int course, vector<int> &time, vector<int> &dp, vector<vector<int>> &course_graph)
    {
        if (dp[course] != -1)
        {
            return dp[course];
        }

        if (course_graph.empty())
        {
            dp[course] = time[course];
            return time[course];
        }

        int t1 = time[course];
        int maxi = 0;
        for (auto &&pre : course_graph[course])
        {
            maxi = max(maxi, calculate_time(pre, time, dp, course_graph));
        }
        t1 += maxi;
        return dp[course] = t1;
    }
    int minimumTime(int n, vector<vector<int>> &relations, vector<int> &time)
    {

        vector<vector<int>> course_graph(n);

        for (auto &&c : relations)
        {
            int prev = c[0] - 1;
            int nex = c[1] - 1;
            course_graph[nex].push_back(prev);
        }

        int min_time = 0;
        vector<int> dp(n, -1);
        for (int i = 0; i < n; i++)
        {
            min_time = max(min_time, calculate_time(i, time, dp, course_graph));
        }
        return min_time;
    }
};