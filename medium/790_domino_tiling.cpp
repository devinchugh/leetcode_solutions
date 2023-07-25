#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int numTilings(int n)
    {

        if (n <= 1)
        {
            return 1;
        }
        if (n == 2)
        {
            return 2;
        }
        int prev2 = 1;
        int prev1 = 1;
        int curr = 2;
        int mod = 1e9 + 7;

        for (int i = 3; i <= n; i++)
        {
            int temp = curr;
            curr = (2 * curr % mod) + prev2 % mod;
            curr = curr % mod;
            prev2 = prev1;
            prev1 = temp;
        }

        return curr;
    }
};