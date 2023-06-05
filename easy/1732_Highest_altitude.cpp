#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int ans=0;
        int maxi=0;
        for (auto &&i : gain)
        {
            ans+=i;
            maxi=max(ans,maxi);
        }
        return maxi;
    }
};