#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxSatisfaction(vector<int> &satis)
    {
        sort(satis.begin(), satis.end());
        int n = satis.size();
        int idx = -1;
        for (int i = 0; i < satis.size(); i++)
        {
            if (satis[i] >= 0)
            {
                idx = i;
                break;
            }
        }

        if (idx == -1 || idx == n - 1)
        {
            return 0;
        }
        int ans = 0;
        int i = idx;

        while (true)
        {
            int count = 1;
            int nextmaxi = 0;
            if (i >= 0)
            {
                for (int j = i; j < n; j++)
                {
                    nextmaxi += count * satis[j];
                    count++;
                }
            }
            if (nextmaxi > ans)
            {
                ans = nextmaxi;
            }
            else
            {
                break;
            }
            i--;
        }
        return ans;
    }
};