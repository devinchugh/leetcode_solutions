#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int countGreater(vector<int> arr, int n, double k)
    {
        int l = 0;
        int r = n - 1;

        // Stores the index of the left most element
        // from the array which is greater than k
        int leftGreater = n;

        // Finds number of elements greater than k
        while (l <= r)
        {
            int m = l + (r - l) / 2;

            // If mid element is greater than
            // k update leftGreater and r
            if (arr[m] >= k)
            {
                leftGreater = m;
                r = m - 1;
            }

            // If mid element is less than
            else
                l = m + 1;
        }

        // Return the count of elements greater than k
        return (n - leftGreater);
    }
    vector<int> successfulPairs(vector<int> &spells, vector<int> &potions, long long success)
    {
        sort(potions.begin(), potions.end());
        vector<int> ans;
        for (int i = 0; i < spells.size(); i++)
        {
            int x = spells[i];
            double k= (double)success/x;;
            
            int m=countGreater(potions,potions.size(),k);
            ans.push_back(m);
        }
        return ans;
    }
};