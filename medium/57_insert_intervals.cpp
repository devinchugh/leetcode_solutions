#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
    int start = newInterval[0];
    int end = newInterval[1];
    int n = intervals.size();
    
    if (n == 0) {
        intervals.push_back(newInterval);
        return intervals;
    }
    
    if (end < intervals[0][0]) {
        intervals.insert(intervals.begin(), newInterval);
        return intervals;
    }
    
    if (start > intervals[n - 1][1]) {
        intervals.push_back(newInterval);
        return intervals;
    }
    
    int i = 0;
    
    // Skip intervals that are completely before the new interval
    while (i < n && intervals[i][1] < start) {
        i++;
    }
    
    // Merge intervals that overlap with the new interval
    while (i < n && intervals[i][0] <= end) {
        start = min(start, intervals[i][0]);
        end = max(end, intervals[i][1]);
        intervals.erase(intervals.begin() + i);
        n--;
    }
    
    intervals.insert(intervals.begin() + i, {start, end});
    
    return intervals;
}
};