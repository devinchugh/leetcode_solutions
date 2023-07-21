#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<string>> ans;
    bool check(string a)
    {
        int n = a.size();
        for (int i = 0; i < n / 2; i++)
        {
            if (a[i] != a[n - i - 1])
            {
                return false;
            }
        }
        return true;
    }
    void getans(string &s, int currpos, vector<string> curr)
    {
        int n = curr.size();
        if (currpos >= s.size())
        {
            if (check(curr[n - 1]))
                ans.push_back(curr);
            return;
        }
        if (curr.empty())
        {
            string a = "";
            a += s[currpos];
            curr.push_back(a);
            getans(s, currpos + 1, curr);
            return;
        }
        if (check(curr[n - 1]))
        {
            string a = "";
            a += s[currpos];
            curr.push_back(a);
            getans(s, currpos + 1, curr);
            curr.pop_back();
        }

        curr[n - 1] += s[currpos];
        getans(s, currpos + 1, curr);
    }
    vector<vector<string>> partition(string s)
    {
        getans(s,0,{});
        return ans;
    }
};