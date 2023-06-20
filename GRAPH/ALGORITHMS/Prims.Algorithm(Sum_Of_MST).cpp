#include <bits/stdc++.h>
using namespace std;
int spanningTree(int V, vector<vector<int>> adj[])
{
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    pq.push({0, 0});
    vector<int> vis(V, 0);
    int sum = 0;
    while (!pq.empty())
    {
        auto it = pq.top();
        pq.pop();
        int wt = it.first;
        int node = it.second; 
        if (vis[node])
            continue;
        vis[node] = 1;
        sum += wt;
        for (auto it : adj[node])
        {
            int v = it[0];
            int w = it[1];
            if (!vis[v])
            {
                pq.push({w, v});
            }
        }
    }
    return sum;
}