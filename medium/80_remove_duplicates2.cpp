#include <bits/stdc++.h>
using namespace std;


class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {
        int n = nums.size();
        if(n<=2){
            return n;
        }
        int slow = 2, fast = 2;
        while (fast < n)
        {
            if (slow > 1 && nums[slow - 1] == nums[fast] && nums[slow-2] == nums[fast])
            {
                while (fast < n && nums[slow-1] == nums[fast])
                {
                    fast++;
                }
                if (fast < n){
                    nums[slow] = nums[fast];
                    slow++;

                }    
                fast++;
                
            }
            else
            {
                nums[slow] = nums[fast];
                slow++;
                fast++;
            }
        }
        return slow;
    }
};