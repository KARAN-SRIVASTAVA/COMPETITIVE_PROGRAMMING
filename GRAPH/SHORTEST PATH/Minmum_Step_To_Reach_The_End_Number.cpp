#include <bits/stdc++.h>
using namespace std;
int minimumMultiplications(vector<int> &arr, int start, int end)
{
    queue<pair<int, int>> q;
    vector<bool> vis(100000, 0);
    vis[start] = 1;
    q.push({start, 0});
    while (!q.empty())
    {
        auto it = q.front();
        q.pop();
        int s = it.first;
        int step = it.second;
        if (s == end)
            return step;
        for (int i = 0; i < arr.size(); i++)
        {
            int newNum = (s * arr[i]) % 100000;
            if (!vis[newNum])
            {
                q.push({newNum, step + 1});
                vis[newNum] = 1;
            }
        }
    }
    return -1;
} 