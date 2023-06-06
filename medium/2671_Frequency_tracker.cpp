#include <bits/stdc++.h>
using namespace std;

class FrequencyTracker
{
public:
    unordered_map<int, int> mp;
    unordered_map<int,int> freq;

    FrequencyTracker()
    {
    }

    void add(int number)
    {
        if(mp[number]){
            freq[mp[number]]--;
        }
        mp[number]++;
        freq[mp[number]]++;
    }

    void deleteOne(int number)
    {
        if (mp[number])
        {
            if(freq[mp[number]]>0){
                freq[mp[number]]--;
            }
            mp[number]--;
            freq[mp[number]]++;
        }
    }

    bool hasFrequency(int frequency)
    {
        return freq[frequency]>0;
    }
};
