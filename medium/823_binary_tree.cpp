#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    unordered_map<int, int> mp;
    unordered_map<int, int> dp;
    int mod = 1e9 + 7;
    int getans(int num, vector<int> &arr)
    {
        if(dp[num]){
            return dp[num];
        }
        long long res = 1;

        for (int i = 0; i < arr.size(); i++)
        {
            if (num % arr[i] == 0 && mp[num / arr[i]])
            {
                
                res = res + ((long long)getans(arr[i], arr)%mod * getans(num / arr[i], arr)%mod)%mod;
                res%=mod;
              
            }
        }
        return dp[num]=res;
    }
    int numFactoredBinaryTrees(vector<int> &arr)
    {
        for (auto &&i : arr)
        {
            mp[i] = 1;
        }
        sort(arr.begin(), arr.end());
        int ans=0;
        for (int i = 0; i < arr.size(); i++)
        {
            ans+=getans(arr[i], arr);
            ans%=mod;
        }
        return ans;
        
    }
};