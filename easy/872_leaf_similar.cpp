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
    void getleaf(vector<int> &arr, TreeNode *root)
    {
        if (root == NULL)
        {
            return;
        }
        if (root->left == NULL && root->right == NULL)
        {
            arr.push_back(root->val);
        }
        getleaf(arr, root->left);
        getleaf(arr, root->right);
    }
    bool leafSimilar(TreeNode *root1, TreeNode *root2)
    {
        vector<int> arr1, arr2;

        getleaf(arr1, root1);
        getleaf(arr2, root2);
        return arr1==arr2;
    }
};
