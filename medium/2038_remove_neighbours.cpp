#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    bool winnerOfGame(string colors) {
         int countA=0, countB=0;
         int n=colors.size();

         for (int i = 1; i < n-1; i++)
         {
            if(colors[i-1]==colors[i] && colors[i]==colors[i+1]){
                if(colors[i]=='A'){
                    countA++;
                }
                else{
                    countB++;
                }
            }
         }
         //cout<<countA<<' '<<countB;
         if(countA!=countB){
            return countA>countB;
         }
         return false;
         
    }
};