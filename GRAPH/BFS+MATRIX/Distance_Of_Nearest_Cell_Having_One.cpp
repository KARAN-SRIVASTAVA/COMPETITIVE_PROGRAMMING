#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> nearest(vector<vector<int>> grid)
{
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>> vis(n, vector<int>(m, 0));
    vector<vector<int>> dist(n, vector<int>(m, 0));
    queue<pair<pair<int, int>, int>> q;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == 1)
            {
                q.push({{i, j}, 0});
                vis[i][j] = 1;
            }
        }
    }
    while (!q.empty()) 
    {
        auto it = q.front();
        q.pop();
        int x = it.first.first;
        int y = it.first.second;
        int dis = it.second;
        int dx[] = {-1, 1, 0, 0};
        int dy[] = {0, 0, 1, -1};
        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx >= 0 && ny >= 0 && nx < n && ny < m && !vis[nx][ny] && grid[nx][ny] == 0)
            {
                vis[nx][ny] = 1;
                q.push({{nx, ny}, dis + 1});
                dist[nx][ny] = dis + 1;
            }
        }
    }
    return dist;
}