#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
int f(int n, int m, vector<vector<int>> &dp, vector<vector<int>> &mat)
{
    if (n < 0 || m < 0)
        return 0;
    if (dp[n][m] != -1)
        return dp[n][m];
    if (mat[n][m] == -1)
        return 0;
    if (n == 0 && m == 0)
        return 1;
    return dp[n][m] = (f(n - 1, m, dp, mat) + f(n, m - 1, dp, mat)) % MOD;
}
int Tab(int n, int m, vector<vector<int>> &mat)
{
    vector<vector<int>> dp(n, vector<int>(m, 0));
    dp[0][0] = 1;
    for (int i = 1; i < n; i++)
        if (mat[i][0] == -1)
            dp[i][0] = 0;
        else
            dp[i][0] = dp[i - 1][0];

    for (int i = 1; i < m; i++)
        if (mat[0][i] == -1)
            dp[0][i] = 0;
        else
            dp[0][i] = dp[0][i - 1];

    for (int i = 1; i < n; i++)
        for (int j = 1; j < m; j++)
            if (mat[i][j] != -1)
                dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % MOD;
    return dp[n - 1][m - 1];
}
int Opt(int n, int m, vector<vector<int>> &mat)
{
    vector<int> prev(m, 0);
    prev[0] = 1;
    for (int i = 1; i < m; i++)
        if (mat[0][i] == -1)
            prev[i] = 0;
        else
            prev[i] = prev[i - 1];

    for (int i = 1; i < n; i++)
    {
        vector<int> curr(m, 0);
        if (mat[i][0] == -1)
            curr[0] = 0;
        else
            curr[0] = prev[0];
        for (int j = 1; j < m; j++)
            if (mat[i][j] != -1)
                curr[j] = (prev[j] + curr[j - 1]) % MOD;
        prev = curr;
    }
    return prev[m - 1];
}
int mazeObstacles(int n, int m, vector<vector<int>> &mat)
{
    if (mat[0][0] == -1 || mat[n - 1][m - 1] == -1)
        return 0;
    // vector<vector<int>>dp(n,vector<int>(m,-1));
    // return f(n-1,m-1,dp,mat);
    // return Tab(n,m,mat);
    return Opt(n, m, mat);
}