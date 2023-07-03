#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int countPoints(string rings)
    {
        map<int, set<char>> mp;
        int n = rings.size();
        if (n / 2 < 3)
        {
            return 0;
        }
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            if (rings[i] == 'R' || rings[i] == 'G' || rings[i] == 'B')
            {
                char x = rings[i];
                i++;
                mp[rings[i] - '0'].insert(x);
            }
        }
        for (auto &&i : mp)
        {
            if (i.second.size() == 3)
            {
                ans++;
            }
        }

        return ans;
    }
};