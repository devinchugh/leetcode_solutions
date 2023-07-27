#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    TreeNode *left;
    TreeNode *right;
    int val;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// pre-> root left right
// inorder -> left root right
// post -> left right root

class Solution
{
public:
    TreeNode *buildtree(vector<int> &preorder, vector<int> &inorder, int inst, int inend, int &curr, int n)
    {
        if (curr >= n || inst > inend)
        {
            return NULL;
        }
        TreeNode *nd = new TreeNode(preorder[curr]);
        
        int idx = -1;
        for (int i = inst; i <= inend; i++)
        {
            if (inorder[i] == preorder[curr])
            {
                idx = i;
                break;
            }
        }
        curr++;

        nd->left = buildtree(preorder, inorder, inst, idx - 1, curr, n);
        nd->right = buildtree(preorder, inorder, idx + 1, inend, curr, n);
        return nd;
    }
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {
        int i = 0;
        return buildtree(preorder, inorder, 0, inorder.size() - 1, i, inorder.size());
    }
};