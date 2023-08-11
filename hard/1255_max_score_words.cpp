#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    map<char, int> mp;
    int getscore(vector<string> &words, vector<int> &score, int idx)
    {
        if (idx >= words.size())
        {
            return 0;
        }

        // not making this word
        int a = getscore(words, score, idx + 1);

        // lets make the word
        stack<char> st;
        int s = 0;
        for (auto &&chr : words[idx])
        {
            if (mp[chr] > 0)
            {
                mp[chr]--;
                s += score[chr - 'a'];
                st.push(chr);
            }
            else
            {
                s = 0;
                break;
            }
        }

        if (s != 0)
            s += getscore(words, score, idx + 1);

        while (!st.empty())
        {
            mp[st.top()]++;
            st.pop();
        }

        return max(a, s);
    }

    int maxScoreWords(vector<string> &words, vector<char> &letters, vector<int> &score)
    {

        for (auto &&chr : letters)
        {
            mp[chr]++;
        }
        return getscore(words, score, 0);
    }
};