#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    int minSizeSubarray(vector<int>& nums, int t) {
        int n=nums.size();

        long long int sum=0;
        int ans=INT_MAX;
        int count=0;
        for (auto &&i : nums)
        {
            sum+=i;
        }
        if(t>sum){
            count = (t/sum)*n;
            t=t%sum;
        }
        int l=0, r=0;
        sum=0;
        while (r<n)
        {
            sum+=nums[r];
            while(sum>t){
                sum-=nums[l];
                l++;
            }
            if(sum==t){
               ans=min(ans, r-l+1);
            }
            r++;
        }
        r=0;
        while (r<n)
        {
            if(l==n){
                break;
            }
            sum+=nums[r];
            while(sum>t){
                sum-=nums[l];
                l++;
                if(l==n){
                    break;
                }
            }
            if(sum==t){
               ans=min(ans, n-l+r+1);
            }
            r++;
        }
        if(ans>INT_MAX/2){
            return -1;
        }
        return ans+count;
        
    }
};