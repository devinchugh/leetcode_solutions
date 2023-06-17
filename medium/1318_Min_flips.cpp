#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minFlips(int a, int b, int c)
    {
        int ans = 0;
        while (a || b || c)
        {
            int lastbit = c & 1;
            int l_a = a & 1;
            int l_b = b & 1;
            if (lastbit == 1)
            {
                if (l_a == 0 && l_b == 0)
                {
                    ans++;
                }
            }
            else
            {
                if(l_a==1 && l_b==1){
                    ans+=2;
                }
                else if(l_a==1 || l_b==1){
                    ans++;
                }
            }
            a=a>>1;
            b=b>>1;
            c=c>>1;
        }
        return ans;
    }
};


