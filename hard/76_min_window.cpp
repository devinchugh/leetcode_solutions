#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string minWindow(string s, string t)
    {
        map<char, int> mp1;
        for (auto &&i : t)
        {
            mp1[i]++;
        }
        int low = 0;
        int right = s.size() - 1;
        int count = 0;
        string ans ;
        int sz=INT_MAX;
        for (right = 0; right < s.size(); right++)
        {
            if (mp1[s[right]] > 0)
            {
                count++;
            }
            mp1[s[right]]--;
            if (count == t.size())
            {
                while (low < right && mp1[s[low]] < 0)
                {
                    mp1[s[low]]++;
                    low++;
                }
                if (sz > right - low + 1)
                {
                    ans = s.substr(low, right - low + 1);
                    sz=right-low+1;
                    //cout<<ans<<endl;
                }
                mp1[s[low++]]++;
                count--;
            }
        }
        if(sz==INT_MAX){
            return "";
        }

        return ans;
    }
};
