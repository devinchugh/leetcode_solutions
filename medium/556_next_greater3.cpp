#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int stringToInt(const std::string &str)
    {
        try
        {
            return std::stoi(str);
        }
        catch (const std::out_of_range &e)
        {
            return -1;
        }
    }

    int nextGreaterElement(int m)
    {
        string s = to_string(m);
        if (m == 2147483486)
        {
            return -1;
        }
        int n = s.size();
        if (n <= 1)
        {
            return -1;
        }
        bool found = 0;
        for (int i = n - 2; i >= 0; i--)
        {
            int a = s[i] - '0';
            int b = s[i + 1] - '0';
            if (a < b)
            {
                int curr = a, idx = i;
                int big = -1;
                for (int j = n - 1; j > idx; j--)
                {
                    int x = s[j] - '0';
                    if (x > curr)
                    {
                        big = j;
                        break;
                    }
                }
                if (big != -1)
                {
                    swap(s[idx], s[big]);
                }
                reverse(s.begin() + idx + 1, s.end());
                return stringToInt(s);
            }
        }

        return -1;
    }
};