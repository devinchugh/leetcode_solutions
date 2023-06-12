#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isVowel(char c)
    {
        if (c == 'a' || c == 'o' || c == 'i' || c == 'e' || c == 'u')
        {
            return true;
        }
        if (c == 'A' || c == 'O' || c == 'I' || c == 'E' || c == 'U')
        {
            return true;
        }
        return false;
    }
    string reverseVowels(string s)
    {
        stack<char> st;
        int n = s.size();
        for (int i = 0; i < n; i++)
        {
            if (isVowel(s[i]))
            {
                st.push(s[i]);
            }
        }
        for (int i = 0; i < n; i++)
        {
            if (isVowel(s[i]) && !st.empty())
            {
                s[i] = st.top();
                st.pop();
            }
        }
        return s;
    }
};