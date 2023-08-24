#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string reorganizeString(string s)
    {

        map<char, int> mp;

        for (auto &&i : s)
        {
            mp[i]++;
        }
        string ans = "";

        while (ans.size() < s.size())
        {
            int freq = 0;
            char x='#', y='#';
            int prevfreq = 0;
            //cout<<ans<<endl;
            for (auto &&val : mp)
            {
                if (val.second > freq)
                {
                    if(x!='#'){
                        y=x;
                        prevfreq=freq;
                    }
                    x = val.first;
                    freq = val.second;
                }
                else
                {
                    if (val.second > prevfreq)
                    {
                        y = val.first;
                        cout<<y<<endl;
                        prevfreq = val.second;
                    }
                }
            }
            ans += x;
            mp[x]--;
            if (y!='#')
            {
                ans += y;
                mp[y]--;
            }
            else if(ans.size()!=s.size()){
                return "";
            }
        }
        return ans;
    }
};