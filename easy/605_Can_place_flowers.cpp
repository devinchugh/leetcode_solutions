#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool canPlaceFlowers(vector<int> &flowerbed, int n)
    {
        if (n == 0)
        {
            return true;
        }
        if (flowerbed.size() == 1)
        {
            if (flowerbed[0] == 0 && n == 1)
                return true;
            return false;
        }
        if (flowerbed.size() <= 2)
        {
            if (flowerbed[1] == 0 && flowerbed[0] == 0 && n == 1)
            {
                return true;
            }
            return false;
        }
        if (!flowerbed[0] && !flowerbed[1])
        {
            flowerbed[0] = 1;
            n--;
        }
        for (int i = 1; i < flowerbed.size() - 1; i++)
        {
            if (!flowerbed[i - 1] && !flowerbed[i] && !flowerbed[i + 1])
            {
                flowerbed[i] = 1;
                cout << i << endl;
                n--;
            }
        }
        if (!flowerbed[flowerbed.size() - 2] && !flowerbed[flowerbed.size() - 1])
        {
            flowerbed[flowerbed.size() - 1] = 1;
            n--;
        }
        if (n <= 0)
        {
            return true;
        }
        return false;
    }
};