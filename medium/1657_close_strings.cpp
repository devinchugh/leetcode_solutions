#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool closeStrings(string word1, string word2)
    {
        int n1 = word1.size();
        int n2 = word2.size();
        if (n1 != n2)
        {
            return false;
        }

        map<char, int> mp1, mp2;
        for (auto &&i : word1)
        {
            mp1[i]++;
        }
        for (auto &&i : word2)
        {
            mp2[i]++;
            if (mp1[i] == 0)
            {
                return false;
            }
        }
        if (mp1.size() != mp2.size())
        {
            return false;
        }
        vector<int> arr1, arr2;
        for (auto &&i : mp1)
        {
            arr1.push_back(i.second);
        }
        for (auto &&i : mp2)
        {
            arr2.push_back(i.second);
        }
        sort(begin(arr1), end(arr1));
        sort(begin(arr2), end(arr2));

        return arr1 == arr2;
    }
};