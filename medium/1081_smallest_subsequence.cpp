#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string smallestSubsequence(string s)
    {
        vector<int> last(26), seen(26, 0);
        for (int i = 0; i < s.size(); i++)
        {
            last[s[i] - 'a'] = i;
        }

        string res;
        stack<int> st;

        for (int i = 0; i < s.size(); i++)
        {
            if (seen[s[i] - 'a'])
            {
                seen[s[i] - 'a']++;
                continue;
            }

            while (!res.empty() && res.back() > s[i] && last[res.back() - 'a'] > i)
            {
                seen[res.back() - 'a'] = 0;
                res.pop_back();
            }
            res.push_back(s[i]);
            seen[s[i] - 'a']++;
        }
        return res;
    }
};