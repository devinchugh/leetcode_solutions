#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> nextGreaterElements(vector<int> &nums)
    {
        stack<int> right;
        int n = nums.size();
        vector<int> greater_ele(n);

        for (int i = n - 1 - 1; i >= 0; i--)
        {
            right.push(nums[i]);
        }

        for (int i = nums.size() - 1; i >= 0; i--)
        {
            while (!right.empty() && right.top() <= nums[i])
            {
                right.pop();
            }
            if (!right.empty())
            {
                greater_ele[i] = right.top();
            }
            else
            {
                greater_ele[i] = -1;
            }
            right.push(nums[i]);
        }
        return greater_ele;
    }
};