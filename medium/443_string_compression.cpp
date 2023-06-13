#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int compress(vector<char> &chars)
    {
        int count = 1;
        char prev = chars[0];
        string ans = "";
        ans += chars[0];
        for (int i = 1; i < chars.size(); i++)
        {
            if (prev == chars[i])
            {
                count++;
                continue;
            }
            else
            {
                if (count != 1)
                {
                    ans += to_string(count);
                }
                ans += chars[i];
                prev = chars[i];
                count = 1;
            }
        }
        if (count != 1)
        {
            ans += to_string(count);
        }
        for (int i = 0; i < ans.size(); i++)
        {
            chars[i]=ans[i];
        }
        
        cout << ans << endl;
        return ans.size();
    }
};