#include<bits/stdc++.h>
using namespace std;
#define pll pair<int, int>
vector<int> dijkstra(int V, vector<vector<int>> adj[], int S)
{
    vector<int> dist(V, 1e9);
    queue<pll> q;
    q.push({0, S});
    dist[S] = 0;
    while (!q.empty())
    {
        auto it = q.front();
        q.pop();
        int dis = it.first;
        int node = it.second;
        for (auto neb : adj[node])
        {
            int adjNode = neb[0];
            int adjDis = neb[1];
            if (dis + adjDis < dist[adjNode])
            {
                dist[adjNode] = dis + adjDis;
                q.push({dist[adjNode], adjNode});
            }
        }
    }
    for (int i = 0; i < V; i++)
        if (dist[i] == 1e9)
            dist[i] = -1;
    return dist;
}