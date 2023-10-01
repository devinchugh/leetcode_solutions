#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string slow_approach(string s, int k)
    {
        string ans = "";
        string x = "";
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] >= 'a' && s[i] <= 'z')
            {
                ans += s[i];
            }
            else
            {
                int num = s[i] - '0';
                num--;
                string temp = ans;
                while (num--)
                {
                    ans += temp;
                }
            }
            if (ans.size() >= k)
            {
                x += ans[k - 1];
                return x;
            }
        }
        return x;
    }
    string optimized_approach(string s, int k)
    {

        long long int idx = 0;
        int i = 0;
        while (i < s.size())
        {
            if (s[i] >= 'a' && s[i] <= 'z')
            {
                idx++;
            }
            else
            {
                int num = s[i] - '0';
                idx=num*idx;
            }
            i++;
        }
        for (i = s.size()-1 ; i >= 0; i--)
        {
            if (s[i] >= '0' && s[i] <= '9')
            {
                idx = idx / (s[i]-'0');
                k= k%idx;
            }
            else{
                if(k==0 || k==idx){
                    string ans="";
                    ans+=s[i];
                    return ans;
                }
                idx--;
            }
        }
        return "x";
    }
    string decodeAtIndex(string s, int k)
    {
        // we need to find the char at string k

        // Brute Force Approach

        // Fast & Optimized Approach
        return optimized_approach(s, k);
    }
};