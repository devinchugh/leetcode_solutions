#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left, *right;
};

class Solution
{
public:
    int maxi;
    int findheight(TreeNode *root)
    {
        if (root == NULL)
        {
            return 0;
        }
        int right = 0, left = 0;
        left = findheight(root->left);
        right = findheight(root->right);
        maxi = max(maxi, left + right);
        return 1 + max(left, right);
    }
    int diameterOfBinaryTree(TreeNode *root)
    {
        maxi = 0;
        findheight(root);
        return maxi;
    }
};