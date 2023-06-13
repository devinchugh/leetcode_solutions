#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void visit(vector<vector<int>> &isConnected, vector<bool> &visited, int j)
    {
        visited[j] = 1;
        int n = isConnected.size();
        for (int i = 0; i < n; i++)
        {
            if (isConnected[j][i] && visited[i] == 0)
            {
                visit(isConnected, visited, i);
            }
        }
        return;
    }
    int findCircleNum(vector<vector<int>> &isConnected)
    {
        int n = isConnected.size();
        vector<bool> visited(n, 0);
        int count = 0;
        for (int i = 0; i < n; i++)
        {
            if (!visited[i])
            {
                count++;
                visit(isConnected, visited, i);
            }
        }
        return count;
    }
};