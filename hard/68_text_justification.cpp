#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<string> fullJustify(vector<string> &words, int maxWidth)
    {
        vector<string> ans;

        int i = 0;
        int n = words.size();

        while (i < n)
        {
            queue<string> q;
            int sz = 0;
            while (i < n && sz + q.size() - 1 + words[i].size() < maxWidth)
            {
                sz += words[i].size();
                q.push(words[i]);
                i++;
            }
            string line = "";
            if (i >= n)
            {
                while (!q.empty())
                {
                    line += q.front();
                    q.pop();
                    line += " ";
                }
                line.pop_back();
                int x = maxWidth - line.size();
                for (int _ = 0; _ < x; _++)
                {
                    line += " ";
                }

                ans.push_back(line);
                return ans;
            }
            if (sz + q.size() - 1 == maxWidth)
            {
                while (!q.empty())
                {
                    line += q.front();
                    q.pop();
                    line += " ";
                }
                line.pop_back();
            }
            else
            {
                int spaces = maxWidth - sz;
                if (q.size() == 1)
                {
                    line += q.front();
                    q.pop();
                    for (int _ = 0; _ < spaces; _++)
                    {
                        line += " ";
                    }
                    // ans.push_back(line);
                    // continue;
                }
                else
                {
                    int wrdspace = spaces / (q.size() - 1);
                    string space = "";
                    for (int _ = 0; _ < wrdspace; _++)
                    {
                        space += " ";
                    }
                    line += q.front();
                    int count = -1;
                    if (spaces % (q.size() - 1) != 0)
                    {
                        count = spaces % (q.size() - 1);
                        space += " ";
                    }
                    line += space;
                    q.pop();
                    count--;
                    while (!q.empty())
                    {
                        if (count == 0)
                        {
                            space.pop_back();
                        }
                        line += q.front();
                        q.pop();
                        line += space;
                        count--;
                    }
                    for (int _ = 0; _ < wrdspace; _++)
                    {
                        line.pop_back();
                    }
                }
            }

            ans.push_back(line);
        }
        return ans;
    }
};