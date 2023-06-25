#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int hIndex(vector<int> &citations)
    {
        int n = citations.size();
        sort(begin(citations), end(citations));
        int h_index = 0;
        for (int i = 0; i < n; i++)
        {
            int temp_h = n - i;
            if (citations[i] >= temp_h)
            {
                h_index = max(h_index, temp_h);
            }
        }

        return h_index;
    }
};