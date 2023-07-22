#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<string> letterCombinations(string digits)
    {
        vector<string> ans;
        int n = digits.size();
        if (n == 0)
        {
            return ans;
        }
        unordered_map<int, string> mp;

        mp['2'] = "abc";
        mp['3'] = "def";
        mp['4'] = "ghi";
        mp['5'] = "jkl";
        mp['6'] = "mno";
        mp['7'] = "pqrs";
        mp['8'] = "tuv";
        mp['9'] = "wxyz";

        for (auto &&i : digits)
        {
            vector<string> temp;
            if (ans.empty())
            {
                for (auto &&chr : mp[i])
                {
                    ans.push_back(string(1, chr));
                }
            }
            else
            {
                int sz = ans.size();
                for (int j = 0; j < sz; j++)
                {
                    string wrd = ans[j];
                    for (auto &&chr : mp[i])
                    {
                        temp.push_back(wrd + chr);
                    }
                }
                ans=temp;
                temp.clear();
            }
        }

        return ans;
    }
};