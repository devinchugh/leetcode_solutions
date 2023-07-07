#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2)
    {
        stack<int> right;
        vector<int> greater_ele(nums2.size());

        for (int i = nums2.size() - 1; i >= 0; i--)
        {
            while (!right.empty() && right.top() < nums2[i])
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
            right.push(nums2[i]);
        }
        for (int i = 0; i < nums1.size(); i++)
        {
            for (int j = 0; j < nums2.size(); j++)
            {
                if (nums1[i] == nums2[j])
                {
                    nums1[i] = greater_ele[j];
                    break;
                }
            }
        }
        return nums1;
    }
};