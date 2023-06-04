#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int longestConsecutive(vector<int> &nums)
    {
        if (nums.size()==0)
        {
            return 0;
        }
        
        map<int, int> mp;
        for (auto &&i : nums)
        {
            mp[i]++;
        }
        int count = 1;
        int curr = 1;
        int prev = (*mp.begin()).first;
        map<int, int>::iterator it = mp.begin();
        it++;

        for (it; it != mp.end(); it++)
        {
            pair<int, int> temp = *it;
            if (temp.first == prev + 1)
            {
                prev = temp.first;
                curr++;
                count = max(curr, count);
            }
            else
            {
                prev = temp.first;
                curr = 1;
            }
        }
        return count;
    }
};

int main()
{
}