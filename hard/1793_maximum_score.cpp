#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maximumScore(vector<int> &nums, int k)
    {

        int n = nums.size();
        //priority_queue<int, vector<int>, greater<int>> left;
        int mini=nums[k];
        int l = k;
        int r = k;

        
        int score = 0;
        while (l >= 0 && r < n)
        {
            score = max(score, mini * (r - l + 1));

            int harm1 = INT_MAX;
            int harm2 = INT_MAX;

            if (l - 1 >= 0)
            {
                harm1 = mini - nums[l - 1]; // 3-1=2,
            }
            if (r + 1 < n)
            {
                harm2 = mini - nums[r + 1];
            }

            if (harm1 == INT_MAX && harm2 == INT_MAX)
            {
                break;
            }
            else if(harm1<harm2){
                l--;
                mini=min(mini, nums[l]);
            }
            else{
                r++;
                mini=min(mini, nums[r]);
            }
        }
        return score;
    }
};