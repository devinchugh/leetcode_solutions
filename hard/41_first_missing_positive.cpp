#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int firstMissingPositive(vector<int> &nums)
    {
        map<int, int> mp;
        for (auto &&i : nums)
        {
            mp[i] = 1;
        }
        int prev = 1;
        for (auto &&i : mp)
        {
            if (i.first > 0 && i.first != prev)
            {
                return prev;
            }
            else if (i.first == prev)
            {
                prev++;
            }
        }

        return prev;
    }
};