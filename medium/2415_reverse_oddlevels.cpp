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
    void reverselevel(vector<TreeNode*> arr){
        int n=arr.size();
        for (int i = 0; i < n/2; i++)
        {
            swap(arr[i]->val,arr[n-i-1]->val);
        }
        
    }
    TreeNode *reverseOddLevels(TreeNode *root)
    {
        if (root == NULL)
        {
            return root;
        }
        queue<vector<TreeNode *>> pq;
        pq.push({root});
        bool toreverse = 0;

        while (!pq.empty())
        {
            vector<TreeNode *> temp = pq.front();
            vector<TreeNode *> arr;
            for (auto &&i : temp)
            {
                if (i->left)
                    arr.push_back(i->left);
                if (i->right)
                    arr.push_back(i->right);
            }
            if (toreverse)
            {
                reverselevel(temp);
            }
            pq.pop();
            toreverse=!toreverse;
            if (arr.size() > 0)
            {
                pq.push(arr);
            }
        }
        return root;
    }
};