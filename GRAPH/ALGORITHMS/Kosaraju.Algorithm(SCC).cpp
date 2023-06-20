#include <bits/stdc++.h>
using namespace std;
/*
* Valid Only for DG
// Steps:-
* Sort All The edges According to finishing time
* Reverse the graph
* Do a dfs
*/
void dfs(int node, vector<int> &vis, stack<int> &st, vector<vector<int>> &adj)
{
    vis[node] = 1;
    for (auto it : adj[node])
        if (!vis[it])
            dfs(it, vis, st, adj);
    st.push(node); 
}
void dfs2(int node, vector<int> &vis, vector<int> adj[])
{
    vis[node] = 1;
    for (auto it : adj[node])
        if (!vis[it])
            dfs2(it, vis, adj);
}
int kosaraju(int V, vector<vector<int>> &adj)
{
    vector<int> vis(V, 0);
    stack<int> st;

    // step 1: Sorting edges acc. to there finishing time
    for (int i = 0; i < V; i++)
        if (!vis[i])
            dfs(i, vis, st, adj);

    // step2: Reversing the graph
    vector<int> adjR[V];
    for (int i = 0; i < V; i++)
        for (auto it : adj[i])
            adjR[it].push_back(i);

    // step 3: dfs Traversal
    int cnt = 0;
    vector<int> vis2(V, 0);
    while (!st.empty())
    {
        int node = st.top();
        st.pop();
        if (!vis2[node])
        {
            cnt++;
            dfs2(node, vis2, adjR);
        }
    }

    return cnt;
}