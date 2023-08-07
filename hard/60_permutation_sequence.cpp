#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string getPermutation(int n, int k)
    {
        string a = "";
        for (int i = 1; i <= n; i++)
        {
            a += to_string(i);
        }

        vector<int> fact(n + 1);
        fact[0] = 1;
        for (int i = 1; i <= n; i++)
        {
            fact[i] = i * fact[i - 1];
        }
        k--;
        string ans = "";
        for (int i = n - 1; i >= 0; i--)
        {
            int index = k / fact[i];
            k = k % fact[i];
            ans += a[index];
            a.erase(ans.begin() + index);
        }

        return ans;
    }
};