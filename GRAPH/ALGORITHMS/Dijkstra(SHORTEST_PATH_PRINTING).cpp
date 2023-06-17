#include <bits/stdc++.h>
using namespace std;
vector<int> shortestPath(int n, int m, vector<vector<int>> &edges)
{
    vector<int> dist(n + 1, 1e9);
    vector<pair<int, int>> adj[n + 1];
    for (auto it : edges)
    {
        adj[it[0]].push_back({it[1], it[2]});
        adj[it[1]].push_back({it[0], it[2]});
    }
    vector<int> parent(n + 1);
    for (int i = 1; i <= n; i++)
        parent[i] = i;
    set<pair<int, int>> s;
    dist[1] = 0;
    s.insert({0, 1});
    while (!s.empty())
    {
        auto it = *s.begin();
        int dis = it.first;
        int node = it.second;
        s.erase(it);
        for (auto it : adj[node])
        {
            int v = it.first;
            int w = it.second;
            if (dis + w < dist[v])
            {
                if (dist[v] != 1e9)
                    s.erase({dist[v], v});
                dist[v] = dis + w;
                s.insert({dist[v], v});
                parent[v] = node;
            }
        }
    }
    if (dist[n] == 1e9)
        return {-1};
    vector<int> ShortestPath;
    int start = n;
    while (parent[start] != start)
    {
        ShortestPath.push_back(start);
        start = parent[start];
    }
    ShortestPath.push_back(start);
    reverse(ShortestPath.begin(), ShortestPath.end());
    return ShortestPath;
}