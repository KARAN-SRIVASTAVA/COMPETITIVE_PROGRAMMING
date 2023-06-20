#include <bits/stdc++.h>
using namespace std;
bool isCycle(int V, vector<int> adj[])
{
    vector<int> vis(V, 0);
    vector<int> parent(V, -1);
    for (int i = 0; i < V; i++)
    {
        if (!vis[i])
        { 
            parent[i] = -1;
            vis[i] = 1;
            queue<int> q;
            q.push(i);
            while (!q.empty())
            {
                int node = q.front();
                q.pop();
                for (auto it : adj[node])
                {
                    if (!vis[it])
                    {
                        vis[it] = 1;
                        q.push(it);
                        parent[it] = node;
                    }
                    else if (parent[node] != it)
                    {
                        return 1;
                    }
                }
            }
        }
    }
    return 0;
}