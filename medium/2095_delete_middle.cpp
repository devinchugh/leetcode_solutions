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
    ListNode *deleteMiddle(ListNode *head)
    {
        int n = 0;
        if (head == NULL)
        {
            return head;
        }
        ListNode *temp = head;
        while (temp != NULL)
        {
            n++;
            temp = temp->next;
        }
        temp = head;
        n=n/2;
        for (int _ = 0; _ < n - 1; _++)
        {
            temp = temp->next;
        }
        ListNode *todelete = temp->next;
        temp->next = todelete->next;
        delete todelete;
        return head;
    }
};