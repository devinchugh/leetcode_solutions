#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int kthFactor(int n, int k) {
        vector<int> factors;

        for (int i = 1; i <= n/2; i++)
        {
            if(n%i==0){
                factors.push_back(i);
            }
            if(factors.size()==k){
                return factors[k-1];
            }
        }
        factors.push_back(n);
        if(factors.size()==k){
                return factors[k-1];
        }
        return -1;
        
    }
};