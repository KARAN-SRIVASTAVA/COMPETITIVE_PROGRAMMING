#include <bits/stdc++.h>
using namespace std;
#define pll pair<int, int>
vector<int> dijkstra(int V, vector<vector<int>> adj[], int S)
{
    vector<int> dist(V, 1e9);
    set<pll> s;
    s.insert({0, S});
    dist[S] = 0;
    while (!s.empty())
    {
        auto it = *s.begin();
        s.erase(it);
        int dis = it.first;
        int node = it.second;
        for (auto it : adj[node])
        {
            int adjNode = it[0];
            int adjDis = it[1];
            if (dis + adjDis < dist[adjNode])
            {
                if (dist[adjNode] != 1e9)
                {
                    // MEANS SOMEONE REACHED BEFORE AND PRESENT IN THE SET
                    // Saving Future Iterations With Erasing These Values At Cost Of LogN
                    auto it = s.find({dist[adjNode], adjNode});
                    s.erase(it);
                }
                dist[adjNode] = dis + adjDis;
                s.insert({dist[adjNode], adjNode});
            }
        }
    }
    for (int i = 0; i < V; i++)
        if (dist[i] == 1e9)
            dist[i] = -1;
    return dist;
}