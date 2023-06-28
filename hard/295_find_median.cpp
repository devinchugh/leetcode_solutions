#include <bits/stdc++.h>
using namespace std;

class MedianFinder
{
public:
    priority_queue<int> maxheap;
    priority_queue<int, vector<int>, greater<int>> minheap;
    MedianFinder()
    {
    }
    void balance()
    {
        int m = maxheap.size(), n = minheap.size();
        if (abs(m - n) <= 1)
        {
            return;
        }
        if (m > n)
        {
            while (m - n > 1)
            {
                minheap.push(maxheap.top());
                maxheap.pop();
                m--;
                n++;
            }
        }
        else
        {
            while (n - m > 1)
            {
                maxheap.push(minheap.top());
                minheap.pop();
                m++;
                n--;
            }
        }
    }
    void addNum(int num)
    {
        if (maxheap.empty())
        {
            maxheap.push(num);
        }
        else if (maxheap.top() > num)
        {
            maxheap.push(num);
            balance();
        }
        else
        {
            minheap.push(num);
            balance();
        }
    }

    double findMedian()
    {
        int n = maxheap.size(), m = minheap.size();
        if (m == n)
        {
            return (double)(maxheap.top() + minheap.top()) / 2.0;
        }
        if (m > n)
        {
            return minheap.top();
        }
        return maxheap.top();
    }
};