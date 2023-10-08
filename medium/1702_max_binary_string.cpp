#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string maximumBinaryString(string binary)
    {
        int i = 0;
        int n = binary.size();

        while (i < n && binary[i] != '0')
        {
            i++;
        }
        if (i == n)
        {
            return binary;
        }

        int leadingones = i;

        int ones = 0;
        int zeroes = 0;
        int pos = i;
        for (int i; i < n; i++)
        {
            if (binary[i] == '0')
            {
                zeroes++;
            }
            else
            {
                ones++;
            }
            binary[i] = '1';
        }
        binary[pos + zeroes] = '0';
        return binary;
    }
};