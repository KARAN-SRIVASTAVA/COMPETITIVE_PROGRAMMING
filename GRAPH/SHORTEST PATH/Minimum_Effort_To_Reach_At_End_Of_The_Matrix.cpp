#include <bits/stdc++.h>
using namespace std;
int MinimumEffort(vector<vector<int>> &heights)
{
    int n = heights.size();
    int m = heights[0].size();
    vector<vector<int>> d(n, vector<int>(m, 1e9));
    d[0][0] = 0;
    set<pair<int, pair<int, int>>> s;
    s.insert({0, {0, 0}});
    while (!s.empty())
    {
        auto it = *s.begin();
        s.erase(it);
        int OldEffort = it.first;
        int x = it.second.first;
        int y = it.second.second;
        int dx[] = {-1, 1, 0, 0};
        int dy[] = {0, 0, 1, -1};
        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx >= 0 && nx < n && ny >= 0 && ny < m)
            {
                int newEffort = max(OldEffort, abs(heights[nx][ny] - heights[x][y]));
                if (newEffort < d[nx][ny])
                {
                    if (d[nx][ny] != 1e9)
                    {
                        s.erase({d[nx][ny], {nx, ny}});
                    }
                    d[nx][ny] = newEffort;
                    s.insert({newEffort, {nx, ny}});
                }
            }
        }
    }
    return d[n - 1][m - 1];
}