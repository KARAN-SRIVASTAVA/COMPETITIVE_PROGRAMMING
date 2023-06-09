#include <bits/stdc++.h> 
using namespace std;
void print(vector<vector<int>>&dp){
	for(auto it:dp){
		for(auto j:it) cout<<j<<" ";
		cout<<endl;
	}
}
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
	// print(dp);
	string shortestSupersequence = "";
	int i = n, j = m;
	while (i > 0 && j > 0)
	{
		if (dp[i][j] > dp[i - 1][j] && dp[i][j] > dp[i][j - 1])
		{
			shortestSupersequence += s[i - 1];
			i--, j--;
		}
		else if (dp[i][j-1] == dp[i][j]){
			shortestSupersequence+=t[j-1];
			j--;
		}
		else{
			shortestSupersequence+=s[i-1];
			i--;
		}
	}
	while(i>0)shortestSupersequence+=s[i-1],i--;
	while(j>0)shortestSupersequence+=t[j-1],j--;
	reverse(shortestSupersequence.begin(), shortestSupersequence.end());
	return shortestSupersequence;
}
string lcs(string s, string t)
{
	int n = s.size();
	int m = t.size();
	return tab(n, m, s, t);
}
string shortestSupersequence(string a, string b)
{
	return lcs(a,b);
}