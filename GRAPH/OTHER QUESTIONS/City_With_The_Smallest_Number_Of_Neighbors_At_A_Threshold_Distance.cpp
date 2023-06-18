#include <bits/stdc++.h>
using namespace std;
int findCity(int n, int m, vector<vector<int>> &edges, int ThreDis)
{
    vector<vector<int>> dist(n, vector<int>(n, 1e9));
    for (auto it : edges)
    {
        dist[it[0]][it[1]] = it[2];
        dist[it[1]][it[0]] = it[2];
    }
    for (int i = 0; i < n; i++)
        dist[i][i] = 0;

    for (int via = 0; via < n; via++)
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if (dist[i][via] + dist[via][j] < dist[i][j])
                    dist[i][j] = dist[i][via] + dist[via][j];

    int city = -1;
    int small = 1e9;
    for (int i = 0; i < n; i++)
    {
        int cnt = 0;
        for (int j = 0; j < n; j++)
            if (dist[i][j] <= ThreDis)
                cnt++;
        if (cnt <= small)
        {
            small = cnt;
            city = i;
        }
    }

    return city;
}