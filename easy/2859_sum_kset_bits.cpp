#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int getsetbits(int n)
    {
        int count = 0;
        while (n)
        {
            if (n & 1)
            {
                count++;
            }
            n = n >> 1;
            //cout << n << endl;
        }
        return count;
    }
    int sumIndicesWithKSetBits(vector<int> &nums, int k)
    {
        int sum=0;
        for (auto &&i : nums)
        {
            if(getsetbits(i)==k){
                sum+=i;
            }
        }
        
        return sum;
    }
};

