#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> canSeePersonsCount(vector<int> &heights)
    {
        int n = heights.size();
        vector<int> ans(n, 0);

         stack<int> st;  // Stack to store indices of buildings
        
        for (int i = n - 1; i >= 0; i--)
        {
            while (!st.empty() && heights[i]>st.top())
            {
                st.pop();
                ans[i]++;
            }
            if(!st.empty()){
                ans[i]++;
            }
            st.push(heights[i]);
        }
        
        return ans;
    }
};