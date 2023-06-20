#include <bits/stdc++.h>
using namespace std;
void dfs(int x, int y, int sx, int sy, vector<vector<int>> &vis,
         vector<vector<int>> &grid, int n, int m, vector<pair<int, int>> &v)
{
    v.push_back({x - sx, y - sy});
    vis[x][y] = 1;
    int dx[] = {-1, 1, 0, 0};
    int dy[] = {0, 0, -1, 1};
    for (int i = 0; i < 4; i++) 
    {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx >= 0 && ny >= 0 && nx < n && ny < m && !vis[nx][ny] && grid[nx][ny])
        {
            dfs(nx, ny, sx, sy, vis, grid, n, m, v);
        }
    }
}
int countDistinctIslands(vector<vector<int>> &grid)
{
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>> vis(n, vector<int>(m, 0));
    set<vector<pair<int, int>>> s;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (!vis[i][j] && grid[i][j])
            {
                vector<pair<int, int>> v;
                dfs(i, j, i, j, vis, grid, n, m, v);
                s.insert(v);
            }
        }
    }
    return s.size();
}