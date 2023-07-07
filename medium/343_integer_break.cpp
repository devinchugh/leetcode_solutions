#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> arr;
    int getans(int n)
    {
        if (n == 1)
        {
            return 1;
        }
        int ans = 0;
        if (arr[n] != -1)
        {
            return arr[n];
        }
        for (int i = 1; i < n; i++)
        {

            ans = max(ans, i * (n - i));

            ans = max(ans, i * getans(n - i));
        }

        return arr[n] = ans;
    }
    int integerBreak(int n)
    {
        for (int i = 0; i <= n; i++)
        {
            arr.push_back(-1);
        }

        return getans(n);
    }
};