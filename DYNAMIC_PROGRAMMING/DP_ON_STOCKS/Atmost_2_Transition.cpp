#include <bits/stdc++.h>
using namespace std;
int f(vector<int> &a, int n, int ind, int id, vector<vector<int>> &dp)
{
    if (id > 3)
        return 0;
    if (ind >= n)
        return 0;
    if (dp[ind][id] != -1)
        return dp[ind][id];
    if (id % 2 == 0)
        return dp[ind][id] = max(-a[ind] + f(a, n, ind + 1, id + 1, dp), f(a, n, ind + 1, id, dp));
    else
        return dp[ind][id] = max(a[ind] + f(a, n, ind + 1, id + 1, dp), f(a, n, ind + 1, id, dp));
}
int tab(vector<int> &a, int n)
{
    vector<vector<int>> dp(n + 1, vector<int>(5, 0));
    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = 0; j < 4; j++)
        {
            if (j % 2 == 0)
                dp[i][j] = max(-a[i] + dp[i + 1][j + 1], dp[i + 1][j]);
            else
                dp[i][j] = max(a[i] + dp[i + 1][j + 1], dp[i + 1][j]);
        }
    }
    return dp[0][0];
}
int Opt(vector<int> &a, int n)
{
    vector<int> next(5, 0);
    for (int i = n - 1; i >= 0; i--)
    {
        vector<int> curr(5, 0);
        for (int j = 0; j < 4; j++)
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
int maxProfit(vector<int> &prices, int n)
{
    //   vector<vector<int>>dp(n,vector<int>(4,-1));
    //   return f(prices,n,0,0,dp);
    //   return tab(prices,n);
    return Opt(prices, n);
}