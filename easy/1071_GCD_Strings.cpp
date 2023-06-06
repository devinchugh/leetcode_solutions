#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string gcdOfStrings(string s1, string s2)
    {

        int n1 = s1.size(), n2 = s2.size();
        if (s1 + s2 == s2 + s1)
        {
            int x=__gcd(n1,n2);
            return s1.substr(0,x);
        }
        return "";
    }
};
