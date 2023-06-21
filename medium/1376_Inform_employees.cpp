#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int timetoinform(int n, map<int, vector<int>> &mngrof, vector<int> &informTime, int head)
    {
        if (informTime[head] == 0)
        {
            return 0;
        }
        int nodesinformtime = 0;
        for (auto &&i : mngrof[head])
        {
            nodesinformtime = max(nodesinformtime, timetoinform(n, mngrof, informTime, i));
        }

        return nodesinformtime + informTime[head];
    }
    int numOfMinutes(int n, int headID, vector<int> &manager, vector<int> &informTime)
    {

        map<int, vector<int>> mngrof;
        for (int i = 0; i < n; i++)
        {
            mngrof[manager[i]].push_back(i);
        }

        return timetoinform(n, mngrof, informTime, headID);
    }
};