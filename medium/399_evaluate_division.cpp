#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string getminidist(map<string, double> &distance, map<string, bool> &visited)
    {
        double mini = INFINITY;
        string ans;
        for (auto &&vertex : distance)
        {
            if (!visited[vertex.first] && vertex.second <= mini)
            {
                mini = vertex.second;
                ans = vertex.first;
            }
        }
        return ans;
    }
    double dijkstra(map<string, vector<pair<string, double>>> &graph, string source, string dest)
    {
        map<string, double> distance;
        map<string, bool> visited;
        int count = 0;
        for (auto &&vertices : graph)
        {
            distance[vertices.first] = INFINITY;
            visited[vertices.first] = 0;
            count++;
        }
        distance[source] = 1;

        while (count--)
        {
            string neigh = getminidist(distance, visited);
            visited[neigh] = 1;

            for (int i = 0; i < graph[neigh].size(); i++)
            {
                double x = distance[neigh] * graph[neigh][i].second;
                distance[graph[neigh][i].first] = min(distance[graph[neigh][i].first], x);
            }
        }
        return distance[dest];
    }
    vector<double> calcEquation(vector<vector<string>> &equations, vector<double> &values, vector<vector<string>> &queries)
    {
        map<string, bool> mp;
        vector<double> ans;
        map<string, vector<pair<string, double>>> graph;
        int n = equations.size();
        for (int i = 0; i < n; i++)
        {
            string x, y;
            double val;
            x = equations[i][0];
            y = equations[i][1];
            val = values[i];
            mp[x] = 1;
            mp[y] = 1;
            graph[x].push_back({y, val});
            graph[y].push_back({x, 1 / val});
        }

        for (auto &&query : queries)
        {
            double a = -1;
            if (mp[query[0]] && mp[query[1]])
            {
                if (query[0] == query[1])
                {
                    a = 1;
                }
                else
                {
                    a = dijkstra(graph, query[0], query[1]);
                    if (a >= INFINITY)
                    {
                        a = -1;
                    }
                }
                ans.push_back(a);
            }
            else
            {
                ans.push_back(a);
            }
        }
        return ans;
    }
};