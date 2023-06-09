#include <bits/stdc++.h>
using namespace std;
int f(int i, int j, vector<vector<int>> &triangle, vector<vector<int>> &dp)
{
	if (i == triangle.size() - 1)
		return triangle[i][j];
	if (dp[i][j] != -1)
		return dp[i][j];
	return dp[i][j] = triangle[i][j] + min(f(i + 1, j, triangle, dp), f(i + 1, j + 1, triangle, dp));
}
int Tab(vector<vector<int>> &triangle, int n)
{
	vector<vector<int>> dp(n, vector<int>(n, 1e9));
	dp[0][0] = triangle[0][0];
	for (int i = 1; i < n; i++)
		dp[i][0] = dp[i - 1][0] + triangle[i][0];
	for (int i = 1; i < n; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			dp[i][j] = triangle[i][j] + min(dp[i - 1][j - 1], dp[i - 1][j]);
		}
	}
	int ans = 1e9;
	for (int i = 0; i < n; i++)
		ans = min(ans, dp[n - 1][i]);
	return ans;
}
int Opt(vector<vector<int>> &triangle, int n)
{
	vector<int> prev(n, 1e9);
	prev[0] = triangle[0][0];
	for (int i = 1; i < n; i++)
	{
		vector<int> curr(n, 1e9);
		curr[0] = triangle[i][0] + prev[0];
		for (int j = 1; j <= i; j++)
			curr[j] = triangle[i][j] + min(prev[j - 1], prev[j]);
		prev = curr;
	}
	int ans = 1e9;
	for (int i = 0; i < n; i++)
		ans = min(ans, prev[i]);
	return ans;
}
int minimumPathSum(vector<vector<int>> &triangle, int n)
{
	// vector<vector<int>>dp(n,vector<int>(n,-1));
	// return f(0,0,triangle,dp);
	// return Tab(triangle,n);
	return Opt(triangle, n);
}