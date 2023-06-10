#include <bits/stdc++.h>
using namespace std;
#define pll pair<int, int>
// Dijkstra Using Priority Queue
/**** Does Not Work For Negative Cycle Because of Its Greedy Nature It Will Fall into Infinite Loop ****/
/*O(E(logV))-->Time Complexity*/
vector<int> Dijkstra(int V, vector<pll> adj[], int S)
{
    vector<int> dist(V, 1e9);
    priority_queue<pll, vector<pll>, greater<pll>> pq;
    pq.push({0, S});
    dist[S] = 0;
    while (!pq.empty())
    {
        auto it = pq.top();
        pq.pop();
        int dis = it.first;
        int node = it.second;
        for (auto neb : adj[node])
        {
            int adjNode = neb.first;
            int adjDis = neb.second;
            if (dis + adjDis < dist[adjNode])
            {
                dist[adjNode] = dis + adjDis;
                pq.push({dist[adjNode], adjNode});
            }
        }
    }
    for (int i = 0; i < V; i++)
        if (dist[i] == 1e9)
            dist[i] = -1;
    return dist;
}