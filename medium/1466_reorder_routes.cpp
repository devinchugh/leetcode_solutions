#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int dfs(vector<vector<int>> &adj, vector<bool> &visited, int node)
    {
        int reorder = 0;
        for (auto &&to : adj[node])
        {
            if (!visited[abs(to)])
            {
                reorder += dfs(adj, visited, abs(to)) + (to > 0);
            }
        }
        return reorder;
    }

    int minReorder(int n, vector<vector<int>> &connections)
    {
        vector<vector<int>> adj(n);
        for (auto &&i : connections)
        {
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(-i[0]);
        }
        vector<bool> visited(n, 0);
        return dfs(adj, visited, 0);
    }
};