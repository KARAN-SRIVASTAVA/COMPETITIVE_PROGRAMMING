#include <bits/stdc++.h>
using namespace std;
void print(vector<vector<int>> dp)
{
  for (auto it : dp)
  {
    for (auto j : it)
      cout << j << " ";
    cout << endl;
  }
}
long f(int i, int *coin, int x, vector<vector<long>> &dp)
{
  if (x == 0)
    return 1;
  if (i == 0)
    return !(x % coin[0]);
  if (dp[i][x] != -1)
    return dp[i][x];
  long ans1 = f(i - 1, coin, x, dp);
  long ans2 = 0;
  if (coin[i] <= x)
    ans2 = f(i, coin, x - coin[i], dp);
  return dp[i][x] = ans1 + ans2;
}
long tab(int n, int *coin, int x)
{
  vector<vector<long>> dp(n, vector<long>(x + 1, 0));
  for (int j = 0; j <= x; j++)
    if (!(j % coin[0]))
      dp[0][j] = 1;
  for (int i = 0; i < n; i++)
    dp[i][0] = 1;
  for (int i = 1; i < n; i++)
  {
    for (int j = 1; j <= x; j++)
    {
      dp[i][j] = dp[i - 1][j];
      if (coin[i] <= j)
        dp[i][j] += dp[i][j - coin[i]];
    }
  }
  return dp[n - 1][x];
}
long Opt(int n, int *coin, int x)
{
  vector<long> prev(x + 1, 0);
  for (int j = 0; j <= x; j++)
    if (!(j % coin[0]))
      prev[j] = 1;
  for (int i = 1; i < n; i++)
  {
    vector<long> curr(x + 1, 0);
    curr[0] = 1;
    for (int j = 1; j <= x; j++)
    {
      curr[j] = prev[j];
      if (coin[i] <= j)
        curr[j] += curr[j - coin[i]];
    }
    prev = curr;
  }
  return prev[x];
}
long Opt2(int n, int *coin, int x)
{
  vector<long> prev(x + 1, 0);
  for (int j = 0; j <= x; j++)
    if (!(j % coin[0]))
      prev[j] = 1;
  for (int i = 1; i < n; i++)
  {
    prev[0] = 1;
    for (int j = 1; j <= x; j++)
      if (coin[i] <= j)
        prev[j] += prev[j - coin[i]];
  }
  return prev[x];
}

long countWaysToMakeChange(int *coins, int n, int x)
{
  // vector<vector<long>>dp(n,vector<long>(x+1,-1));
  //  return f(n-1,coins,x,dp);
  // return tab(n,coins,x);
  // return Opt(n,coins,x);
  return Opt2(n, coins, x);
}