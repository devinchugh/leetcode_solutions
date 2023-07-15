#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    unordered_map<int, bool> visited;
    unordered_map<int, bool> rec_stack;
    bool checkcycle(vector<vector<int>> &adj_list, int curr)
    {
        if (rec_stack[curr])
        {
            return true;
        }
        if (visited[curr])
        {
            return false;
        }

        visited[curr] = 1;
        rec_stack[curr] = 1;
        for (auto &&i : adj_list[curr])
        {
            if (!visited[i] && checkcycle(adj_list, i))
            {
                return true;
            }
            if(rec_stack[i]){
                return true;
            }
        }
        rec_stack[curr] = 0;
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>> &pre)
    {
        vector<vector<int>> adj_list(numCourses);

        for (auto &&i : pre)
        {
            adj_list[i[0]].push_back(i[1]);
        }
        for (int i = 0; i < numCourses; i++)
        {
            if (!visited[i] && checkcycle(adj_list, i))
            {
                return false;
            }
        }
        return true;
    }
};