#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> ans;
    void getpath(vector<vector<int>> &graph, int node, vector<int> &path)
    {
        int n = graph.size();
        path.push_back(node);
        if (node == n - 1)
        {
            ans.push_back(path);
        }
        else
        {
            for (auto &&neigh : graph[node])
            {
                getpath(graph, neigh, path);
            }
        }
        path.pop_back();
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>> &graph)
    {
        int n = graph.size();
        vector<int> path;
        getpath(graph, 0, path);
        return ans;
    }
};