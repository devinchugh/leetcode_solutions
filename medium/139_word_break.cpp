#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    unordered_map<string, bool> memo; // Memoization table
    map<string, bool> mp;

    bool checkword(string &s, int currpos, string wrd)
    {
        if (currpos >= s.size())
        {
            if (wrd.size() == 0)
            {
                return true;
            }
            return false;
        }

        string memoKey = wrd + to_string(currpos); // Create a unique key for memoization
        if (memo.count(memoKey) > 0)               // Check if the result is already memoized
        {
            return memo[memoKey];
        }

        bool a = 0;

        if (mp[wrd + s[currpos]])
        {
            a = checkword(s, currpos + 1, "");
        }

        bool result = a || checkword(s, currpos + 1, wrd + s[currpos]);

        memo[memoKey] = result; // Store the result in the memoization table
        return result;
    }

    bool wordBreak(string s, vector<string> &wordDict)
    {
        for (auto &&i : wordDict)
        {
            mp[i] = 1;
        }

        memo.clear(); // Clear the memoization table before each function call
        return checkword(s, 0, "");
    }
};