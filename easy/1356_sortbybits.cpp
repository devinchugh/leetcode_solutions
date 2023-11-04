#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    static bool getbits(int a, int b)
    {

        int n1 = 0;
        while (a)
        {
            n1 += a & 1;
            a /= 2;
        }
        int n2 = 0;
        while (b)
        {
            n2 += b & 1;
            b /= 2;
        }
        return a < b;
    }
    vector<int> sortByBits(vector<int> &arr)
    {
        sort(arr.begin(), arr.end(), getbits);
        return arr;
    }
};