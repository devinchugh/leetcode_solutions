#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
};

class Solution
{
public:
    ListNode *deleteDuplicates(ListNode *head)
    {
        ListNode *temp = head;
        while (temp != NULL && temp->next != NULL)
        {
            if (temp->val == temp->next->val)
            {
                ListNode *todelete = temp->next;
                temp->next = todelete->next;
                delete todelete;
            }
            else
            {
                temp = temp->next;
            }
        }
        return head;
    }
};
