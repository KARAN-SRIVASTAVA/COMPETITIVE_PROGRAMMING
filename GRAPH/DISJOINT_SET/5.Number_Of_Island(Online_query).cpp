#include <bits/stdc++.h>
using namespace std;
class DisjointSet
{
public:
    vector<int> parent, rank, size;
    DisjointSet(int n)
    {
        parent.resize(n + 1, 0);
        size.resize(n + 1, 0);
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

vector<int> numOfIslands(int n, int m, vector<vector<int>> &operators)
{
    DisjointSet ds(m * n);
    vector<vector<bool>> vis(n, vector<bool>(m, 0));
    int cnt = 0;
    vector<int> ans;
    for (auto it : operators)
    {
        int i = it[0];
        int j = it[1];
        if (vis[i][j])
        {
            ans.push_back(cnt);
            continue;
        }
        vis[i][j] = 1;
        cnt++;
        int dx[] = {-1, 1, 0, 0};
        int dy[] = {0, 0, -1, 1};
        int id1 = i * m + j;
        for (int p = 0; p < 4; p++)
        {
            int nx = i + dx[p];
            int ny = j + dy[p];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m || !vis[nx][ny])
                continue;
            int id2 = nx * m + ny;
            int up1 = ds.findUpar(id1);
            int up2 = ds.findUpar(id2);
            if (up1 == up2)
                continue;
            cnt--;
            ds.UnionBySize(up1, up2);
        }
        ans.push_back(cnt);
    }
    return ans;
}
