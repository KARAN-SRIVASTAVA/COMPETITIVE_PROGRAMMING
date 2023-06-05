#include <bits/stdc++.h> 
using namespace std;
int f(int i,int j,vector<vector<int>>&mat,vector<vector<int>>&dp,int n,int m){
    if(i<0||i>=n||j<0||j>=m) return -1e9;
    if(i==0) return mat[i][j];
    if(dp[i][j]!=-1) return dp[i][j];
    int ans1 = f(i-1,j,mat,dp,n,m);
    int ans2 = f(i-1,j-1,mat,dp,n,m);
    int ans3 = f(i-1,j+1,mat,dp,n,m);
    return dp[i][j] = mat[i][j]+max(ans1,max(ans2,ans3));
}
int Tab(int n,int m,vector<vector<int>>&mat){
    vector<vector<int>>dp = mat;
    for(int i=1;i<n;i++){
        for(int j=0;j<m;j++){
            if(j==0)
               dp[i][j]+=max(dp[i-1][j],dp[i-1][j+1]);
            else if(j==m-1)
               dp[i][j]+=max(dp[i-1][j],dp[i-1][j-1]);
            else
               dp[i][j]+=max(dp[i-1][j-1],max(dp[i-1][j],dp[i-1][j+1]));
        }
    }
    int ans = -1e9;
    for(int j=0;j<m;j++) ans = max(ans,dp[n-1][j]);
    return ans;
}
int Opt(int n,int m,vector<vector<int>>&mat){
    vector<int>prev = mat[0];
    for(int i=1;i<n;i++){
        vector<int>curr = mat[i];
        for(int j=0;j<m;j++){
            if(j==0)
               curr[j]+=max(prev[j],prev[j+1]);
            else if(j==m-1)
               curr[j]+=max(prev[j],prev[j-1]);
            else
               curr[j]+=max(prev[j-1],max(prev[j],prev[j+1]));
        }
        prev = curr;
    }
    int ans = -1e9;
    for(int j=0;j<m;j++) ans = max(ans,prev[j]);
    return ans;
}
int getMaxPathSum(vector<vector<int>> &matrix)
{
    int n = matrix.size();
    int m = matrix[0].size();
    // vector<vector<int>>dp(n,vector<int>(m,-1));
    // int ans = -1e9;
    // for(int j=0;j<m;j++)
    //     ans = max(ans,f(n-1,j,matrix,dp,n,m));
    // return ans;
    // return Tab(n,m,matrix);
    return Opt(n,m,matrix);
}