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
    TreeNode *buildtree(vector<int> &postorder, vector<int> &inorder, int inst, int inend, int &curr, int n)
    {
        if (curr < 0 || inst > inend)
        {
            return NULL;
        }
        TreeNode *nd = new TreeNode(postorder[curr]);
        
        int idx = -1;
        for (int i = inst; i <= inend; i++)
        {
            if (inorder[i] == postorder[curr])
            {
                idx = i;
                break;
            }
        }
        curr--;

        nd->right = buildtree(postorder, inorder, idx + 1, inend, curr, n);
        nd->left = buildtree(postorder, inorder, inst, idx - 1, curr, n);
        return nd;
    }
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
    {
        int i = inorder.size()-1;
        return buildtree(postorder, inorder, 0, inorder.size() - 1, i, inorder.size());
    }
};