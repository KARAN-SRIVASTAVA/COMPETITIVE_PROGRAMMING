#include <bits/stdc++.h>
using namespace std;
int orangesRotting(vector<vector<int>> &grid)
{
    int c1 = 0;
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>> vis(n, vector<int>(m, 0));
    // x,y,t
    queue<pair<pair<int, int>, int>> q;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == 2)
            {
                q.push({{i, j}, 0});
                vis[i][j] = 1;
            }
            if (grid[i][j] == 1)
                c1++;
        }
    }
    int changecnt = 0;
    int ans = 0;
    while (!q.empty())
    {
        auto it = q.front();
        q.pop();
        int x = it.first.first;
        int y = it.first.second;
        int t = it.second;
        ans = t;
        int dx[] = {-1, 1, 0, 0};
        int dy[] = {0, 0, 1, -1};
        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx >= 0 && nx < n && ny >= 0 && ny < m && !vis[nx][ny] && grid[nx][ny] == 1)
            {
                changecnt++;
                vis[nx][ny] = 1;
                q.push({{nx, ny}, t + 1});
            } 
        }
    }
    if (changecnt != c1)
        return -1;
    return ans;
}