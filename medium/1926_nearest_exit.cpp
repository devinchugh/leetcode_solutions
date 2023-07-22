#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int nearestExit(vector<vector<char>> &maze, vector<int> &entrance)
    {
        int m = maze.size();
        int n = maze[0].size();

        int currrow = entrance[0];
        int currcol = entrance[1];

        queue<pair<int, int>> q;
        q.push({currrow, currcol});
        int steps = 1;
        maze[currrow][currcol] = '+';
        vector<vector<int>> offsets = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

        while (!q.empty())
        {
            int x = q.size();
            for (int _ = 0; _ < x; _++)
            {
                pair<int, int> t = q.front();
                q.pop();

                for (int k = 0; k < 4; k++)
                {
                    int r = t.first + offsets[k][0], c = t.second + offsets[k][1];

                    if (r < 0 || c < 0 || r >= m || c >= n || maze[r][c] == '+')
                    {
                        continue;
                    }

                    if (r == 0 || r == m - 1 || c == 0 || c == n - 1)
                    {
                        return steps;
                    }
                    maze[r][c]='+';
                    q.push({r, c});
                }
            }
            steps++;
        }
        return -1;
    }
};