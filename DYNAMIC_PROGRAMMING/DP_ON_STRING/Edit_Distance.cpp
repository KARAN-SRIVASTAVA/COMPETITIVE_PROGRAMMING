#include <bits/stdc++.h>
using namespace std;
int f(int i, int j, string &s, string &t, vector<vector<int>> &dp)
{
	if (i == 0)
		return j;
	if (j == 0)
		return i;
	if (dp[i][j] != -1)
		return dp[i][j];
	if (s[i - 1] == t[j - 1])
		return dp[i][j] = f(i - 1, j - 1, s, t, dp);
	return dp[i][j] = 1 + min(f(i - 1, j, s, t, dp), min(f(i, j - 1, s, t, dp), f(i - 1, j - 1, s, t, dp)));
}
int tab(int n, int m, string &s, string &t)
{
	vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
	for (int i = 0; i <= n; i++)
		dp[i][0] = i;
	for (int j = 0; j <= m; j++)
		dp[0][j] = j;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			if (s[i - 1] == t[j - 1])
				dp[i][j] = dp[i - 1][j - 1];
			else
				dp[i][j] = 1 + min(dp[i - 1][j], min(dp[i][j - 1], dp[i - 1][j - 1]));
		}
	}
	return dp[n][m];
}
int Opt(int n, int m, string &s, string &t)
{
	vector<int> prev(m + 1, 0);
	for (int j = 0; j <= m; j++)
		prev[j] = j;
	for (int i = 1; i <= n; i++)
	{
		vector<int> curr(m + 1, 0);
		curr[0] = i;
		for (int j = 1; j <= m; j++)
		{
			if (s[i - 1] == t[j - 1])
				curr[j] = prev[j - 1];
			else
				curr[j] = 1 + min(prev[j], min(curr[j - 1], prev[j - 1]));
		}
		prev = curr;
	}
	return prev[m];
}
int editDistance(string s, string t)
{
	int n = s.size();
	int m = t.size();
	// vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
	// return f(n,m,s,t,dp);
	// return tab(n,m,s,t);
	return Opt(n, m, s, t);
}