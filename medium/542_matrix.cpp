#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> updateMatrix(vector<vector<int>> &mat)
    {
        int m = mat.size();
        int n = mat[0].size();
        vector<vector<int>> ans(m, vector<int>(n, INT_MAX / 2));

        
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (mat[i][j] == 0)
                {
                    ans[i][j] = 0;
                }
                else
                {
                    int a = INT_MAX / 2;
                    int b = INT_MAX / 2;
                    if (i - 1 >= 0)
                    {
                        a = ans[i - 1][j];
                    }
                    if (j - 1 >= 0)
                    {
                        b = ans[i][j - 1];
                    }
                    ans[i][j] = min(ans[i][j], min(a, b) + 1);
                }
            }
        }
        for (int i = m - 1; i >= 0; i--)
        {
            for (int j = n - 1; j >= 0; j--)
            {
                if (mat[i][j] == 0)
                {
                    ans[i][j] = 0;
                }
                else
                {
                    int a = INT_MAX / 2;
                    int b = INT_MAX / 2;
                    if (i + 1 < m)
                    {
                        a = ans[i + 1][j];
                    }
                    if (j + 1 < n)
                    {
                        b = ans[i][j + 1];
                    }
                    ans[i][j] = min(ans[i][j], min(a, b) + 1);
                }
            }
        }

        return ans;
    }
};