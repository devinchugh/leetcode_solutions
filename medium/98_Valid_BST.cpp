#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    bool checkBST(TreeNode *root, long long maxi, long long mini)
    {
        if (root == NULL)
            return true;
        if (root->val >= maxi)
            return false;
        if (root->val <= mini)
            return false;
        return checkBST(root->left, root->val, mini) && checkBST(root->right, maxi, root->val);
    }
    bool isValidBST(TreeNode *root)
    {
        if (root == NULL)
            return true;
        return checkBST(root, INT64_MAX, INT64_MIN);
    }
};