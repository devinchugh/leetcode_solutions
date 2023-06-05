#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int equalPairs(vector<vector<int>> &grid)
    {
        int ans = 0;
        int n = grid.size();
        vector<pair<int, int>> arr;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                bool found = 1;
                for (int k = 0; k < n; k++)
                {
                    if (grid[i][k] != grid[k][j])
                    {
                        found = 0;
                        break;
                    }
                }
                if (found)
                {
                    ans++;
                    arr.push_back({i, j});
                }
            }
        }
        return ans;
    }
};