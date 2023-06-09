#include <bits/stdc++.h>
using namespace std;
bool f(int i, int j, string &s, string &t, vector<vector<int>> &dp)
{
    if (i == 0 && j == 0)
        return 1;
    if (i == 0 && j > 0)
        return 0;
    if (j == 0)
    {
        for (int ind = 1; ind <= i; ind++)
            if (s[ind - 1] != '*')
                return 0;
        return 1;
    }
    if (dp[i][j] != -1)
        return dp[i][j];
    if (s[i - 1] == '?' || s[i - 1] == t[j - 1])
        return dp[i][j] = f(i - 1, j - 1, s, t, dp);
    if (s[i - 1] == '*')
    {
        bool b1 = f(i - 1, j, s, t, dp);
        bool b2 = f(i, j - 1, s, t, dp);
        return dp[i][j] = b1 | b2;
    }
    return dp[i][j] = false;
}
int tab(int n, int m, string &s, string &t)
{
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    for (int i = 1; i <= n; i++)
    {
        bool b = 1;
        for (int ind = 1; ind <= i; ind++)
            if (s[ind - 1] != '*')
                b = 0;
        dp[i][0] = b;
    }
    dp[0][0] = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (s[i - 1] == '?' || s[i - 1] == t[j - 1])
                dp[i][j] = dp[i - 1][j - 1];
            else if (s[i - 1] == '*')
                dp[i][j] = dp[i - 1][j] | dp[i][j - 1];
            else
                dp[i][j] = 0;
        }
    }
    return dp[n][m];
}
int Opt(int n, int m, string &s, string &t)
{
    vector<int> prev(m + 1, 0);
    prev[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        vector<int> curr(m + 1, 0);
        bool b = 1;
        for (int ind = 1; ind <= i; ind++)
            if (s[ind - 1] != '*')
                b = 0;
        curr[0] = b;
        for (int j = 1; j <= m; j++)
        {
            if (s[i - 1] == '?' || s[i - 1] == t[j - 1])
                curr[j] = prev[j - 1];
            else if (s[i - 1] == '*')
                curr[j] = prev[j] | curr[j - 1];
            else
                curr[j] = 0;
        }
        prev = curr;
    }
    return prev[m];
}

bool wildcardMatching(string s, string t)
{
    int n = s.size();
    int m = t.size();
    // vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
    // return f(n,m,s,t,dp);
    // return tab(n,m,s,t);
    return Opt(n, m, s, t);
}
