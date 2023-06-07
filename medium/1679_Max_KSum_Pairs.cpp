#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        int ans=0;
        sort(nums.begin(),nums.end());

        int l=0, r=nums.size()-1;
        while (l<r)
        {
            if(nums[l]+nums[r]==k){
                l++;
                r--;
                ans++;
            }
            else if(nums[l]+nums[r]>k){
                r--;
            }
            else{
                l++;
            }
        }
        return ans;
        
    }
};