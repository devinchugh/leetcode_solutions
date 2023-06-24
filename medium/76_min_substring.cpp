#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool chk(vector<int> &arr)
    {
        for (auto &&i : arr)
        {
            if (i > 0)
            {
                return false;
            }
        }
        return true;
    }
    string minWindow(string s, string t)
    {
        int m = s.size();
        int n = t.size();
        if (m == 0 || n == 0 || n > m)
        {
            return "";
        }
        vector<int> arr(128, 0);
        int remain = n;
        for (int i = 0; i < n; i++)
        {
            arr[t[i]]++;
        }
        int left = 0, right = 0, pos=-1;
        arr[s[right]]--;
        int sz = INT_MAX;
        
        while (right<m)
        {
            if(!chk(arr)){
                right++;
                if(right<m)
                arr[s[right]]--;
            }
            else{
                if(sz>(right-left+1)){
                    sz=right-left+1;

                }
            }
        }
        
    }
};