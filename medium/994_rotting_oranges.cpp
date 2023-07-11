#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool check_rotten(vector<vector<int>> &grid)
    {
        int m = grid.size(), n = grid[0].size();

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 1)
                {
                    return false;
                }
            }
        }
        return true;
    }
    int orangesRotting(vector<vector<int>> &grid)
    {
        int min = 0;
        int m = grid.size(), n = grid[0].size();
        queue<vector<int>> q;
        vector<vector<int>> visited(11, vector<int>(11, 0));
        vector<vector<int>> arr = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        if (check_rotten(grid))
        {
            return 0;
        }
        while (!check_rotten(grid))
        {
            for (int i = 0; i < grid.size(); i++)
            {
                for (int j = 0; j < grid[0].size(); j++)
                {
                    if (!visited[i][j] && grid[i][j] == 2)
                    {
                        q.push({i, j});
                    }
                }
            }
            if (q.empty())
            {
                return -1;
            }
            while (!q.empty())
            {
                int a = q.front()[0];
                int b = q.front()[1];
                visited[a][b] = 1;
                q.pop();
                for (int z = 0; z < 4; z++)
                {
                    if (a + arr[z][0] >= 0 && a + arr[z][0] < m && b + arr[z][1] >= 0 && b + arr[z][1] < n)
                    {
                        // visited[a + arr[z][0]][b + arr[z][1]] = 1;
                        if (grid[a + arr[z][0]][b + arr[z][1]] == 1)
                            grid[a + arr[z][0]][b + arr[z][1]] = 2;
                    }
                }
            }
            min++;
        }
        return min;
    }
};