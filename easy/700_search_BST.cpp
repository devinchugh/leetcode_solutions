#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
};


class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        if(root==NULL){
            return NULL;
        }
        if(root->val==val){
            return root;
        }
        if(root->val>val){
            return searchBST(root->left, val);
        }
        return searchBST(root->right,val);
    }
};