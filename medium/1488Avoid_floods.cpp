#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> avoidFlood(vector<int> &rains)
    {
        int n = rains.size();
        vector<int> ans(n, -1);
        unordered_map<int, int> rained_on; // lake Number -> Last Rained
        priority_queue<int, vector<int>, greater<int>> dry_day;

        for (int i = 0; i < n; i++)
        {
            if (rains[i] == 0)
            {
                dry_day.push(i);
                continue;
            }

            if (!rained_on[rains[i]])
            {
                rained_on[rains[i]] = i + 1;
            }
            else
            {
                int last_rained = rained_on[rains[i]] - 1;
                queue<int> temp;
                bool found = 0;
                while (!dry_day.empty())
                {
                    int x = dry_day.top();
                    dry_day.pop();

                    if (x > last_rained)
                    {
                        ans[x] = rains[i];
                        rained_on[rains[i]] = i + 1;
                        found = 1;
                        break;
                    }
                    else
                    {
                        temp.push(x);
                    }
                }
                while (!temp.empty())
                {
                    dry_day.push(temp.front());
                    temp.pop();
                }

                if (!found)
                {
                    return {};
                }
            }
        }
        while (!dry_day.empty())
        {
            int x = dry_day.top();
            ans[x] = 100;
            dry_day.pop();
        }

        return ans;
    }
};