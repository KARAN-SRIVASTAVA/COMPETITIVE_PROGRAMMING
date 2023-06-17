#include <bits/stdc++.h>
using namespace std;
int f(vector<int> &a, int n, int ind, int id, vector<vector<int>> &dp)
{
    if (ind >= n)
        return 0;
    if (dp[ind][id] != -1)
        return dp[ind][id];
    if (id == 0)
        return dp[ind][id] = max(-a[ind] + f(a, n, ind + 1, 1, dp), f(a, n, ind + 1, 0, dp));
    else
        return dp[ind][id] = max(a[ind] + f(a, n, ind + 1, 0, dp), f(a, n, ind + 1, 1, dp));
}
int tab(vector<int> &a, int n)
{
    vector<vector<int>> dp(n + 1, vector<int>(2, 0));
    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = 0; j < 2; j++)
        {
            if (j == 0)
                dp[i][j] = max(-a[i] + dp[i + 1][1], dp[i + 1][0]);
            else
                dp[i][j] = max(a[i] + dp[i + 1][0], dp[i + 1][1]);
        }
    }
    return dp[0][0];
}
int Opt(vector<int> &a, int n)
{
    vector<int> next(2, 0);
    for (int i = n - 1; i >= 0; i--)
    {
        vector<int> curr(2, 0);
        for (int j = 0; j < 2; j++)
        {
            if (j == 0)
                curr[j] = max(-a[i] + next[1], next[0]);
            else
                curr[j] = max(a[i] + next[0], next[1]);
        }
        next[0] = curr[0];
        next[1] = curr[1];
    }
    return next[0];
}
int getMaximumProfit(vector<int> &values, int n)
{
    // vector<vector<int>>dp(n,vector<int>(2,-1));
    // return f(values,n,0,0,dp);
    // return tab(values,n);
    return Opt(values, n);
}