#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    double champagneTower(int poured, int query_row, int query_glass)
    {
        vector<double> prev(101);
        vector<double> curr(101);
        prev[0] = poured;
        if(query_row==0){
            return min(1.0,prev[0]);
        }

        int count = 2;
        for (int i = 1; i < 100; i++)
        {
            for (int j = 0; j < count; j++)
            {
                if (j == 0)
                {
                    curr[j] = max(0.0, (prev[j] - 1) / 2.0);
                }
                else if (j == count - 1)
                {
                    curr[j] = max(0.0, (prev[j - 1] - 1) / 2.0);
                }
                else
                {
                    curr[j] = max(0.0, (prev[j - 1] - 1) / 2.0) + max(0.0, (prev[j] - 1) / 2.0);
                }
                // cout<<dp[i][j]<<' ';
            }

            if (i == query_row)
            {
                return min(1.0, curr[query_glass]);
            }
            prev = curr;
            // cout<<endl;
            count++;
        }
        return 0.0;
    }
};