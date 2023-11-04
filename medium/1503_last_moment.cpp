#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int getLastMoment(int n, vector<int> &left, vector<int> &right)
    {
        int maxi = 0;

        for (auto &&i : left)
        {
            maxi = max(abs(i), maxi);
        }
        for (auto &&i : right)
        {
            maxi = max(abs(i - n), maxi);
        }
        return maxi;
    }
};