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
    vector<int> distanceK(TreeNode *root, TreeNode *target, int k)
    {
        vector<int> ans;
        unordered_map<TreeNode *, TreeNode *> parent;
        unordered_map<TreeNode *, bool> visited;
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty())
        {
            int sz = q.size();
            for (int i = 0; i < sz; i++)
            {
                TreeNode *curr = q.front();
                visited[curr]=0;
                q.pop();
                if (curr->left)
                {
                    parent[curr->left] = curr;
                    q.push(curr->left);
                }
                if (curr->right)
                {
                    parent[curr->right] = curr;
                    q.push(curr->right);
                }
            }
        }
        q.push(target);
        while (!q.empty() && k > 0)
        {
            int sz = q.size();
            
            for (int i = 0; i < sz; i++)
            {
                TreeNode *curr = q.front();
                q.pop();
                visited[curr] = 1;
                if (curr->left && !visited[curr->left])
                {
                    q.push(curr->left);
                }
                if (curr->right && !visited[curr->right])
                {
                    q.push(curr->right);
                }
                if (parent[curr] && !visited[parent[curr]])
                {
                    q.push(parent[curr]);
                }
            }
            k--;
        }
        while (!q.empty())
        {
            ans.push_back(q.front()->val);
            q.pop();
        }

        return ans;
    }
};