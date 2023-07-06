#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    int getans(int n){
        if(n==2){
            return 1;
        }
        int ans=0;
        for (int i = 1; i < n; i++)
        {
            ans=max(ans,i*getans(n-i));
        }
        return ans;
        
    }
    int integerBreak(int n) {
        return getans(n);
    }
};