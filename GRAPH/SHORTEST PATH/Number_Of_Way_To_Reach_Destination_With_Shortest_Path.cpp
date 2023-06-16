#include <bits/stdc++.h>
using namespace std;
int countPaths(int n, vector<vector<int>> &roads)
{

    vector<pair<long long, long long>> adj[n];
    for (auto it : roads)
    {
        adj[it[0]].push_back({it[1], it[2]});
        adj[it[1]].push_back({it[0], it[2]});
    }

    vector<long long> way(n, 0);
    vector<long long> dis(n, 1e15);
    dis[0] = 0;
    way[0] = 1;

    priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, greater<pair<long long, long long>>> pq;
    pq.push({0, 0});

    while (!pq.empty())
    {
        auto it = pq.top();
        pq.pop();
        long long d = it.first;
        long long node = it.second;
        for (auto it : adj[node])
        {
            long long v = it.first;
            long long w = it.second;
            long long newDis = d + w;
            if (newDis < dis[v])
            {
                dis[v] = newDis;
                pq.push({dis[v], v});
                way[v] = way[node];
            }
            else if (newDis == dis[v])
            {
                way[v] = way[v] + way[node];
                way[v] %= 1000000007;
            }
        }
    }
    return (int)way[n - 1];
}