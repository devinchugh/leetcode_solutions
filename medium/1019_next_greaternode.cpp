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
    vector<int> nextLargerNodes(ListNode *head)
    {
        vector<int> ans;
        if (head == NULL)
        {
            return ans;
        }
        ListNode *temp = head;
        stack<pair<int, int>> st; // {element, index}
        int pos = 0;
        while (temp != NULL)
        {
            ans.push_back(0);
            while (!st.empty() && st.top().first < temp->val)
            {
                ans[st.top().second] = temp->val;
                st.pop();
            }
            st.push({temp->val,pos});
            pos++;
            temp=temp->next;
        }
        return ans;
    }
};