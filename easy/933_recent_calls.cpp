#include <bits/stdc++.h>
using namespace std;

class RecentCounter {
public:
    vector<int> arr;
    RecentCounter() {
        
    }
    
    int ping(int t) {
        arr.push_back(t);
        int ans = 0;
        for(int i = arr.size() - 1; i >= 0; i--){
            if(arr[i] >= t - 3000){
                ans++;
            }
            else{
                break;
            }
        }
        return ans;
    }
};