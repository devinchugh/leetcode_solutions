#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> circularGameLosers(int n, int k)
    {
        vector<int> arr(n, 0);
        int x = 0;
        int a = 1;
        while (true)
        {
            arr[x]++;
            if (arr[x] == 2)
            {
                break;
            }
            x = (x + a * k) % n;
            a++;
        }
        vector<int> ans;
        for (int i = 0; i < n; i++)
        {
            if (arr[i] == 0)
            {
                ans.push_back(i + 1);
            }
        }
        return ans;
    }
};