#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string removeStars(string s)
    {
        stack<char> ans;

        for (auto &&i : s)
        {
            if (i == '*')
            {
                if (!ans.empty())
                {
                    ans.pop();
                }
            }
            else
            {
                ans.push(i);
            }
        }
        if (ans.size() == 0)
        {
            return "";
        }
        string ch;
        while (!ans.empty())
        {
            ch += ans.top();
            // cout<<ch[i]<<endl;
            ans.pop();
        }
        reverse(ch.begin(), ch.end());
        return ch;
    }
};