#include <bits/stdc++.h>
using namespace std;
int CheapestFLight(int n, vector<vector<int>> &flights, int src, int dst, int k)
{

    vector<pair<int, int>> adj[n];
    for (auto it : flights)
        adj[it[0]].push_back({it[1], it[2]});

    vector<int> dis(n, 1e9);
    set<pair<int, pair<int, int>>, greater<pair<int, pair<int, int>>>> s;

    // k,node,dist
    dis[src] = 0;
    s.insert({k, {src, 0}});

    while (!s.empty())
    {

        auto it = *s.begin();
        s.erase(it);
        int k = it.first;
        int node = it.second.first;
        int dist = it.second.second;

        if (k == -1)
            continue;
        for (auto it : adj[node])
        {
            int v = it.first;
            int w = it.second;
            int newdist = dist + w;
            if (newdist < dis[v])
            {
                dis[it.first] = newdist;
                s.insert({k - 1, {v, dis[v]}});
            }
        }
    }

    if (dis[dst] == 1e9)
        return -1;
    return dis[dst];
} 