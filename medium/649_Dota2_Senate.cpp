#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string predictPartyVictory(string senate)
    {
        queue<char> qD, qR;
        int n = senate.size();
        for (int i = 0; i < n; i++)
        {
            if (senate[i] == 'R')
            {
                qR.push(i);
            }
            else
            {
                qD.push(i);
            }
        }
        while (!qD.empty() && !qR.empty())
        {
            int d = qD.front();
            int r = qR.front();
            qD.pop();
            qR.pop();
            if (r > d)
            {
                qD.push(n + d);
            }
            else
            {
                qR.push(r + n);
            }
        }
        if(qR.size()>qD.size()){
            return "Radiant";
        }
        return "Dire";
    }
};