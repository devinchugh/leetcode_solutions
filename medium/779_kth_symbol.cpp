#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int kthGrammar(int N, int K)
    {
        if(N==1){
            return 0;
        }

        int total=pow(2, N-1);
        if(K<=total/2){
            return kthGrammar(N-1, K);
        }
        return !kthGrammar(N-1, K-total/2);

    }
};