#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> ans;
    void getans(int n, int k, vector<int> &curr, int val)
    {

        if (curr.size() == k)
        {
            ans.push_back(curr);
            return;
        }

        for (int i = val; i <= n; i++)
        {
            curr.push_back(i);
            getans(n, k, curr, i + 1);
            curr.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k)
    {
        vector<int> s;
        getans(n, k, s, 1);
        return ans;
    }
};