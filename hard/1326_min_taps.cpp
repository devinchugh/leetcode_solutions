#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    static bool compare(vector<int> a, vector<int> b)
    {
        if (a[0] != b[0])
        {
            return a[0] < b[0];
        }
        return a[1] - a[0] > b[1] - b[0];
    }
    int minTaps(int n, vector<int> &ranges)
    {
        vector<vector<int>> intervals;

        for (int i = 0; i <= n; i++)
        {
            if (ranges[i] == 0)
            {
                continue;
            }
            int start = i - ranges[i];
            int end = i + ranges[i];

            start = max(0, start);
            end = min(n, end);
            intervals.push_back({start, end});
        }
        sort(intervals.begin(), intervals.end(), compare);
        if (intervals.empty())
        {
            return -1;
        }
        for (auto &&i : intervals)
        {
            cout << i[0] << ' ' << i[1] << endl;
        }

        int count = 1;
        int end = intervals[0][1];
        int start = intervals[0][0];
        int pre_end = -1;
        int i = 1;
        while (i < intervals.size() && end < n)
        {
            if (end > intervals[i][1])
            {
                i++;
                continue;
            }
            if (intervals[i][0] > end)
            {
                return -1;
            }
            if (intervals[i][0] > pre_end)
            {
                pre_end = end;
                count++;
            }
            end = intervals[i][1];
            i++;
        }
        if(end!=n){
            return -1;
        }
        return count;
    }
};