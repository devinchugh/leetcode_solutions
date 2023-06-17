#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int getans(vector<vector<char>> &maze,vector<vector<bool>> &visited, int m, int n, int currow, int curcol, int ans)
    {
        if ((curcol >= n || curcol < 0) || (currow >= m || currow < 0))
        {
            return ans;
        }
        if (maze[currow][curcol] == '+')
        {
            ans = INT_MAX;
            return ans;
        }
        if (visited[currow][curcol])
        {
            ans = INT_MAX;
            return ans;
        }
        visited[currow][curcol] = 1;
        int a = getans(maze,visited, m, n, currow, curcol + 1, ans + 1);
        int b = getans(maze,visited, m, n, currow + 1, curcol, ans + 1);
        int c = getans(maze,visited, m, n, currow - 1, curcol, ans + 1);
        int d = getans(maze,visited, m, n, currow, curcol - 1, ans + 1);
        return min({a, b, c, d});
    }
    int nearestExit(vector<vector<char>> &maze, vector<int> &entrance)
    {
        vector<vector<bool>> visited(101, vector<bool>(101, 0));
        int steps = getans(maze, visited, maze.size(), maze[0].size(), entrance[0], entrance[1], 0);

        if (steps < INT_MAX)
        {
            return steps;
        }
        return -1;
    }
};