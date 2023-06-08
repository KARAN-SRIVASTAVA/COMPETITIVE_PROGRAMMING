#include <bits/stdc++.h> 
using namespace std;
void print(vector<vector<int>>&v){
    for(auto it:v){
        for(auto j:it) cout<<j<<" ";
        cout<<endl;
    }
}
bool f(int i,vector<int> &a,int k,vector<vector<int>>&dp){
    if(k==0) return 1;
    if(i==0) return a[0]==k;
    if(dp[i][k]!=-1) return dp[i][k];
    bool b1 = f(i-1,a,k,dp);
    bool b2 = 0;
    if(a[i]<=k)
       b2 = f(i-1,a,k-a[i],dp);
    return dp[i][k] = b1|b2;
}
bool tab(int n,int k,vector<int>&a){
    vector<vector<int>>dp(n,vector<int>(k+1,0));
    for(int j=0;j<=k;j++) dp[0][j] = (a[0]==j);
    for(int i=0;i<n;i++) dp[i][0] = 1;
    for(int i=1;i<n;i++){
        for(int j=1;j<=k;j++){
            dp[i][j] = dp[i-1][j];
            if(a[i]<=j)
            dp[i][j]|=dp[i-1][j-a[i]];
        }
    }
    return dp[n-1][k];
}
bool Opt(int n,int k,vector<int>&a){
    vector<int>prev(k+1,0);
    for(int j=0;j<=k;j++) prev[j] = (a[0]==j);
    prev[0] = 1;
    for(int i=1;i<n;i++){
        vector<int>curr(k+1,0);
        curr[0] = 1;
        for(int j=1;j<=k;j++){
            curr[j] = prev[j];
            if(a[i]<=j)
            curr[j]|=prev[j-a[i]];
        }
        prev = curr;
    }
    return prev[k];
}
bool subsetSumToK(int n, int k, vector<int> &arr) {
    // vector<vector<int>>dp(n,vector<int>(k+1,-1));
    // return f(n-1,arr,k,dp);
    // return tab(n,k,arr);
    return Opt(n,k,arr);
}