#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isPossible(vector<int> &target)
    {
        long long sum = 0;
        priority_queue<int> pq;
        for (auto &&i : target)
        {
            sum += i;
            pq.push(i);
        }

        while (pq.top() != 1)
        {
            int x = pq.top();
            // cout<<x<<endl;
            pq.pop();
            sum = sum - x;
            if (sum == 0 || sum >= x)
            {
                return false;
            }
            x = x % (sum);
            if (x == 0 && sum != 1)
            {
                return false;
            }
            sum = sum + x;

            pq.push(x);
        }

        return true;
    }
};