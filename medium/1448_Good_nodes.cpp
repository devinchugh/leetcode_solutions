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
    void countgood(TreeNode* root, int maxi, int &ans){
        if(root==NULL){
            return;
        }
        if(root->val>=maxi){
            maxi=root->val;
            ans++;
        }
        countgood(root->left, maxi, ans);
        countgood(root->right, maxi, ans);
        return;
    }
    int goodNodes(TreeNode* root) {
        if(root==NULL){
            return 0;
        }
        int ans=0;
        countgood(root, root->val, ans);
        return ans;
    }
};