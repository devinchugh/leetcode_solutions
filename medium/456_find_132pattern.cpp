#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool find132pattern(vector<int> &nums)
    {

        int maxi = INT_MIN;
        stack<int> st;
        for (int i = nums.size() - 1; i >= 0; i--)
        {
            if (nums[i] < maxi)
            {
                return true;
            }
            while (!st.empty() && nums[i] > st.top())
            {
                maxi = st.top();
                st.pop();
            }
            st.push(nums[i]);
        }

        return false;
    }
};