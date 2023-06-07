#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> dailyTemperatures(vector<int> &temp)
    {
        vector<int> ans(temp.size(), 0);
        int n = temp.size();
        if (n <= 1)
            return ans;

        stack<pair<int, int>> st;
        st.push({0, temp[0]});
        for (int i = 1; i < n; i++)
        {
            while (!st.empty() && st.top().second < temp[i])
            {
                ans[st.top().first] = i - st.top().first;
                st.pop();
            }
            st.push({i, temp[i]});
        }
        return ans;
    }
};