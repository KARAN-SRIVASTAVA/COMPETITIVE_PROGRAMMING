#include <bits/stdc++.h>
using namespace std;
int shortestPath(vector<vector<int>> &grid, pair<int, int> source,
                 pair<int, int> destination)
{
    int n = grid.size();
    int m = grid[0].size();
    int sx = source.first;
    int sy = source.second;
    int dx = destination.first;
    int dy = destination.second;
    if ((grid[sx][sy] == 0) || (sx == dx && sy == dy))
        return 0;
    vector<vector<int>> dis(n, vector<int>(m, 1e9));
    // d,x,y
    queue<pair<int, pair<int, int>>> q;
    q.push({0, {sx, sy}});
    dis[sx][sy] = 0;
    while (!q.empty())
    {
        int dist = q.front().first;
        int x = q.front().second.first;
        int y = q.front().second.second;
        q.pop();
        vector<int> dxc = {-1, 1, 0, 0};
        vector<int> dyc = {0, 0, -1, 1};
        for (int i = 0; i < 4; i++)
        {
            int nx = x + dxc[i];
            int ny = y + dyc[i];
            if (nx >= 0 && nx < n && ny >= 0 && ny < m && grid[nx][ny] == 1 && dist + 1 < dis[nx][ny])
            {
                dis[nx][ny] = dist + 1;
                if (nx == dx && ny == dy)
                    return dis[nx][ny];
                q.push({dist + 1, {nx, ny}});
            }
        }
    }
    return -1;
}