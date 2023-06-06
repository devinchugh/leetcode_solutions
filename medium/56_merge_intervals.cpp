#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> merge(vector<vector<int>> &in)
    {
        sort(in.begin(), in.end());
        vector<vector<int>> ans;
        int n = in.size();
        if (n <= 1)
        {
            return in;
        }
        ans.push_back(in[0]);

        for (int i = 1; i < n; i++)
        {
            int m = ans.size();
            if (ans[m - 1][1] >= in[i][0])
            {
                ans[m - 1][1] = max(in[i][1], ans[m - 1][1]);
            }
            else
            {
                ans.push_back(in[i]);
            }
        }
        return ans;
    }
};