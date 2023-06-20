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
vector<int> eventualSafeNodes(int V, vector<int> adj[])
{
	vector<int> adjrev[V];

	for (int i = 0; i < V; i++)
		for (auto it : adj[i])
			adjrev[it].push_back(i);

	vector<int> ans = topoSort(V, adjrev);

	sort(ans.begin(), ans.end());

	return ans;
} 