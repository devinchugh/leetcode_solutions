#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        vector<bool> ans;
        int x=*max_element(begin(candies), end(candies));
        for (int i = 0; i < candies.size(); i++)
        {
            ans.push_back(candies[i]+extraCandies>=x);
        }
        return ans;
        
    }
};