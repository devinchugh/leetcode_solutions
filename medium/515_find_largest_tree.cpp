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
    vector<int> largestValues(TreeNode *root)
    {

        vector<int> ans;
        if (root == NULL)
        {
            return ans;
        }
        queue<TreeNode *> q;

        q.push(root);

        while (!q.empty())
        {
            int n = q.size();
            int maxi = INT_MIN;
            for (int _ = 0; _ < n; _++)
            {
                TreeNode *curr = q.front();
                if (curr == NULL)
                {
                    continue;
                }
                q.pop();
                maxi = max(maxi, curr->val);
                if (curr->left)
                {
                    q.push(curr->left);
                }
                if (curr->right)
                {
                    q.push(curr->right);
                }
            }
            ans.push_back(maxi);
        }
        return ans;
    }
};