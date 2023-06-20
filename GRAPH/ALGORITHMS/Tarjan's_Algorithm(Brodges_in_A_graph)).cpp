#include <bits/stdc++.h>
using namespace std;
int timer = 0;
void dfs(int node, int parent, int tim[], int low[], vector<int> &vis, vector<vector<int>> &bridges, vector<int> adj[])
{
    tim[node] = low[node] = timer;
    timer++;
    vis[node] = 1;
    for (auto it : adj[node])
    {
        if (it == parent)
            continue;
        if (!vis[it])
        {
            dfs(it, node, tim, low, vis, bridges, adj);
            low[node] = min(low[node], low[it]);
            if (low[it] > tim[node])
                bridges.push_back({node, it});
        }
        else 
        {
            low[node] = min(low[node], low[it]);
        }
    }
}
vector<vector<int>> criticalConnections(int n, vector<vector<int>> &connections)
{
    vector<int> adj[n];
    for (auto it : connections)
    {
        adj[it[0]].push_back(it[1]);
        adj[it[1]].push_back(it[0]);
    }
    vector<int> vis(n, 0);
    int tim[n], low[n];
    vector<vector<int>> bridges;
    dfs(0, -1, tim, low, vis, bridges, adj);
    return bridges;
}