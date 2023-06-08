#include <bits/stdc++.h>
using namespace std;
void print(vector<vector<int>> dp){
	for(auto it:dp){
		for(auto j:it) cout<<j<<" ";
		cout<<endl;
	}
}
int f(int i,vector<int>&weight,vector<int>&value,int W,vector<vector<int>>&dp){
	// Base Case
	if(i==0){
		if(weight[0]<=W) return value[0];
		return 0;
	}
	if(dp[i][W]!=-1) return dp[i][W];
	// exclude
	int ans1 = f(i-1,weight,value,W,dp);
	// Include
	int ans2 = 0;
	if(weight[i]<=W)
	  ans2 = value[i]+f(i-1,weight,value,W-weight[i],dp);
    return dp[i][W] = max(ans1,ans2);
}
int Tab(int n,vector<int>&weight,vector<int>&value,int W){
	vector<vector<int>>dp(n,vector<int>(W+1,0));
	for(int j=weight[0];j<=W;j++) dp[0][j] = value[0];
	for(int i=1;i<n;i++){
		for(int j=0;j<=W;j++){
			dp[i][j] = dp[i-1][j];
	        if(weight[i]<=j)
            dp[i][j] = max(dp[i][j],value[i]+dp[i-1][j-weight[i]]);
		}
	}
    // print(dp);
	return dp[n-1][W];
}
int Opt1(int n,vector<int>&weight,vector<int>&value,int W){
	vector<int>prev(W+1,0);
	for(int j=weight[0];j<=W;j++) prev[j] = value[0];
	for(int i=1;i<n;i++){
		vector<int>curr(W+1,0);
		for(int j=0;j<=W;j++){
			curr[j] = prev[j];
	        if(weight[i]<=j)
            curr[j] = max(curr[j],value[i]+prev[j-weight[i]]);
		}
		prev = curr;
	}
	return prev[W];
}
int Opt2(int n,vector<int>&weight,vector<int>&value,int W){
	vector<int>prev(W+1,0);
	for(int j=weight[0];j<=W;j++) prev[j] = value[0];
	for(int i=1;i<n;i++){
		for(int j=W;j>=0;j--)
	        if(weight[i]<=j)
               prev[j] = max(prev[j],value[i]+prev[j-weight[i]]);
	}
	return prev[W];
}
int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
	// vector<vector<int>>dp(n,vector<int>(maxWeight+1,-1));
	// return f(n-1,weight,value,maxWeight,dp);
	// return Tab(n,weight,value,maxWeight);
	// return Opt1(n,weight,value,maxWeight);
	return Opt2(n,weight,value,maxWeight);
}