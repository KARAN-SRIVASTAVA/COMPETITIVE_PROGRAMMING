#include <bits/stdc++.h>
using namespace std;
/*--THERE CAN BE MULTIPLE SUBSEQUENCE WE ARE JUST RETURNING ONE--*/
string tab(int n, int m, string &s, string &t)
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
	string lcs = "";
	int i = n, j = m;
	while (i > 0 && j > 0)
	{
		if (dp[i][j] > dp[i - 1][j] && dp[i][j] > dp[i][j - 1])
		{
			lcs += s[i - 1];
			i--, j--;
		}
		else if (dp[i - 1][j] == dp[i][j])
			i--;
		else
			j--;
	}
	reverse(lcs.begin(), lcs.end());
	return lcs;
}
string lcs(string s, string t)
{
	int n = s.size();
	int m = t.size();
	return tab(n, m, s, t);
}