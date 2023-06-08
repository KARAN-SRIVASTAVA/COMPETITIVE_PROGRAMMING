#include <bits/stdc++.h> 
using namespace std;
int f(int i,vector<int> &coin,int x,vector<vector<int>>&dp){
  // Base Case
  if(x==0) return 0;
  if(i==0){
      if(x%coin[0]) return 1e9;
      return x/coin[0];
  }
  if(dp[i][x]!=-1) return dp[i][x];
  int a1 = f(i-1,coin,x,dp);
  int a2 = 1e9;
  if(coin[i]<=x)
     a2 = 1+f(i,coin,x-coin[i],dp);
  return dp[i][x] = min(a1,a2);
}
int tab(int n,vector<int> &coin,int x){
    vector<vector<int>>dp(n,vector<int>(x+1,1e9));
    for(int j=0;j<=x;j++)
      if(j%coin[0]==0) dp[0][j] = j/coin[0];
    for(int i=0;i<n;i++) dp[i][0] = 0;
    for(int i=1;i<n;i++){
        for(int j=1;j<=x;j++){
            dp[i][j] = dp[i-1][j];
            if(coin[i]<=j)
            dp[i][j] = min(dp[i][j],1+dp[i][j-coin[i]]);
        }
    }
    if(dp[n-1][x]>=1e9) return -1;
    return dp[n-1][x];
}
int Opt(int n,vector<int> &coin,int x){
    vector<int>prev(x+1,1e9);
    for(int j=0;j<=x;j++)
      if(j%coin[0]==0) prev[j] = j/coin[0];
    for(int i=1;i<n;i++){
        vector<int>curr(x+1,1e9);
        curr[0] = 0;
        for(int j=1;j<=x;j++){
            curr[j] = prev[j];
            if(coin[i]<=j)
            curr[j] = min(curr[j],1+curr[j-coin[i]]);
        }
        prev = curr;
    }
    if(prev[x]>=1e9) return -1;
    return prev[x];
}
int Opt2(int n,vector<int> &coin,int x){
    vector<int>prev(x+1,1e9);
    for(int j=0;j<=x;j++)
      if(j%coin[0]==0) prev[j] = j/coin[0];
    for(int i=1;i<n;i++){
        prev[0] = 0;
        for(int j=1;j<=x;j++){
            if(coin[i]<=j)
            prev[j] = min(prev[j],1+prev[j-coin[i]]);
        }
    }
    if(prev[x]>=1e9) return -1;
    return prev[x];
}
int minimumElements(vector<int> &coin, int x)
{
    int n = coin.size();
    // vector<vector<int>>dp(n,vector<int>(x+1,-1));
    // int ans = f(n-1,coin,x,dp);
    // if(ans>=1e9) return -1;
    // return ans;
    // return tab(n,coin,x);
    // return Opt(n,coin,x);
    return Opt2(n,coin,x);
}