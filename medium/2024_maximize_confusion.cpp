#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxConsecutiveAnswers(string answerKey, int k)
    {
        queue<char> q;
        int ans = 0;
        int countT = 0, countF = 0;
        map<char, int> mp;

        for (int i = 0; i < answerKey.size(); i++)
        {
            q.push(answerKey[i]);
            if (answerKey[i] == 'T')
            {
                countT++;
            }
            else
            {
                countF++;
            }
            

            if (min(countT, countF) > k)
            {
                while (!q.empty() && min(countT, countF) > k)
                {
                    char x = q.front();
                    q.pop();
                    if (x == 'T')
                    {
                        countT--;
                    }
                    else
                    {
                        countF--;
                    }
                }
            }
            int a = q.size();
            ans = max(ans, a);
        }
        return ans;
    }
};