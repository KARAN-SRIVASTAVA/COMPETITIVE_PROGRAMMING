#include <bits/stdc++.h>
using namespace std;
void dfs(int x, int y, vector<vector<char>> &grid, vector<vector<int>> &vis)
{
    vis[x][y] = 1;
    for (int i = -1; i < 2; i++)
    {
        for (int j = -1; j < 2; j++)
        { 
            int nx = x + i;
            int ny = y + j;
            if (nx >= 0 && ny >= 0 && nx < vis.size() && ny < vis[0].size() && !vis[nx][ny] && grid[nx][ny] == '1')
                dfs(nx, ny, grid, vis);
        }
    }
}
int numIslands(vector<vector<char>> &grid)
{
    int n = grid.size();
    int m = grid[0].size();
    int cnt = 0;
    vector<vector<int>> vis(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == '1' && !vis[i][j])
            {
                dfs(i, j, grid, vis);
                cnt++;
            }
        }
    }
    return cnt;
}