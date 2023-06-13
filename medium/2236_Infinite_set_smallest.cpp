#include <bits/stdc++.h>
using namespace std;

class SmallestInfiniteSet
{
public:
    priority_queue<int, vector<int>, greater<int>> pq;
    map<int,int> mp;
    SmallestInfiniteSet()
    {
        for (int i = 1; i <= 1000; i++)
        {
            pq.push(i);
            mp[i]=1;
        }
    }

    int popSmallest()
    {
        int n=pq.top();
        pq.pop();
        mp[n]--;
        return n;
    }

    void addBack(int num)
    {
        if(mp[num]==0){
            pq.push(num);
            mp[num]++;
        }
    }
};