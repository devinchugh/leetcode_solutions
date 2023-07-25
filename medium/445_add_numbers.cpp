#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution
{
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        int sz1 = 0, sz2 = 0;
        ListNode *t1 = l1, *t2 = l2;
        stack<ListNode *> a, b;
        while (t1 != NULL)
        {
            sz1++;
            a.push(t1);
            t1 = t1->next;
        }
        while (t2 != NULL)
        {
            sz2++;
            b.push(t2);
            t2 = t2->next;
        }
        if (sz1 < sz2)
        {
            swap(l1, l2);
            swap(sz1, sz2);
            swap(a, b);
        }
        vector<int> arr;
        int carry = 0;
        while (!b.empty())
        {
            int x = a.top()->val + b.top()->val;
            t1 = a.top();
            a.pop();
            b.pop();
            if (carry)
            {
                x++;
            }
            if (x >= 10)
            {
                carry = 1;
                x = x % 10;
            }
            else
            {
                carry = 0;
            }
            t1->val = x;
        }
        while (!a.empty())
        {
            int x = a.top()->val;
            t1 = a.top();
            a.pop();
            if (carry)
            {
                x++;
            }
            if (x >= 10)
            {
                carry = 1;
                x = x % 10;
            }
            else
            {
                carry = 0;
            }
            t1->val = x;
        }
        if (carry)
        {
            t1 = new ListNode(1);
            t1->next = l1;
            l1 = t1;
        }
        return l1;
    }
};