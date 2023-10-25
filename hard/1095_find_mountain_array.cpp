#include <bits/stdc++.h>
using namespace std;

class MountainArray
{
public:
    int get(int index);
    int length();
};

class Solution
{
public:
    int find_peak(MountainArray &mountainArr)
    {
        int n = mountainArr.length();
        int l = 0, r = n - 1;
        while (l < r)
        {
            int mid = l + (r - l) / 2;
            int mid_val = mountainArr.get(mid);
            int right_val = mountainArr.get(mid + 1);

            if (mid_val < right_val)
            {
                l = mid + 1;
            }
            else
            {
                r = mid;
            }
        }
        return l;
    }
    int search_left(int l, int r, MountainArray &mountainArr, int target)
    {
        while (l <= r)
        {
            int mid = l + (r - l) / 2;
            int num = mountainArr.get(mid);
            if (num == target)
            {
                return mid;
            }
            else if (num < target)
            {
                l = mid + 1;
            }
            else
            {
                r = mid - 1;
            }
        }
        return -1;
    }
    int search_right(int l, int r, MountainArray &mountainArr, int target)
    {
        while (l <= r)
        {
            int mid = l + (r - l) / 2;
            int num = mountainArr.get(mid);
            if (num == target)
            {
                return mid;
            }
            else if (num < target)
            {
                r = mid - 1;
            }
            else
            {
                l = mid + 1;
            }
        }
        return -1;
    }
    int findInMountainArray(int target, MountainArray &mountainArr)
    {
        int x = find_peak(mountainArr);
        int a = search_left(0, x, mountainArr, target);
        if (a != -1)
        {
            return a;
        }
        return search_right(x + 1, mountainArr.length() - 1, mountainArr, target);
    }
};