#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findLongestChain(vector<vector<int>> &pairs)
    {
        sort(pairs.begin(), pairs.end(), [](vector<int> a, vector<int> b)
             { return a[1] < b[1]; });

        int count = 1;
        int prev = pairs[0][1];
        for (int i = 1; i < pairs.size(); i++)
        {
            if (prev < pairs[i][0])
            {
                count++;
                prev = pairs[i][1];
            }
        }
        return count;
    }
};