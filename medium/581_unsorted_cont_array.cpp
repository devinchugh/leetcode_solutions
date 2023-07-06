#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findUnsortedSubarray(vector<int> &nums)
    {
        if (is_sorted(nums.begin(), nums.end()))
        {
            return 0;
        }
        if(nums.size()==2){
            return 2;
        }
        if (nums[0] > nums[nums.size()-1])
        {
            return nums.size();
        }
        int left = 0, right = nums.size() - 1;
        
        while (left < right && nums[left] <= nums[left + 1])
        {
            left++;
        }
        cout<<left<<endl;
        while (left < right && nums[right] >= nums[right - 1])
        {
            right--;
        }
        cout<<right<<endl;
        int mini = *min_element(nums.begin() + left, nums.begin() + right+1), maxi = *max_element(nums.begin() + left, nums.begin() + right+1);
        cout<<maxi<<' '<<mini<<endl;
        while (left >= 0 && nums[left] > mini)
        {
            left--;
        }
        while (right < nums.size() && nums[right] < maxi)
        {
            right++;
        }
        return right - left - 1;
    }
};

int main()
{
    vector<int> arr = {1,3,2,4};
    Solution sl;
    cout << sl.findUnsortedSubarray(arr);
}