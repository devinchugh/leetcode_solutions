#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    TreeNode *left;
    TreeNode *right;
    int val;
};

// Preoreder root left right
// Inorder  left root right
// Postorder left right root

class Solution
{
public:
    void flatten(TreeNode *root)
    {

        stack<TreeNode *> q;
        if (root == NULL)
        {
            return;
        }
         if (root->right)
        {
            q.push(root->right);
        }
        if (root->left)
        {
            q.push(root->left);
        }
       
        TreeNode *curr = root;
        while (!q.empty())
        {

            TreeNode *temp = q.top();
            q.pop();
            if (temp->right)
            {
                q.push(temp->right);
            }
            if (temp->left)
            {
                q.push(temp->left);
            }
            
            curr->right = temp;
            curr->left = NULL;
            curr = temp;
        }
    }
};