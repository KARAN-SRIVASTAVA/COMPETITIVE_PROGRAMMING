#include <bits/stdc++.h> 
using namespace std;
int f(int i, int j, string &s, string &t, vector<vector<int>> &dp)
{
    if (i <= 0 || j <= 0)
        return 0;
    if (dp[i][j] != -1)
        return dp[i][j];
    if (s[i - 1] == t[j - 1])
        return dp[i][j] = 1 + f(i - 1, j - 1, s, t, dp);
    else
    {
        int ans1 = f(i - 1, j, s, t, dp);
        int ans2 = f(i, j - 1, s, t, dp);
        return dp[i][j] = max(ans1, ans2);
    }
}
int tab(int n, int m, string &s, string &t)
{
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (s[i - 1] == t[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    return dp[n][m];
}
int Opt(int n, int m, string &s, string &t)
{
    vector<int> prev(m + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        vector<int> curr(m + 1, 0);
        for (int j = 1; j <= m; j++)
        {
            if (s[i - 1] == t[j - 1])
                curr[j] = 1 + prev[j - 1];
            else
                curr[j] = max(prev[j], curr[j - 1]);
        }
        prev = curr;
    }
    return prev[m];
}
int lcs(string s, string t)
{
    int n = s.size();
    int m = t.size();
    // vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
    // return f(n,m,s,t,dp);
    // return tab(n,m,s,t);
    return Opt(n, m, s, t);
}
int longestPalindromeSubseq(string s)
{
    string t = s;
    reverse(t.begin(), t.end());
    return lcs(s, t);
}
int minInsertion(string &str)
{
    return str.size()-longestPalindromeSubseq(str);
}