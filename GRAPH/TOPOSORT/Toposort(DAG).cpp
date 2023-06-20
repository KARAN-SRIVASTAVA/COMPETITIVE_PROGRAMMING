// IT IS ONE OF THE MULTIPLE TOPOSORT --> u appears before v
// Valid Only If Graph is DAG(Directed Acyclic Graph)
#include <bits/stdc++.h>
using namespace std;
void dfs(int node, vector<int> &vis, vector<int> &ans, vector<int> adj[])
{
	vis[node] = 1;
	ans.push_back(node);
	for (auto it : adj[node])
		if (!vis[it])
			dfs(it, vis, ans, adj);
	ans.push_back(node);
}
vector<int> topoSort(int V, vector<int> adj[])
{
	vector<int> ans;
	vector<int> vis(V, 0);
	for (int i = 0; i < V; i++)
		if (!vis[i])
			dfs(i, vis, ans, adj);
	reverse(ans.begin(), ans.end());
	return ans;
} 