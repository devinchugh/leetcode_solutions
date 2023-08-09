#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string largestPalindromic(string num)
    {

        vector<int> arr(10, 0);

        for (auto &&chr : num)
        {
            arr[chr - '0']++;
        }

        string ans = "";

        for (int i = 10 - 1; i >= 0; i--)
        {
            int count = arr[i] / 2;
            arr[i]-=2*count;
            for (int j = 0; j < count; j++)
            {
                ans+=to_string(i);
            }
        }
        if(ans[0]=='0'){
            ans="";
        }
        string temp=ans;
        for (int i = 10 - 1; i >= 0; i--)
        {
            if(arr[i]){
                ans+=to_string(i);
                break;
            }
        }
        
        reverse(begin(temp), end(temp));
        if(ans==""){
            return "0";
        }
        return ans+temp;
    }
};