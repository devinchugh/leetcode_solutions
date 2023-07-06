#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool chksquare(vector<int> &sticks, vector<int> &sides, int curr, int target)
    {
        if (curr == sticks.size())
        {
            return ((sides[0] == sides[1]) && (sides[0] == sides[2]) && (sides[0] == sides[3]));
        }
        for (int i = 0; i < 4; i++)
        {
            if(sides[i] + sticks[curr]>target){
                continue;
            }
            sides[i] += sticks[curr];
            if (chksquare(sticks, sides, curr + 1, target))
            {
                return true;
            }
            sides[i] -= sticks[curr];
        }
        return false;
    }
    bool makesquare(vector<int> &sticks)
    {
        int n = sticks.size();
        vector<int> sides(4, 0);
        int target=0;
        for (auto &&val : sticks)
        {
            target+=val;
        }
        if(target%4!=0){
            return false;
        }
        target/=4;
        
        return chksquare(sticks, sides, 0, target);
    }
};