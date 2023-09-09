#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int>dp;
    int getans(vector<int>& nums, int target,  int currsum){
        if(currsum==target){
            return 1;
        }
        if(currsum>target){
            return 0;
        }
        if(dp[currsum]!=-1){
            return dp[currsum];
        }
        int ans=0;
        for (int i = 0; i < nums.size(); i++)
        {
            int curr=nums[i];
            ans+=getans(nums,target,currsum+curr);
        }
        

        return dp[currsum]=ans;
    }
    int combinationSum4(vector<int>& nums, int target) {
        vector<int>temp(1001,-1);
        dp=temp;
        return getans(nums,target,0);
    }
};