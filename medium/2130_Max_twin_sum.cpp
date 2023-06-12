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
    int pairSum(ListNode *head)
    {
        int n = 0;
        if (head == NULL)
        {
            return 0;
        }
        stack<int> st;
        ListNode *temp = head;
        while (temp != NULL)
        {
            n++;
            st.push(temp->val);
            temp = temp->next;
        }
        temp = head;
        n = n / 2;
        int maxi=0;
        for (int _ = 0; _ < n; _++)
        {
            maxi=max(temp->val+st.top(),maxi);
            st.pop();
            temp=temp->next;
        }
        return maxi;
        
    }
};