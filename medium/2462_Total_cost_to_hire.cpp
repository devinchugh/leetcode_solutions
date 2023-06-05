#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long totalCost(vector<int> &costs, int k, int candi)
    {
        long long ans = 0;
        int n = costs.size();
        priority_queue<int, vector<int>, greater<int>> lowidx, highidx;

        for (int i = 0; i < candi; i++)
        {
            lowidx.push(costs[i]);
        }
        int low = candi;
        for (int i = max(low, n - candi); i < n; i++)
        {
            highidx.push(costs[i]);
        }
        int high = max(low, n - candi) - 1;

        for (int i = 0; i < k; i++)
        {
            if (!lowidx.empty() && !highidx.empty() && lowidx.top() <= highidx.top())
            {
                ans += lowidx.top();
                lowidx.pop();
                if (low < high)
                {
                    lowidx.push(costs[low]);
                    low++;
                }
            }
            else if (!lowidx.empty() && !highidx.empty())
            {
                ans += highidx.top();
                highidx.pop();
                if (low < high)
                {
                    highidx.push(costs[high]);
                    high--;
                }
            }
            else if (!lowidx.empty())
            {
                ans += lowidx.top();
                lowidx.pop();
                if (low < high)
                {
                    lowidx.push(costs[low]);
                    low++;
                }
            }
            else
            {
                ans += highidx.top();
                highidx.pop();
                if (low < high)
                {
                    highidx.push(costs[high]);
                    high--;
                }
            }
        }
        return ans;
    }
};