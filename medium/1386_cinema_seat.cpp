#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxNumberOfFamilies(int n, vector<vector<int>> &resSeats)
    {
        int maxseats = 2 * n;
        unordered_map<int, vector<int>> mp;
        for (auto &&i : resSeats)
        {
            mp[i[0]].push_back(i[1]);
        }
        for (auto &&i : mp)
        {
            vector<int> chk(11, 0);
            for (auto &&j : i.second)
            {
                chk[j] = 1;
            }
            bool left = chk[2] || chk[3] || chk[4] || chk[5];
            bool right = chk[6] || chk[7] || chk[8] || chk[9];
            bool mid = chk[6] || chk[7] || chk[4] || chk[5];

            if (left || mid || right)
            {
                if (left && right && mid)
                {
                    maxseats -= 2;
                }
                else{
                    maxseats--;
                }
            }
        }
        return maxseats;
    }
};