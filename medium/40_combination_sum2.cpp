#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> ans;
    void findans(vector<int> &candi,const int target, vector<int> &curr, const int currpos)
    {
        if (target == 0)
        {
            ans.push_back(curr);
            return;
        }
        else
        {
            for (int i = currpos; i < candi.size(); i++)
            {
                if (candi[i] > target)
                {
                    return;
                }
                if (i > 0 && candi[i] == candi[i - 1] && i>currpos)
                {
                    continue;
                }
                curr.push_back(candi[i]);
                findans(candi, target - candi[i], curr, i + 1);
                curr.pop_back();
            }
        }
    }
    vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
    {
        vector<int> curr;
        sort(begin(candidates),end(candidates));
        findans(candidates, target, curr, 0);

        return ans;
    }
};