#include <bits/stdc++.h>
using namespace std;
void dfs(int x, int y, vector<vector<int>> &grid, vector<vector<int>> &ans, vector<vector<int>> &vis, int oldcol, int newcol)
{
    vis[x][y] = 1;
    ans[x][y] = newcol;
    int dx[] = {-1, 1, 0, 0};
    int dy[] = {0, 0, -1, 1};
    for (int j = 0; j < 4; j++)
    {
        int nx = x + dx[j];
        int ny = y + dy[j];
        if (nx >= 0 && ny >= 0 && nx < vis.size() && ny < vis[0].size() && !vis[nx][ny] && grid[nx][ny] == oldcol)
            dfs(nx, ny, grid, ans, vis, oldcol, newcol);
    }
}
vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int newColor)
{
    vector<vector<int>> ans = image;
    vector<vector<int>> vis(image.size(), vector<int>(image[0].size(), 0));
    dfs(sr, sc, image, ans, vis, image[sr][sc], newColor);
    return ans;
}