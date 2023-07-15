#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findlength(string &s, int l, int r, vector<vector<int>> &dp)
    {
        if(l==r){
            return 1;
        }
        if(l>r){
            return 0;
        }
        if(dp[l][r]!=-1){
            return dp[l][r];
        }

        if(s[l]==s[r]){
            dp[l][r]=2+findlength(s, l+1, r-1, dp);
        }
        else{
            dp[l][r]=max(findlength(s, l+1, r, dp), findlength(s, l, r-1, dp));
        }
        return dp[l][r];
    }

    int longestPalindromeSubseq(string s)
    {
        vector<vector<int>> dp(1001, vector<int>(1001, -1));
        return findlength(s, 0, s.size()-1, dp);
    }
};