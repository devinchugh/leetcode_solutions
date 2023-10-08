#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minimumSum(int n, int k)
    {

        int sum = n * (n + 1) / 2;

        if (n < k / 2)
        {
            return sum;
        }

        int s1 = k * (k + 1) / 2;
        int s2 = (k / 2) * (k / 2 + 1) / 2;
        int count=k-k/2-1;
        sum = (n+count) * ((n+count) + 1) / 2;
        sum = sum - (s1 - s2) + k;
        return sum;

    }
};