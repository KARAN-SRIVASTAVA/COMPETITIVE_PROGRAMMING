#include <bits/stdc++.h>
using namespace std;
int timer = 0;
void dfs(int node, int parent, int low[], int tim[], vector<int> &vis,
         vector<int> &mark, vector<int> adj[])
{
    vis[node] = 1;
    tim[node] = low[node] = timer;
    timer++;
    int child = 0;
    for (auto it : adj[node])
    {
        if (it == parent)
            continue;
        if (!vis[it])
        {
            dfs(it, node, low, tim, vis, mark, adj);
            low[node] = min(low[node], low[it]);
            if (low[it] >= tim[node] && parent != -1)
                mark[node] = 1;
            child++;
        }
        else
            low[node] = min(low[node], tim[it]);
    }
    if (child > 1 && parent == -1)
        mark[node] = 1;
}
vector<int> articulationPoints(int n, vector<int> adj[])
{

    int low[n], tim[n];
    vector<int> vis(n, 0), mark(n, 0);

    for (int i = 0; i < n; i++)
        if (!vis[i])
            dfs(i, -1, low, tim, vis, mark, adj);

    vector<int> ans;

    for (int i = 0; i < n; i++)
        if (mark[i])
            ans.push_back(i);

    if (ans.size() == 0)
        return {-1};
    return ans;
}