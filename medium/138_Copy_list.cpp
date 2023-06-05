#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int val;
    Node *next;
    Node *random;

    Node(int _val)
    {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution
{
public:
    Node *copyRandomList(Node *head)
    {
        if (head == NULL)
        {
            return NULL;
        }
        Node *newhead;
        unordered_map<Node *, Node *> mp;
        newhead = new Node(head->val);
        mp[head] = newhead;
        Node *tem1 = newhead;
        Node *tem2 = head->next;

        while (tem2 != NULL)
        {
            Node *x = new Node(tem2->val);
            mp[tem2] = x;
            tem1->next = x;
            tem1 = tem1->next;
            tem2 = tem2->next;
        }
        tem1->next = NULL;

        tem1 = newhead;
        tem2 = head;
        while (tem2 != NULL)
        {
            if (tem2->random == NULL)
            {
                tem1->random = NULL;
            }
            else
            {
                tem1->random = mp[tem2->random];
            }
            tem1 = tem1->next;
            tem2 = tem2->next;
        }
        return newhead;
    }
};