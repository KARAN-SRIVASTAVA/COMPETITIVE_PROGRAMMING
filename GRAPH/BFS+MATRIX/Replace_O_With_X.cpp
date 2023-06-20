#include <bits/stdc++.h>
using namespace std;
void dfs(int x, int y, vector<vector<int>> &vis, vector<vector<char>> &mat)
{
    vis[x][y] = 1;
    int dx[] = {-1, 1, 0, 0};
    int dy[] = {0, 0, 1, -1};
    for (int i = 0; i < 4; i++)
    {
        int nx = x + dx[i]; 
        int ny = y + dy[i];
        if (nx >= 0 && ny >= 0 && nx < vis.size() && ny < vis[0].size() && mat[nx][ny] == 'O' && !vis[nx][ny])
        {
            dfs(nx, ny, vis, mat);
        }
    }
}
vector<vector<char>> fill(int n, int m, vector<vector<char>> matrix)
{
    vector<vector<char>> mat = matrix;
    vector<vector<int>> vis(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if ((i == 0 || i == n - 1 || j == 0 || j == m - 1) && !vis[i][j] && mat[i][j] == 'O')
                dfs(i, j, vis, mat);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (mat[i][j] == 'O' && !vis[i][j])
                mat[i][j] = 'X';
    return mat;
}