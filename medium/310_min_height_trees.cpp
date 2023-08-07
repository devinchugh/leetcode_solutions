#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>> &edges)
    {

        if (n == 1)
        {
            return {0};
        }

        
        vector<vector<int>> adj_list(n);
        vector<int> indegrees(n, 0);

        for (auto &&edge : edges)
        {
            int i = edge[0], j = edge[1];
            adj_list[i].push_back(j);
            adj_list[j].push_back(i);
            indegrees[i]++;
            indegrees[j]++;
        }

        queue<int> q;

        for (int i = 0; i < n; i++)
        {
            if (indegrees[i] == 1)
            {
                q.push(i);
            }
        }

        while (n > 2)
        {
            int numleaves = q.size();
            n -= numleaves;

            for (int i = 0; i < numleaves; i++)
            {
                int x = q.front();
                q.pop();

                for (auto &&neigh : adj_list[x])
                {
                    indegrees[neigh]--;
                    if (indegrees[neigh] == 1)
                    {
                        q.push(neigh);
                    }
                }
            }
        }
        vector<int> ans;
        while (!q.empty())
        {
            ans.push_back(q.front());
            q.pop();
        }
        return ans;
    }
};