#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution
{
public:
    vector<TreeNode *> getBSTs(int start, int end)
    {
        vector<TreeNode *> ans;
        if (start > end)
        {
            ans.push_back(NULL);
            return ans;
        }

        for (int i = start; i <= end; i++)
        {
            vector<TreeNode *> left = getBSTs(start, i - 1);
            vector<TreeNode *> right = getBSTs(i + 1, end);
            for (int j = 0; j < left.size(); j++)
            {
                for (int k = 0; k < right.size(); k++)
                {
                    TreeNode *curr = new TreeNode(i);
                    curr->left = left[j];
                    curr->right = right[k];
                    ans.push_back(curr);
                }
            }
        }
        return ans;
    }
    vector<TreeNode *> generateTrees(int n)
    {
        return getBSTs(1, n);
    }
};