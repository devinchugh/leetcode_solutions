#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> fullBloomFlowers(vector<vector<int>> &flowers, vector<int> &people)
    {
        sort(begin(flowers), end(flowers));
        int n = flowers.size();
        vector<int> beg, ed;

        for (int i = 0; i < n; i++)
        {
            beg.push_back(flowers[i][0]);
            ed.push_back(flowers[i][1]);
        }
        sort(ed.begin(), ed.end());
        vector<int> ans;

        for (int i = 0; i < people.size(); i++)
        {
            int a = lower_bound(begin(beg), end(beg), people[i]+1) - begin(beg);
            int b = lower_bound(begin(ed), end(ed), people[i]) - begin(ed);
            
            ans.push_back(a-b);
        }
        return ans;
    }
};