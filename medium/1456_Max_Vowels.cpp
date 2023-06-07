#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool have_vowel(char c)
    {
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
        {
            return true;
        }
        return false;
    }
    int maxVowels(string s, int k)
    {
        int ans = 0;
        for (int i = 0; i < k; i++)
        {
            if (have_vowel(s[i]))
            {
                ans++;
            }
        }
        int maxi=ans;
        for (int i = k; i < s.size(); i++)
        {
            if (have_vowel(s[i - k]))
            {
                ans--;
            }
            if (have_vowel(s[i]))
            {
                ans++;
            }
            maxi=max(maxi,ans);
        }
        return maxi;
    }
};