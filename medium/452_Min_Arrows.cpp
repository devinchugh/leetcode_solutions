#include <bits/stdc++.h>
using namespace std;

bool cmp(vector<int> &a, vector<int> &b) { return a[1] < b[1]; }
class Solution
{
public:
    int findMinArrowShots(vector<vector<int>> &points)
    {
        sort(begin(points), end(points), cmp);
        int arrow = 1;
        int curr = points[0][1];
        for (int i = 1; i < points.size(); i++)
        {
            if (points[i][0] > curr)
            {
                arrow++;
                curr = points[i][1];
            }
        }
        return arrow;
    }
};