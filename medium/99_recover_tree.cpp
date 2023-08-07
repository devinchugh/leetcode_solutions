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
    TreeNode *first;
    TreeNode *second;
    TreeNode *prev;
    void dfs(TreeNode *root)
    {
        if (root == NULL)
        {
            return;
        }

        dfs(root->left);

        if(first==NULL && root->val<prev->val){
            first=prev;
        }
        if(first!=NULL && root->val<prev->val){
            second=root;
        }
        prev=root;

        dfs(root->right);
    }
    void recoverTree(TreeNode *root)
    {
        if (root == NULL)
        {
            return;
        }
        first = NULL;
        second = NULL;

        prev = new TreeNode(INT_MIN);
        dfs(root);
        swap(first->val, second->val);
    }
};