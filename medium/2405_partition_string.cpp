#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int partitionString(string s)
    {
        map<char, bool> mp;
        int n = 1;

        for (auto &&chr : s)
        {
            if (mp[chr])
            {
                n++;
                mp.clear();
            }
            mp[chr] = 1;
        }

        return n;
    }
};