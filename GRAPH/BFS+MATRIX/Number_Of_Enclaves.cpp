#include <bits/stdc++.h>
using namespace std;
void dfs(int x, int y, vector<vector<int>> &vis, vector<vector<int>> &mat)
{
    vis[x][y] = 1;
    int dx[] = {-1, 1, 0, 0};
    int dy[] = {0, 0, 1, -1};
    for (int i = 0; i < 4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx >= 0 && ny >= 0 && nx < vis.size() && ny < vis[0].size() && mat[nx][ny] == 1 && !vis[nx][ny])
        {
            dfs(nx, ny, vis, mat);
        }
    }
}
int numberOfEnclaves(vector<vector<int>> &grid)
{
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>> vis(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if ((i == 0 || i == n - 1 || j == 0 || j == m - 1) && !vis[i][j] && grid[i][j] == 1)
                dfs(i, j, vis, grid);

    int cnt = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (grid[i][j] == 1 && !vis[i][j])
                cnt++;

    return cnt;
}