#include <bits/stdc++.h>
using namespace std;
class DisjointSet
{
public:
    vector<int> parent, rank, size;
    DisjointSet(int n)
    {
        parent.resize(n + 1, 0);
        size.resize(n + 1, 0);
        rank.resize(n + 1, 0);
        for (int i = 0; i < n + 1; i++)
            parent[i] = i;
    }
    int findUpar(int node)
    {
        if (node == parent[node])
            return node;
        return parent[node] = findUpar(parent[node]);
    }
    void UnionByRank(int u, int v)
    {
        int Upu = findUpar(u);
        int Upv = findUpar(v);
        if (Upu == Upv)
            return;
        if (rank[Upu] < rank[Upv])
        {
            parent[Upu] = Upv;
        }
        else if (rank[Upu] > rank[Upv])
        {
            parent[Upv] = Upu;
        }
        else
        {
            parent[Upv] = Upu;
            rank[Upu]++;
        }
    }
    void UnionBySize(int u, int v)
    {
        int Upu = findUpar(u);
        int Upv = findUpar(v);
        if (Upu == Upv)
            return;
        if (size[Upu] < size[Upv])
        {
            parent[Upu] = Upv;
            size[Upv] += size[Upu];
        }
        else
        {
            parent[Upv] = Upu;
            size[Upu] += size[Upv];
        }
    }
};
class Solution
{
public:
    vector<vector<string>> accountsMerge(vector<vector<string>> &accounts)
    {

        map<string, int> mp;
        int n = accounts.size();

        DisjointSet ds(n);

        for (int i = 0; i < n; i++)
            for (int j = 1; j < accounts[i].size(); j++)
                if (mp.find(accounts[i][j]) == mp.end())
                    mp[accounts[i][j]] = i;
                else
                    ds.UnionBySize(i, mp[accounts[i][j]]);

        vector<string> adj[n];

        for (auto it : mp)
        {
            string mail = it.first;
            int node = ds.findUpar(it.second);
            adj[node].push_back(mail);
        }

        vector<vector<string>> ans;

        for (int i = 0; i < n; i++)
        {
            if (adj[i].size() == 0)
                continue;
            sort(adj[i].begin(), adj[i].end());
            vector<string> temp;
            temp.push_back(accounts[i][0]);
            for (auto it : adj[i])
                temp.push_back(it);
            ans.push_back(temp);
        }

        return ans;
    }
};