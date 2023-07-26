#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int peakIndexInMountainArray(vector<int> &arr)
    {
        int l = 0;
        int r = arr.size() - 1;
        int n = arr.size();
        int mid;

        while (l < r)
        {
            mid = l + (r - l) / 2;

            if (arr[mid] < arr[mid + 1])
            {
                l = mid + 1;
            }
            else
            {
                r=mid;
            }
        }
        return l;
    }
};