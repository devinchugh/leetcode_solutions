#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *reverseKGroup(ListNode *head, int k)
    {
        stack<ListNode *> st;

        ListNode *temp = head;
        if (temp == NULL)
        {
            return temp;
        }

        ListNode *newhead = NULL;
        ListNode *curr = NULL;

        while (temp != NULL)
        {
            st.push(temp);
            temp = temp->next;
            if (st.size() == k)
            {
                if (newhead == NULL)
                {
                    newhead = st.top();
                    curr = newhead;
                    st.pop();
                }
                while (!st.empty())
                {
                    curr->next = st.top();
                    st.pop();
                    curr = curr->next;
                    curr->next = NULL;
                }
            }
        }
        if (st.size() != 0)
        {
            stack<ListNode *> temp;
            while (!st.empty())
            {
                temp.push(st.top());
                st.pop();
            }
            swap(st, temp);
            while (!st.empty())
            {
                curr->next = st.top();
                st.pop();
                curr = curr->next;
                curr->next = NULL;
            }
        }
        return newhead;
    }
};