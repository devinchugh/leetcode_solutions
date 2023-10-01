#include <bits/stdc++.h>
using namespace std;

// Define a structure to represent an edge with a weight
struct Edge {
    int source;      // The source vertex of the edge
    int destination; // The destination vertex of the edge
    int weight;      // The weight of the edge
};

// Define a structure to represent a disjoint-set (used for cycle detection)
struct DisjointSet {
    vector<int> parent;
    DisjointSet(int n) : parent(n) {
        for (int i = 0; i < n; ++i)
            parent[i] = i;
    }

    int find(int x) {
        if (parent[x] == x)
            return x;
        return parent[x] = find(parent[x]);
    }

    bool unite(int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y)
            return false;
        parent[x] = y;
        return true;
    }
};

// Compare function for sorting edges by weight
bool compareEdges(const Edge &a, const Edge &b) {
    return a.weight < b.weight;
}

class Solution {
public:
    int getManhattan(vector<int> a, vector<int> b) {
        return abs(a[0] - b[0]) + abs(a[1] - b[1]);
    }

    int minCostConnectPoints(vector<vector<int>> &points) {
        int n = points.size();
        vector<Edge> adjList;
        map<int, vector<int>> mp;
        int val = 0;

        for (auto &&i : points) {
            mp[val] = i;
            val++;
        }

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (i != j) {
                    Edge temp;
                    temp.source = i;
                    temp.destination = j;
                    temp.weight = getManhattan(mp[i], mp[j]);
                    adjList.push_back(temp);
                }
            }
        }

        // Sort the edges by weight in ascending order
        sort(adjList.begin(), adjList.end(), compareEdges);

        // Initialize a disjoint-set for cycle detection
        DisjointSet ds(n);

        // Initialize the minimum spanning tree
        vector<Edge> minimumSpanningTree;

        // Kruskal's algorithm to find the minimum spanning tree
        for (const Edge &edge : adjList) {
            int source = edge.source;
            int destination = edge.destination;
            int weight = edge.weight;

            // Check if adding this edge creates a cycle
            if (ds.find(source) != ds.find(destination)) {
                minimumSpanningTree.push_back(edge);
                ds.unite(source, destination);
            }
        }

        // Calculate the minimum cost of the minimum spanning tree
        int minimumCost = 0;
        for (const Edge &edge : minimumSpanningTree) {
            minimumCost += edge.weight;
        }

        return minimumCost;
    }
};