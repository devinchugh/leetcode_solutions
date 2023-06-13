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
    int maxlength = 0;
    void getans(TreeNode *root, bool goleft, int curr)
    {
        if (root == NULL)
        {
            return;
        }
        if (goleft)
        {
            getans(root->left, 0, curr + 1);
            getans(root->right, 1, 1);
        }
        else
        {
            getans(root->right, 1, curr + 1);
            getans(root->left, 0, 1);
        }
        maxlength = max(curr, maxlength);
    }
    int longestZigZag(TreeNode *root)
    {
        if (root == NULL)
        {
            return 0;
        }

        getans(root, 0, 0);
        getans(root, 1, 0);
        return maxlength;
    }
};