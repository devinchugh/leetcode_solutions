#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    int findMin(vector<int>& nums) {
        int l=0;
        int r=nums.size()-1;
        int n=nums.size();
        if(n==1){
            return nums[l];
        }

        int mid;
        while (l<=r)
        {
            mid=l+(r-l)/2;
            if((mid==0 || nums[mid]<nums[mid-1]) && (mid==n-1 || nums[mid]<nums[mid+1])){
                return nums[mid];
            }
            if(nums[mid]<nums[r]){
                r=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        return nums[mid];
    }
};