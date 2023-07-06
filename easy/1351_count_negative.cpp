#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int countNegativeElements(const std::vector<int> &arr)
    {
        int left = 0;
        int right = arr.size() - 1;
        int count = 0;

        while (left <= right)
        {
            int mid = left + (right - left) / 2;

            if (arr[mid] < 0)
            {
                count += (right - mid + 1);
                right = mid - 1;
            }
            else
            {
                left = mid + 1;
            }
        }

        return count;
    }
    int countNegatives(vector<vector<int>> &grid)
    {
        int count = 0;
        int m = grid.size(), n = grid[0].size();
        for (int i = 0; i < m; i++)
        {
            count += countNegativeElements(grid[i]);
        }
        return count;
    }
};