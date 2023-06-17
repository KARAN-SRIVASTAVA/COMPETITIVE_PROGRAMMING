#include <bits/stdc++.h>
using namespace std;
vector<int> topoSort(int V, vector<int> adj[])
{
	vector<int> indegree(V, 0);

	for (int i = 0; i < V; i++)
		for (auto it : adj[i])
			indegree[it]++;

	vector<int> toposort;
	queue<int> q;

	for (int i = 0; i < V; i++)
		if (indegree[i] == 0)
			q.push(i);

	while (!q.empty())
	{
		int node = q.front();
		q.pop();
		toposort.push_back(node);
		for (auto it : adj[node])
		{
			indegree[it]--;
			if (indegree[it] == 0)
				q.push(it);
		}
	}
	return toposort;
}
vector<int> findOrder(int n, int m, vector<vector<int>> prerequisites)
{
	vector<int> adj[n];
	for (auto it : prerequisites)
		adj[it[1]].push_back(it[0]);
	vector<int> ans = topoSort(n, adj);
	vector<int> v;
	return ans.size() == n ? ans : v;
}