#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    unordered_set<string> words;
    vector<char> chrs;

    int ladderLength(string beginWord, string endWord, vector<string> &wordList)
    {

        for (auto &&i : wordList)
        {
            words.insert(i);
        }

        char a = 'a';
        while (a <= 'z')
        {
            chrs.push_back(a);
            a++;
        }
        int x = 1;

        queue<string> q;
        q.push(beginWord);
        while (!q.empty())
        {
            int n = q.size();
            for (int _ = 0; _ < n; _++)
            {
                string word = q.front();
                q.pop();
                if (word == endWord)
                {
                    return x;
                }
                words.erase(word);
                for (int i = 0; i < word.size(); i++)
                {
                    for (int j = 0; j < chrs.size(); j++)
                    {
                        string temp = word;
                        temp[i] = chrs[j];
                        if (words.find(temp) != words.end())
                        {

                            q.push(temp);
                        }
                    }
                }
            }
            x++;
        }

        return 0;
    }
};