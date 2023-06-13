#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
};

class Solution
{
public:
    int maxLevelSum(TreeNode *root)
    {
        queue<vector<TreeNode *>> pq;
        if (root->left == NULL && root->right == NULL)
        {
            return 1;
        }
        pq.push({root});
        int level = 0;
        int maxi = INT_MIN;
        int mxlevel = 0;
        while (!pq.empty())
        {
            vector<TreeNode *> temp = pq.front();
            pq.pop();
            vector<TreeNode *> nextlevel;
            level++;
            int x = 0;
            for (auto &&i : temp)
            {
                x += i->val;
                if (i->left)
                {
                    nextlevel.push_back(i->left);
                }
                if (i->right)
                {
                    nextlevel.push_back(i->right);
                }
            }
            if (maxi < x)
            {
                maxi = x;
                mxlevel = level;
            }
            if (nextlevel.size() != 0)
            {
                pq.push(nextlevel);
            }
        }
        return mxlevel;
    }
};