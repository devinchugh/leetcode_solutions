#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long caneat(vector<int> &piles, int k)
    {
        long long ans = 0;
        for (auto &&i : piles)
        {
            if (i % k == 0)
            {
                ans = ans + (i / k);
            }
            else
            {
                ans += (i / k + 1);
            }
        }
        return ans;
    }
    int minEatingSpeed(vector<int> &piles, int h)
    {
        int n = piles.size();
        int a = 1;
        int b = 1000000000;
        while (a <= b)
        {
            int mid = a + (b - a) / 2;
            long long x = caneat(piles, mid);

            if (x > h)
            {
                a = mid + 1;
            }
            else
            {
                b = mid - 1;
            }
        }
        return a;
    }
};
