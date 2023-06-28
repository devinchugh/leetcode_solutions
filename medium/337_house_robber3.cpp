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
    map<TreeNode *, int> mp;
    int getans(TreeNode *root)
    {
        if (root == NULL)
        {
            return 0;
        }
        int val = 0;
        if(mp[root]){
            return mp[root];
        }
        if (root->left)
        {
            val += getans(root->left->left);
            val += getans(root->left->right);
        }
        if (root->right)
        {
            val += getans(root->right->left);
            val += getans(root->right->right);
        }
        mp[root] = max(root->val + val, getans(root->left) + getans(root->right));
        return mp[root];
    }
    int rob(TreeNode *root)
    {
        getans(root);
    }
};