#include <bits/stdc++.h>
using namespace std;
int f(int i, int j, vector<int> &cuts, vector<vector<int>> &dp)
{
    if (i > j)
        return 0;
    if (dp[i][j] != -1)
        return dp[i][j];
    int mn = INT_MAX;
    for (int ind = i; ind <= j; ind++)
        mn = min(mn, cuts[j + 1] - cuts[i - 1] + f(i, ind - 1, cuts, dp) + f(ind + 1, j, cuts, dp));
    return dp[i][j] = mn;
}
int tab(int n, vector<int> &cuts)
{
    vector<vector<int>> dp(n + 2, vector<int>(n + 2, 0));
    for (int i = n; i >= 1; i--)
    {
        for (int j = i; j <= n; j++)
        {
            int mn = 1e9;
            for (int ind = i; ind <= j; ind++)
                mn = min(mn, cuts[j + 1] - cuts[i - 1] + dp[i][ind - 1] + dp[ind + 1][j]);
            dp[i][j] = mn;
        }
    }
    return dp[1][n];
}
int cost(int n, int c, vector<int> &cuts)
{
    cuts.push_back(0);
    cuts.push_back(n);
    sort(cuts.begin(), cuts.end());
    // vector<vector<int>>dp(n+2,vector<int>(n+2,-1));
    // return f(1,c,cuts,dp);
    return tab(c, cuts);
}