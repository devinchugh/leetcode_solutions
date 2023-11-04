#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<string> buildArray(vector<int> &target, int n)
    {
        vector<string> ans;

        int curr = 1;
        for (int i = 0; i < target.size(); i++)
        {
            int num = target[i];

            if (curr == num)
            {
                ans.push_back("Push");
            }
            else
            {
                while (curr < num)
                {
                    ans.push_back("Push");
                    ans.push_back("Pop");
                    curr++;
                }
                ans.push_back("Push");
            }
            curr++;
        }
        return ans;
    }
};