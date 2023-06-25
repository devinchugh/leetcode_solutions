#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    vector<vector<int>> ans;
    void findans(vector<int>& candidates, int target, vector<int> &curr, int currpos){
        if(target<0 || currpos>=candidates.size()){
            return;
        }
        if(target==0){
            ans.push_back(curr);
            return;
        }
        findans(candidates, target, curr, currpos+1);
        curr.push_back(candidates[currpos]);
        findans(candidates, target - candidates[currpos], curr, currpos);
        curr.pop_back();
        
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> curr;
        findans(candidates,target,curr,0);
        return ans;
    }
};