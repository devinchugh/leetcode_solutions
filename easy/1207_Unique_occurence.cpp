#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool uniqueOccurrences(vector<int> &arr)
    {
        vector<int> chk(2001, 0);
        for (auto &&i : arr)
        {
            chk[i]++;
        }
        sort(chk.begin(),chk.end());
        for (int i = 1; i < 2001; i++)
        {
            if (chk[i]!=0 && chk[i] == chk[i - 1])
                return false;
        }
        return true;
    }
};