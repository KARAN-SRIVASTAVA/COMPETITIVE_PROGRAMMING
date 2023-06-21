#include <bits/stdc++.h>
using namespace std;
int f(int i, int j, vector<int> &a, vector<vector<int>> &dp)
{
    if (i > j)
        return 0;
    if (dp[i][j] != -1)
        return dp[i][j];
    int mx = 0;
    for (int ind = i; ind <= j; ind++)
        mx = max(mx, f(i, ind - 1, a, dp) + f(ind + 1, j, a, dp) +
                         a[i - 1] * a[j + 1] * a[ind]);
    return dp[i][j] = mx;
}
int tab(int n, vector<int> &a)
{
    vector<vector<int>> dp(n + 2, vector<int>(n + 2, 0));
    for (int i = n; i >= 1; i--)
    {
        for (int j = i; j <= n; j++)
        {
            int mx = 0;
            for (int ind = i; ind <= j; ind++)
                mx = max(mx, a[i - 1] * a[j + 1] * a[ind] + dp[i][ind - 1] +
                                 dp[ind + 1][j]);
            dp[i][j] = mx;
        }
    }
    return dp[1][n];
}
int maxCoins(vector<int> &a)
{
    int n = a.size();
    a.insert(a.begin(), 1);
    a.push_back(1);
    // vector<vector<int>>dp(n+2,vector<int>(n+2,-1));
    // return f(1,n,a,dp);
    return tab(n, a);
}