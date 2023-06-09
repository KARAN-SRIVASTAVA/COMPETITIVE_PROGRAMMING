#include <bits/stdc++.h>
using namespace std;
#include <bits/stdc++.h>
int f(int n, int m, vector<vector<int>> &grid, vector<vector<int>> &dp)
{
  if (n < 0 || m < 0)
    return INT_MAX;
  if (n == 0 && m == 0)
    return grid[n][m];
  if (dp[n][m] != -1)
    return dp[n][m];
  return dp[n][m] = grid[n][m] + min(f(n - 1, m, grid, dp), f(n, m - 1, grid, dp));
}
int Tab(int n, int m, vector<vector<int>> &grid)
{
  vector<vector<int>> dp(n, vector<int>(m, 0));
  dp[0][0] = grid[0][0];
  for (int i = 1; i < n; i++)
    dp[i][0] = dp[i - 1][0] + grid[i][0];
  for (int j = 1; j < m; j++)
    dp[0][j] = dp[0][j - 1] + grid[0][j];
  for (int i = 1; i < n; i++)
    for (int j = 1; j < m; j++)
      dp[i][j] = grid[i][j] + min(dp[i - 1][j], dp[i][j - 1]);
  return dp[n - 1][m - 1];
}
int Opt(int n, int m, vector<vector<int>> &grid)
{
  vector<int> prev(m, 0);
  prev[0] = grid[0][0];
  for (int j = 1; j < m; j++)
    prev[j] = prev[j - 1] + grid[0][j];
  for (int i = 1; i < n; i++)
  {
    vector<int> curr(m, 0);
    curr[0] = grid[i][0] + prev[0];
    for (int j = 1; j < m; j++)
      curr[j] = grid[i][j] + min(prev[j], curr[j - 1]);
    prev = curr;
  }
  return prev[m - 1];
}
int minSumPath(vector<vector<int>> &grid)
{
  int n = grid.size();
  int m = grid[0].size();
  // vector<vector<int>>dp(n,vector<int>(m,-1));
  // return f(n-1,m-1,grid,dp);
  // return Tab(n,m,grid);
  return Opt(n, m, grid);
}