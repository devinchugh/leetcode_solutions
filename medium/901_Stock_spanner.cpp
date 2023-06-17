#include <bits/stdc++.h>
using namespace std;

class StockSpanner
{
public:
    stack<pair<int,int>> stack;
    StockSpanner()
    {
    }

   int next(int price) {
        int ans = 1;
        while (!stack.empty() && stack.top().first <= price) {
            ans += stack.top().second;
            stack.pop();
        }
        
        stack.push({price, ans});
        return ans;
    }
};