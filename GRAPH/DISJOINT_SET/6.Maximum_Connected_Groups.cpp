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
class Solution
{
public:
    int MaxConnection(vector<vector<int>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();
        DisjointSet ds(m * n);
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j])
                {
                    int dx[] = {-1, 1, 0, 0};
                    int dy[] = {0, 0, 1, -1};
                    for (int k = 0; k < 4; k++)
                    {
                        int nx = i + dx[k];
                        int ny = j + dy[k];
                        if (nx >= 0 && ny >= 0 && nx < n && ny < m && grid[nx][ny])
                        {
                            int up1 = ds.findUpar(i * m + j);
                            int up2 = ds.findUpar(nx * m + ny);
                            if (up1 != up2)
                                ds.UnionBySize(up1, up2);
                        }
                    }
                }
            }
        }
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == 0)
                {
                    int dx[] = {-1, 1, 0, 0};
                    int dy[] = {0, 0, 1, -1};
                    set<int> s;
                    for (int k = 0; k < 4; k++)
                    {
                        int nx = i + dx[k];
                        int ny = j + dy[k];
                        if (nx >= 0 && ny >= 0 && nx < n && ny < m && grid[nx][ny])
                        {
                            int up2 = ds.findUpar(nx * m + ny);
                            s.insert(up2);
                        }
                    }
                    int temp = 0;
                    for (auto it : s)
                    {
                        temp += ds.size[it];
                    }
                    temp += 1;
                    ans = max(ans, temp);
                }
            }
        }
        if (ans == 0)
            return m * n;
        return ans;
    }
};