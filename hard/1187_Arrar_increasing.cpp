#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int getans(map<pair<int, int>, int> &dp, vector<int> &arr1, vector<int> &arr2, int prev, int currpo)
    {
        if (currpo == arr2.size())
        {
            return 0;
        }
        if (dp.find({currpo, prev}) != dp.end())
        {
            return dp[{currpo, prev}];
        }
        int idx = upper_bound(arr2.begin(), arr2.end(), prev) - arr2.begin();
        int ans = INT_MAX / 2;
        if (prev < arr1[currpo])
        {
            ans = min(ans, getans(dp, arr1, arr2, arr1[currpo], currpo + 1));
        }
        if (idx < arr2.size())
        {
            ans = min(ans, 1 + getans(dp, arr1, arr2, arr2[idx], currpo + 1));
        }
        dp[{currpo, prev}] = ans;
        return ans;
    }

    int makeArrayIncreasing(vector<int> &arr1, vector<int> &arr2)
    {
        sort(arr2.begin(), arr2.end());
        map<pair<int, int>, int> dp;
        int ans = getans(dp, arr1, arr2, INT_MIN, 0);
        if (ans > INT_MAX / 2)
            return -1;
        return ans;
    }
};