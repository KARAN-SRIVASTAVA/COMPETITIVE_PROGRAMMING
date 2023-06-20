#include <bits/stdc++.h>
using namespace std;
void bfs(int node, vector<int> &vis, vector<int> adj[], vector<int> &bfs)
{
    vis[node] = 1;
    queue<int> q;
    q.push(node);
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        bfs.push_back(node);
        for (auto it : adj[node])
        {
            if (!vis[it])
            {
                vis[it] = 1;
                q.push(it);
            }
        }
    }
}
vector<int> bfsOfGraph(int V, vector<int> adj[])
{
    vector<int> vis(V, 0); 
    vector<int> ans;
    bfs(0, vis, adj, ans);
    return ans;
}