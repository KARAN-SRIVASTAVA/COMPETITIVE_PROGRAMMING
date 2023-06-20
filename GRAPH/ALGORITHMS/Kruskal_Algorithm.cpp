#include <bits/stdc++.h>
using namespace std;
class DisjointSet
{
public:
    vector<int> parent, rank, size;
    DisjointSet(int n)
    {
        parent.resize(n + 1, 0);
        size.resize(n + 1, 1);
        rank.resize(n + 1, 0);
        for (int i = 0; i < n + 1; i++)
            parent[i] = i; 
    }
    int findUpar(int node)
    {
        if (node == parent[node])
            return node;
        return parent[node] = findUpar(parent[node]);
    }
    void UnionByRank(int u, int v)
    {
        int Upu = findUpar(u);
        int Upv = findUpar(v);
        if (Upu == Upv)
            return;
        if (rank[Upu] < rank[Upv])
        {
            parent[Upu] = Upv;
        }
        else if (rank[Upu] > rank[Upv])
        {
            parent[Upv] = Upu;
        }
        else
        {
            parent[Upv] = Upu;
            rank[Upu]++;
        }
    }
    void UnionBySize(int u, int v)
    {
        int Upu = findUpar(u);
        int Upv = findUpar(v);
        if (Upu == Upv)
            return;
        if (size[Upu] < size[Upv])
        {
            parent[Upu] = Upv;
            size[Upv] += size[Upu];
        }
        else
        {
            parent[Upv] = Upu;
            size[Upu] += size[Upv];
        }
    }
};
int spanningTree(int V, vector<vector<int>> adj[])
{
    vector<pair<int, pair<int, int>>> edges;
    // O(V+E)
    for (int i = 0; i < V; i++)
        for (auto it : adj[i])
            edges.push_back({it[1], {i, it[0]}});

    // O(E(logE))
    sort(edges.begin(), edges.end());

    DisjointSet ds(V);
    int sum = 0;
    // O(E)
    for (auto it : edges)
    {
        int wt = it.first;
        int u = it.second.first;
        int v = it.second.second;
        // O(4*Alpha) => O(1)
        if (ds.findUpar(u) != ds.findUpar(v))
        {
            sum += wt;
            ds.UnionByRank(u, v);
        }
    }
    return sum;
}