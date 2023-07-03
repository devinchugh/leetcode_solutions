#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void generateSubsets(vector<vector<int>> &subsets, vector<int> &currentSubset, int start, int end)
    {
        subsets.push_back(currentSubset);

        for (int i = start; i <= end; i++)
        {
            currentSubset.push_back(i);
            generateSubsets(subsets, currentSubset, i + 1, end);
            currentSubset.pop_back();
        }
    }

    vector<vector<int>> combinationSum3(int k, int n)
    {
        vector<vector<int>> subsets;
        vector<int> curr;
        generateSubsets(subsets, curr, 1, 9);
        vector<vector<int>> ans;
        for (auto &&i : subsets)
        {
            if (i.size() == k)
            {
                int sum = 0;
                for (auto &&j : i)
                {
                    sum += j;
                }
                if (sum == n)
                {
                    ans.push_back(i);
                }
            }
        }
        return ans;
    }
};

