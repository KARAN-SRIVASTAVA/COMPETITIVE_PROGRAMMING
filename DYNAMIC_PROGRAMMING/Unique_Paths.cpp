#include <bits/stdc++.h> 
using namespace std;
int f(int n,int m,vector<vector<int>>&dp){
	if(n<0 || m<0) return 0;
	if(dp[n][m]!=-1) return dp[n][m];
	if(n==0 && m==0) return 1;
	return dp[n][m] = f(n-1,m,dp)+f(n,m-1,dp);
}
int Tab(int n,int m){
	vector<vector<int>>dp(n,vector<int>(m,1));
	for(int i=1;i<n;i++)
	  for(int j=1;j<m;j++)
	    dp[i][j] = dp[i-1][j]+dp[i][j-1];
	return dp[n-1][m-1];
}
int Opt(int n,int m){
	vector<int>prev(m,1);
	for(int i=1;i<n;i++){
      vector<int>curr(m,1);
	  for(int j=1;j<m;j++)
	    curr[j] = prev[j]+curr[j-1];
	  prev = curr;
	}
	return prev[m-1];
}
int uniquePaths(int m, int n) {
	// vector<vector<int>>dp(n,vector<int>(m,-1));
	// return f(n-1,m-1,dp);
	// return Tab(n,m);
	return Opt(n,m);
}