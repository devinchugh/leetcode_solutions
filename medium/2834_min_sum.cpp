#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minimumPossibleSum(long long n, int target)
    {
        int mod = 1e9 + 7;
        long long int sum = ((n % mod) * (n % mod + 1) / 2) % mod;
        sum %= mod;
        int count = 0;
        if (n > target / 2)
        {
            int count = 0;
            long long sum1 = ((target % mod) * (target % mod + 1) / 2) % mod;
            long long sum2 = ((target / 2 % mod) * (target / 2 % mod + 1) / 2) % mod;
            int count = target - target / 2 - 1;
            sum = ((n + count % mod) * (n + count % mod + 1) / 2) % mod;
            sum1 -= target;
            sum = sum - (sum1 - sum2);
        }
        return sum;
    }
};