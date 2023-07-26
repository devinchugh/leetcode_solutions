#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isRobotBounded(string instructions)
    {

        vector<int> pos = {0, 0, 0};

        for (auto &&chr : instructions)
        {
            if (chr == 'G')
            {
                if (pos[2] == 0)
                    pos[1]++;
                if (pos[2] == 1)
                    pos[1]--;
                if (pos[2] == 2)
                    pos[0]++;
                if (pos[2] == 3)
                    pos[0]--;
            }
            else if (chr == 'L')
            {
                if (pos[2] == 0)
                    pos[2] = 3;
                else if (pos[2] == 3)
                    pos[2] = 1;
                else if (pos[2] == 1)
                    pos[2] = 2;
                else
                    pos[2] = 0;
            }
            else{
                if (pos[2] == 0)
                    pos[2] = 2;
                else if (pos[2] == 3)
                    pos[2] = 0;
                else if (pos[2] == 1)
                    pos[2] = 3;
                else
                    pos[2] = 1;
            }
        }
        if(pos[2]!=0 || (pos[1]==0 && pos[0]==0)){
            return true;
        }
        return false;
    }
};