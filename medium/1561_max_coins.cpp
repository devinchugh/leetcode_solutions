#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxCoins(vector<int> &piles)
    {
        //    2 2 4
        int ans = 0;
        sort(begin(piles), end(piles));
        int count = 0;

        for (int i = piles.size() - 1 - 1; i >= 0; i = i - 2)
        {
            ans += piles[i];
            count++;
            if (count == piles.size() / 3)
            {
                return ans;
            }
        }
        return ans;
    }
};