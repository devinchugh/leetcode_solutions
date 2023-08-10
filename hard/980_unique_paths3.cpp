#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> visited;
    int getpaths(vector<vector<int>> &grid, int i, int j, int count, int maxi)
    {
        int m = grid.size(), n = grid[0].size();
        if ((i < 0 || i >= m) || (j < 0 || j >= n))
        {
            return 0;
        }
        if (visited[i][j] || grid[i][j] == -1)
        {
            return 0;
        }
        if (grid[i][j] == 2 && count-1 == maxi)
        {
            return 1;
        }
        visited[i][j] = 1;
        int a = getpaths(grid, i - 1, j, count + 1, maxi);
        int b = getpaths(grid, i + 1, j, count + 1, maxi);
        int c = getpaths(grid, i, j + 1, count + 1, maxi);
        int d = getpaths(grid, i, j - 1, count + 1, maxi);

        visited[i][j] = 0;
        return a + b + c + d;
    }
    int uniquePathsIII(vector<vector<int>> &grid)
    {
        int m = grid.size(), n = grid[0].size();
        for (int i = 0; i < m; i++)
        {
            vector<int> temp(n, 0);
            visited.push_back(temp);
        }
        int maxcount = 0;
        int x = 0, y = 0;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 0)
                {
                    maxcount++;
                }
                if (grid[i][j] == 1)
                {
                    x = i;
                    y = j;
                }
            }
        }
        return getpaths(grid, x, y, 0, maxcount);
    }
};