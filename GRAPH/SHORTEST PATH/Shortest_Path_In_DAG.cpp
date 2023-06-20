#include <bits/stdc++.h>
using namespace std;
vector<int> shortestPath(int N, int M, vector<vector<int>> &edges)
{
    vector<pair<int, int>> adj[N];
    for (auto it : edges)
        adj[it[0]].push_back({it[1], it[2]});

    vector<int> dist(N, 1e9);

    int source = 0;
    dist[source] = 0;

    queue<int> q;
    q.push(source);

    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        for (auto it : adj[node])
        {
            int v = it.first;
            int w = it.second;
            if (dist[node] + w < dist[v])
            {
                dist[v] = dist[node] + w;
                q.push(v);
            }
        }
    }

    for (int i = 0; i < N; i++)
        if (dist[i] == 1e9)
            dist[i] = -1;

    return dist;
} 