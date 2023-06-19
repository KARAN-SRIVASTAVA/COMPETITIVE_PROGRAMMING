#include <bits/stdc++.h>
using namespace std;
int tab(int n, int m, vector<vector<int>> &a)
{
    vector<vector<int>> dp(n, vector<int>(m, 0));
    int sum = 0;
    for (int i = 0; i < n; i++)
        dp[i][0] = a[i][0], sum += a[i][0];
    for (int j = 0; j < m; j++)
        dp[0][j] = a[0][j], sum += a[0][j];
    if (a[0][0])
        sum--;
    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < m; j++)
        {
            if (a[i][j] != 0)
                dp[i][j] = 1 + min(dp[i - 1][j], min(dp[i][j - 1], dp[i - 1][j - 1]));
            sum += dp[i][j];
        }
    }
    return sum;
}
int Opt(int n, int m, vector<vector<int>> &a)
{
    vector<int> prev(m, 0);
    int sum = 0;
    for (int j = 0; j < m; j++)
        prev[j] = a[0][j], sum += a[0][j];
    for (int i = 1; i < n; i++)
    {
        vector<int> cur(m, 0);
        if (a[i][0])
            cur[0] = 1, sum += 1;
        for (int j = 1; j < m; j++)
        {
            if (a[i][j] != 0)
                cur[j] = 1 + min(prev[j], min(cur[j - 1], prev[j - 1]));
            sum += cur[j];
        }
        prev = cur;
    }
    return sum;
}
int countSquares(int n, int m, vector<vector<int>> &a)
{
    // return tab(n,m,a);
    return Opt(n, m, a);
}
