#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maximalNetworkRank(int n, vector<vector<int>> &roads)
    {
        vector<int> indegree(n, 0);
        vector<vector<int>> roadconnect(n, vector<int>(n, 0));

        for (int i = 0; i < roads.size(); i++)
        {
            indegree[roads[i][0]]++;
            indegree[roads[i][1]]++;
            roadconnect[roads[i][0]][roads[i][1]] = 1;
            roadconnect[roads[i][1]][roads[i][0]] = 1;
        }
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (i != j)
                {
                    if (roadconnect[i][j])
                    {
                        ans = max(indegree[i] + indegree[j] - 1, ans);
                    }
                    else
                    {
                        ans = max(indegree[i] + indegree[j], ans);
                    }
                }
            }
        }
        return ans;
    }
};