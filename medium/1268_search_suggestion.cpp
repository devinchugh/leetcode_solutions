#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<string>> suggestedProducts(vector<string> &products, string searchWord)
    {
        int n = searchWord.size();
        vector<vector<string>> ans;
        
        int curr = 0;
        while (curr < n)
        {
            vector<string> temp;
            char a = searchWord[curr];
            for (auto &&word : products)
            {
                if (curr< word.size() && word[curr] == a)
                {
                    temp.push_back(word);
                }
            }
            sort(begin(temp), end(temp));
            vector<string> toinsert;
            int sz = temp.size();
            for (int i = 0; i < min(sz, 3); i++)
            {
                toinsert.push_back(temp[i]);
            }
            ans.push_back(toinsert);
            products=temp;
            curr++;
        }
        return ans;
    }
};