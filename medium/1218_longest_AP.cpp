#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int longestSubsequence(vector<int> &arr, int diff)
    {
        map<int, int> mp;
        int ans = 0;
        for (int i = 0; i < arr.size(); i++)
        {
            if (mp[arr[i] - diff])
            {
                mp[arr[i]] = mp[arr[i] - diff] + 1;
            }
            else
            {
                mp[arr[i]] = 1;
            }
            ans = max(ans, mp[arr[i]]);
        }
        return ans;
    }
};