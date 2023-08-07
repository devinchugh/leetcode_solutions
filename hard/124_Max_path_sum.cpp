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
    int maxi = -1001;

    int maxpathSum(TreeNode *root)
    {
        if (root == NULL)
        {
            return 0;
        }

        int a = max(0, maxpathSum(root->left));

        int b = max(0, maxpathSum(root->right));

        maxi = max(maxi, a + b + root->val);

        return max({a + root->val, b + root->val});
    }
    int maxPathSum(TreeNode *root)
    {
        maxpathSum(root);
        return maxi;
    }
};