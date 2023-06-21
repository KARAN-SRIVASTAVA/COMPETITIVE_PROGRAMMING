#include <bits/stdc++.h>
using namespace std;
int f(int i, int j, vector<int> &a, vector<vector<int>> &dp)
{
    if (i == j)
        return 0;
    if (dp[i][j] != -1)
        return dp[i][j];
    int mn = 1e9;
    for (int k = i; k < j; k++)
        mn = min(mn, f(i, k, a, dp) + f(k + 1, j, a, dp) + a[i - 1] * a[k] * a[j]);
    return dp[i][j] = mn;
}
int matrixMultiplication(vector<int> &a, int n)
{
    vector<vector<int>> dp(n, vector<int>(n, -1));
    return f(1, n - 1, a, dp);
}