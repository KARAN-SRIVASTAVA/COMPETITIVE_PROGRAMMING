#include <bits/stdc++.h>
using namespace std;
int minDiceThrowToLastCell(int **board, int n)
{

    queue<pair<int, int>> q;
    vector<int> v(n * n + 1, 0);
    int ind = 1;
    bool b = 1;
    for (int i = n - 1; i >= 0; i--)
    {
        if (b)
            for (int j = 0; j < n; j++)
                v[ind++] = board[i][j];
        else
            for (int j = n - 1; j >= 0; j--)
                v[ind++] = board[i][j];
        b = !b;
    }

    vector<int> vis(n * n + 1, 0);
    vis[0] = vis[1] = 1;
    q.push({1, 0});
    while (!q.empty())
    {
        auto it = q.front();
        q.pop();
        int x = it.first;
        int step = it.second;
        for (int i = 1; i <= 6; i++)
        {
            int nx = x + i;
            if (nx <= n * n && !vis[nx])
            {
                vis[nx] = 1;
                int p = 0;
                if (v[nx] != -1)
                    p = v[nx];
                else
                    p = nx;
                if (p == n * n)
                    return step + 1;
                q.push({p, step + 1});
            }
        }
    }
    return -1;
}