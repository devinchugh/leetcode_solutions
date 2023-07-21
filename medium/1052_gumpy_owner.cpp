#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxSatisfied(vector<int> &customers, vector<int> &grumpy, int minutes)
    {
        int n = customers.size();
        int sum = 0;
        int maxsatis = 0;
        int l = 0;
        int r = 0;
        while (r-l < minutes)
        {
            if (!grumpy[r])
            {
                maxsatis += customers[r];
            }
            else
            {
                sum += customers[r];
            }
            r++;
        }
        int maxsum = sum;
        while (r < n)
        {
            if (grumpy[l])
            {
                sum -= customers[l];
            }

            if (!grumpy[r])
            {
                maxsatis += customers[r];
            }
            else
            {
                sum += customers[r];
            }

            maxsum = max(sum, maxsum);
            l++;
            r++;
        }
        return maxsum + maxsatis;
    }
};