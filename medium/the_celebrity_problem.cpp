#include <bits/stdc++.h>
using namespace std;

bool knows(int a, int b) {}

int findCelebrity(int n)
{
    // Write your code here.

    stack<int> st;
    for (int i = 0; i < n; i++)
    {
        st.push(i);
    }

    while (st.size() > 1)
    {
        int a = st.top();
        st.pop();
        int b = st.top();
        st.pop();
        if(knows(a, b))
        {
            st.push(b);
        }
        else
        {
            st.push(a);
        }
    }
    if (st.size() == 0)
    {
        return -1;
    }

    int celeb = st.top();

    for (int i = 0; i < n; i++)
    {
        if (i != celeb && (knows(celeb, i) || !knows(i, celeb)))
        {
            return -1;
        }
    }
    return celeb;
}