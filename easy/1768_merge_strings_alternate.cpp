#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string mergeAlternately(string word1, string word2)
    {
        string ans = "";
        int i = 0, j = 0;
        bool x = 1;
        while (i < word1.size() && j < word2.size())
        {
            if (x)
            {
                ans += word1[i];
                i++;
            }
            else
            {
                ans += word2[j];
                j++;
            }
        }
        while (i < word1.size())
        {
            ans += word1[i];
            i++;
        }
        while (j < word2.size())
        {
            ans += word2[j];
            j++;
        }
        return ans;
    }
};