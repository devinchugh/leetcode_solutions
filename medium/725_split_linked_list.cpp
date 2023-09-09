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
    vector<ListNode *> splitListToParts(ListNode *head, int k)
    {
        vector<ListNode *> ans(k);
        if (head == NULL || head->next == NULL)
        {
            ans[0] = head;
            return ans;
        }

        ListNode *temp = head;
        int sz = 0;
        while (temp != NULL)
        {
            temp = temp->next;
            sz++;
        }

        if (sz <= k)
        {
            temp = head;
            for (int i = 0; i < sz; i++)
            {
                ans[i] = temp;
                ListNode *nex = temp->next;
                temp->next = NULL;
                temp = nex;
            }
            return ans;
        }

        int quo = sz / k;
        int rem = sz % k;
        temp = head;
        for (int i = 0; i < k; i++)
        {
            ans[i] = temp;
            for (int j = 0; j < quo - 1; j++)
            {
                temp = temp->next;
            }
            if (rem > 0)
            {
                temp = temp->next;
                rem--;
            }
            ListNode *nex = temp->next;
            temp->next = NULL;
            temp = nex;
        }
        return ans;
    }
};