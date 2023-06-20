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
            parent[Upu] = Upv;
        else if (rank[Upu] > rank[Upv])
            parent[Upv] = Upu;
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
int maxRemove(vector<vector<int>> &stones, int n)
{
    int maxRow = 0, maxCol = 0;
    for (auto it : stones)
    {
        maxRow = max(maxRow, it[0]);
        maxCol = max(maxCol, it[1]);
    }
    DisjointSet ds(maxRow + maxCol);
    for (auto it : stones)
    {
        int nodeRow = it[0];
        int nodeCol = it[1] + maxRow + 1;
        ds.UnionBySize(nodeRow, nodeCol);
    }
    unordered_set<int> s;
    for (auto it : stones)
    {
        s.insert(ds.findUpar(it[0]));
        s.insert(ds.findUpar(it[1] + maxRow + 1));
    }
    return n - s.size();
}
