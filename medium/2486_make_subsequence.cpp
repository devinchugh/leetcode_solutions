#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int appendCharacters(string s, string t)
    {
        int n = s.size();
        int m = t.size();

        int i = 0, j = 0;

        while (i < n && j < m)
        {
            if (s[i] == t[j])
            {
                i++;
                j++;
            }
            else
            {
                i++;
            }
        }

        if (m - j > 0)
        {
            return m - j;
        }
        return 0;
    }
};