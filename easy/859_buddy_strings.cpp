#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool buddyStrings(string s, string goal)
    {
        if (s.size() <= 1 || s.size() != goal.size())
        {
            return false;
        }
        int n = s.size();
        int count = 0;
        if (s == goal)
        {
            set<char> arr(s.begin(), s.end());
            return arr.size() < goal.size();
        }
        int l = 0, r = n - 1;
        while (s[l] == goal[l])
        {
            l++;
        }
        while (s[r] == goal[r])
        {
            r--;
        }
        swap(s[l], s[r]);
        return s == goal;
    }
};