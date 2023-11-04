#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int poorPigs(int buckets, int minutesToDie, int minutesToTest)
    {
        int num = minutesToTest / minutesToDie;
        int ans = ceil(log2(buckets)/log2(num+1));
        
        return ans;
    }
};