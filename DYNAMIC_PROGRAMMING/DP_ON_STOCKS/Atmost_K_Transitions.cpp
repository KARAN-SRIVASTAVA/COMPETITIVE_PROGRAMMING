#include <bits/stdc++.h>
using namespace std;
int f(vector<int> &a, int n, int ind, int id, int k, vector<vector<int>> &dp)
{
    if (id >= 2 * k)
        return 0;
    if (ind >= n)
        return 0;
    if (dp[ind][id] != -1)
        return dp[ind][id];
    if (id % 2 == 0)
        return dp[ind][id] = max(-a[ind] + f(a, n, ind + 1, id + 1, k, dp), f(a, n, ind + 1, id, k, dp));
    else
        return dp[ind][id] = max(a[ind] + f(a, n, ind + 1, id + 1, k, dp), f(a, n, ind + 1, id, k, dp));
}
int tab(vector<int> &a, int n, int k)
{
    vector<vector<int>> dp(n + 1, vector<int>(2 * k + 1, 0));
    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = 0; j < 2 * k; j++)
        {
            if (j % 2 == 0)
                dp[i][j] = max(-a[i] + dp[i + 1][j + 1], dp[i + 1][j]);
            else
                dp[i][j] = max(a[i] + dp[i + 1][j + 1], dp[i + 1][j]);
        }
    }
    return dp[0][0];
}
int Opt(vector<int> &a, int n, int k)
{
    vector<int> next(2 * k + 1, 0);
    for (int i = n - 1; i >= 0; i--)
    {
        vector<int> curr(2 * k + 1, 0);
        for (int j = 0; j < 2 * k; j++)
        {
            if (j % 2 == 0)
                curr[j] = max(-a[i] + next[j + 1], next[j]);
            else
                curr[j] = max(a[i] + next[j + 1], next[j]);
        }
        next = curr;
    }
    return next[0];
}
int maximumProfit(vector<int> &prices, int n, int k)
{
    //   vector<vector<int>>dp(n,vector<int>(2*k,-1));
    //   return f(prices,n,0,0,k,dp);
    //   return tab(prices,n,k);
    return Opt(prices, n, k);
}
