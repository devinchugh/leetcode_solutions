#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool canVisitAllRooms(vector<vector<int>> &rooms)
    {
        int n = rooms.size();
        vector<int> chk(n, 0);
        chk[0] = 1;
        queue<int> pq;
        for (auto &&i : rooms[0])
        {
            pq.push(i);
        }
        while (!pq.empty())
        {
            int a = pq.front();
            pq.pop();
            if (chk[a] == 0)
            {
                chk[a] = 1;
                for (auto &&i : rooms[a])
                {
                    pq.push(i);
                }
            }
        }
        for (auto &&i : chk)
        {
            if (i == 0)
            {
                return false;
            }
        }
        return true;
    }
};