#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        int n = s.size();
        if (n == 0)
        {
            return 0;
        }
        int maxi = 1;
        int l = 0, r = 0;
        unordered_map<char, bool> mp;

        while (r < n)
        {
            maxi = max(maxi, r - l);
            if (!mp[s[r]])
            {
                mp[s[r]] = 1;
                r++;
            }
            else
            {
                while (mp[s[r]])
                {
                    mp[s[l]] = 0;
                    l++;
                }
                mp[s[r]] = 1;
                r++;
            }
        }
        maxi = max(maxi, r - l);
        return maxi;
    }
};