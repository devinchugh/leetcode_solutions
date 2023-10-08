#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int longestEqualSubarray(vector<int> &nums, int k)
    {
        int n = nums.size();
        if(n==1){
            return 1;
        }
        map<int,int> mp;
        int maxi=1;
        int left=0;
        for(int i=0;i<n;i++){
            mp[nums[i]]++;
            maxi=max(maxi,mp[nums[i]]);
            if(i-left+1-maxi>k){
                mp[nums[left]]--;
                left++;
            }

        }
        return maxi;
    }
};