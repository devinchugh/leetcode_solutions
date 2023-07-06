#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int fourSumCount(vector<int> &nums1, vector<int> &nums2, vector<int> &nums3, vector<int> &nums4)
    {
        int a = nums1.size();
        int b = nums2.size();
        int c = nums3.size();
        int d = nums4.size();
        int count = 0;
        unordered_map<int, int> mp;
        for (int i = 0; i < c; i++)
        {
            for (int j = 0; j < d; j++)
            {
                mp[nums3[i] + nums4[j]]++;
            }
        }

        for (int i = 0; i < a; i++)
        {
            for (int j = 0; j < b; j++)
            {

                if (mp[-(nums1[i] + nums2[j])])
                {
                    // mp[-(nums1[i] + nums2[j] + nums3[k])]--;
                    count += mp[-(nums1[i] + nums2[j])];
                }
            }
        }
        return count;
    }
};