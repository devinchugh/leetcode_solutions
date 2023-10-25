#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n=nums.size();

        set<int> s(nums.begin(), nums.end());
        vector<int> arr(s.begin(), s.end());
        sort(arr.begin(), arr.end());
        int ans=n;
        for (int i = 0; i < arr.size(); i++)
        {
            int left=arr[i];
            int right=left+n-1;
            int j=upper_bound(arr.begin(), arr.end(), right)-arr.begin();
            int count=j-i;
            ans=min(ans, n-count);
        }
        return ans;
    }
};