#include <bits/stdc++.h>
using namespace std;
class Solution
{ 
public:
    vector<int> topoSort(int V, vector<int> adj[])
    {

        vector<int> indegree(V, 0);

        for (int i = 0; i < V; i++)
            for (auto it : adj[i])
                indegree[it]++;

        queue<int> q;
        vector<int> toposort;

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
    string findOrder(string dict[], int N, int K)
    {
        vector<int> adj[K];
        for (int i = 1; i < N; i++)
        {
            string s1 = dict[i - 1];
            string s2 = dict[i];
            int len = min(s1.size(), s2.size());
            for (int j = 0; j < len; j++)
            {
                if (s1[j] != s2[j])
                {
                    adj[s1[j] - 'a'].push_back(s2[j] - 'a');
                    break;
                }
            }
        }
        vector<int> toposort = topoSort(K, adj);
        string ans = "";
        for (int i = 0; i < toposort.size(); i++)
            ans += toposort[i] + 'a';
        return ans;
    }
};