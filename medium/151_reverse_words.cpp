#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string reverseWords(string s)
    {
        if (s.size() <= 1)
        {
            return s;
        }
        int n = s.size();
        vector<string> arr;
        string temp = "";
        for (int i = 0; i < n; i++)
        {
            if (s[i] == ' ')
            {
                if (temp.size() > 0)
                    arr.push_back(temp);
                temp = "";
            }
            else
            {
                temp += s[i];
            }
        }
        if (temp.size() > 0)
            arr.push_back(temp);
        string ans = "";
        for (int i = arr.size() - 1; i > 0; i--)
        {
            ans = ans + arr[i] + " ";
        }
        ans += arr[0];
        return ans;
    }
};