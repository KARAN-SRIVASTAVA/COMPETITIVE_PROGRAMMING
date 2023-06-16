#include <bits/stdc++.h>
using namespace std;
bool dfs(int node, vector<int> adj[], vector<int> &vis, vector<int> &parent, int par)
{
    parent[node] = par;
    vis[node] = 1;
    for (auto it : adj[node])
    {
        if (!vis[it])
        {
            bool b = dfs(it, adj, vis, parent, node);
            if (b)
                return 1;
        }
        else if (parent[node] != it)
            return 1;
    }
    return 0;
}
bool isCycle(int V, vector<int> adj[])
{
    vector<int> vis(V, 0);
    vector<int> parent(V, 0);
    for (int i = 0; i < V; i++)
        if (!vis[i])
            if (dfs(i, adj, vis, parent, -1))
                return 1;
    return 0;
}