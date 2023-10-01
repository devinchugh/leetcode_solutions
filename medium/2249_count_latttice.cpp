#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    set<pair<int, int>>st;
    int getpoints(vector<int> arr)
    {
        int x = arr[0];
        int y = arr[1];
        int r = arr[2];
        int ans = 0;
        for (int i = x - r; i <= x + r; i++)
        {
            for (int j = y - r; j <= y + r; j++)
            {
                double dis = pow(pow(i - x, 2) + pow(j - y, 2), 0.5);
                if (dis <= r)
                {
                    st.insert({i,j});
                    ans++;
                }
            }
        }
        return ans;
    }
    int countLatticePoints(vector<vector<int>> &circles)
    {
        int points = 0;

        for (int i = 0; i < circles.size(); i++)
        {
            points += getpoints(circles[i]);
        }
        return st.size();
    }
};