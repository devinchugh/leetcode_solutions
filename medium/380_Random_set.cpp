#include <bits/stdc++.h>
using namespace std;

class RandomizedSet
{
public:
    map<int, int> mp;
    vector<int> arr;
    RandomizedSet()
    {
    }

    bool insert(int val)
    {
        if (mp[val] == 0)
        {
            mp[val] = 1;
            arr.push_back(val);
            return true;
        }
        return false;
    }

    bool remove(int val)
    {
        if (mp[val] != 0)
        {
            mp[val] = 0;
            vector<int>::iterator it;
            for (it = arr.begin(); it != arr.end(); it++)
            {
                if (*it == val)
                {
                    arr.erase(it);
                    return true;
                }
            }
        }
        return false;
    }

    int getRandom()
    {
        int idx = rand() % arr.size();
        return arr[idx];
    }
};
