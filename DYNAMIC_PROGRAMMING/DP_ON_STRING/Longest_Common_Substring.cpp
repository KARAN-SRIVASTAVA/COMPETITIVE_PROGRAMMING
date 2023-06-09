#include <bits/stdc++.h>
using namespace std;
int tab(int n, int m, string &s, string &t)
{
	vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
	int ans = 0;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			if (s[i - 1] == t[j - 1])
				dp[i][j] = 1 + dp[i - 1][j - 1];
			else
				dp[i][j] = 0;
			ans = max(ans, dp[i][j]);
		}
	}
	return ans;
}
int Opt(int n, int m, string &s, string &t)
{
	vector<int> prev(m + 1, 0);
	int maxlen = 0;
	for (int i = 1; i <= n; i++)
	{
		vector<int> curr(m + 1, 0);
		for (int j = 1; j <= m; j++)
		{
			if (s[i - 1] == t[j - 1])
				curr[j] = 1 + prev[j - 1];
			else
				curr[j] = 0;
			maxlen = max(maxlen, curr[j]);
		}
		prev = curr;
	}
	return maxlen;
}
int lcs(string s, string t)
{
	int n = s.size();
	int m = t.size();
	// return tab(n,m,s,t);
	return Opt(n, m, s, t);
}