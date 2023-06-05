#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int val;
    Node *left;
    Node *right;
    Node *next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node *_left, Node *_right, Node *_next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

class Solution
{
public:
    Node *connect(Node *root)
    {
        if (root == NULL)
        {
            return NULL;
        }
        queue<vector<Node *>> mp;
        mp.push({root});
        while (!mp.empty())
        {
            vector<Node *> temp = mp.front();
            vector<Node *> next;
            mp.pop();
            for (int i = 0; i < temp.size(); i++)
            {
                if (i + 1 < temp.size())
                    temp[i]->next = temp[i + 1];
                else
                    temp[i]->next = NULL;
                if (temp[i]->left)
                    next.push_back(temp[i]->left);
                if (temp[i]->right)
                    next.push_back(temp[i]->right);
            }
            if(next.size()>0){
                mp.push(next);
            }
        }
        return root;
    }
};