#include <bits/stdc++.h>
using namespace std;
int solve(int i, int j1, int j2, vector<vector<int>> &grid, int n, int m, vector<vector<vector<int>>> &dp)
{
    if (j1 < 0 || j1 >= m || j2 < 0 || j2 >= m)
        return -1e8;
    if (i == n - 1)
    {
        if (j1 == j2)
            return grid[i][j1];
        else
            return grid[i][j1] + grid[i][j2];
    }
    if (dp[i][j1][j2] != -1)
        return dp[i][j1][j2];
    int maxi = -1e8;
    for (int dj1 = -1; dj1 < 2; dj1++)
    {
        for (int dj2 = -1; dj2 < 2; dj2++)
        {
            if (j1 == j2)
                maxi = max(maxi, grid[i][j1] + solve(i + 1, j1 + dj1, j2 + dj2, grid, n, m, dp));
            else
                maxi = max(maxi, grid[i][j1] + grid[i][j2] + solve(i + 1, j1 + dj1, j2 + dj2, grid, n, m, dp));
        }
    }
    return dp[i][j1][j2] = maxi;
}
int tab(vector<vector<int>> &grid, int n, int m)
{
    vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(m, -1e8)));
    for (int j1 = 0; j1 < m; j1++)
        for (int j2 = 0; j2 < m; j2++)
            if (j1 == j2)
                dp[n - 1][j1][j2] = grid[n - 1][j1];
            else
                dp[n - 1][j1][j2] = grid[n - 1][j1] + grid[n - 1][j2];

    for (int i = n - 2; i >= 0; i--)
    {
        for (int j1 = 0; j1 < m; j1++)
        {
            for (int j2 = 0; j2 < m; j2++)
            {
                int maxi = -1e8;
                for (int dj1 = -1; dj1 < 2; dj1++)
                    for (int dj2 = -1; dj2 < 2; dj2++)
                        if (j1 + dj1 < m && j2 + dj2 < m && j1 + dj1 >= 0 && j2 + dj2 >= 0)
                        {
                            if (j1 == j2)
                            {
                                maxi = max(maxi, grid[i][j1] + dp[i + 1][j1 + dj1][j2 + dj2]);
                            }
                            else
                            {
                                maxi = max(maxi, grid[i][j1] + grid[i][j2] + dp[i + 1][j1 + dj1][j2 + dj2]);
                            }
                            dp[i][j1][j2] = maxi;
                        }
            }
        }
    }
    return dp[0][0][m - 1];
}
int maximumChocolates(int r, int c, vector<vector<int>> &grid)
{
    // vector<vector<vector<int>>> dp(r,vector<vector<int>>(c,vector<int>(c,-1)));
    // return solve(0,0,c-1,grid,r,c,dp);
    return tab(grid, r, c);
}