#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> asteroidCollision(vector<int> &asteroids)
    {
        stack<int> arr;
        vector<int> ans;
        for (int i = 0; i < asteroids.size(); i++)
        {
            if (arr.empty())
            {
                arr.push(asteroids[i]);
            }
            else
            {
                if (arr.top() * asteroids[i] >= 0)
                {
                    arr.push(asteroids[i]);
                }
                else if (arr.top() < 0)
                {
                    arr.push(asteroids[i]);
                }
                else
                {
                    bool found = 1;
                    bool chk = 0;
                    while (!arr.empty() && arr.top() > 0 && asteroids[i] < 0 && abs(arr.top()) <= abs(asteroids[i]))
                    {
                        if (abs(arr.top()) == abs(asteroids[i]))
                        {
                            arr.pop();
                            found = 0;
                            break;
                        }
                        chk = 1;
                        arr.pop();
                    }
                    if (found && chk && (arr.empty() || arr.top() * asteroids[i] >= 0))
                    {
                        arr.push(asteroids[i]);
                    }
                }
            }
        }
        while (!arr.empty())
        {
            ans.push_back(arr.top());
            arr.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};