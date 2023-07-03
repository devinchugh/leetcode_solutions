#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int numDecodings(string s)
    {
        vector<int> dp(s.size() + 1, 0);
        dp[0] = 1;
        dp[1] = 1;
        if(s[0]=='0'){
            return 0;
        }
        for (int i = 2; i <= s.size(); i++)
        {
            string mid;
            mid += s[i - 2];
            mid += s[i - 1];
            int tmp = stoi(mid);
            if(tmp==0){
                return 0;
            }
            if (s[i-1] == '0')
            {
                if (tmp > 26)
                {
                    return 0;
                }
                dp[i] = dp[i - 2];
            }
            else
            {
                if (s[i-2]!='0' && tmp <= 26)
                {
                    dp[i] = dp[i - 1] + dp[i - 2];
                }
                else
                {
                    dp[i] = dp[i - 1];
                }
            }
        }
        return dp[s.size()];
    }
};