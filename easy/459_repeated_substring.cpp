#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool checkstring(string s, string pre)
    {

        for (int i = 0; i < s.size(); i++)
        {
            string x = s.substr(i, pre.size());

            if (x != pre)
            {
                return false;
            }
            i = i + pre.size() - 1;
        }

        return true;
    }
    bool repeatedSubstringPattern(string s)
    {
        string sub = "";

        for (int i = 0; i < s.size() / 2; i++)
        {
            sub += s[i];
            if (checkstring(s, sub))
            {
                return true;
            }
        }
        return false;
    }
};
