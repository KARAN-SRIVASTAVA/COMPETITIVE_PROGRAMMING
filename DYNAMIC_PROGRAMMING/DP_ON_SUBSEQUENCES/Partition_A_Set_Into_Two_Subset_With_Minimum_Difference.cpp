#include <bits/stdc++.h>
using namespace std;
void print(vector<vector<int>>&v){
    for(auto it:v){
        for(auto j:it) cout<<j<<" ";
        cout<<endl;
    }
}
int tab(int n,vector<int> &a,int tar){
    vector<vector<int>>dp(n,vector<int>(tar+1,0));
    for(int j=0;j<=tar;j++){
        if(j==0){
            if(a[0]==0) dp[0][j] = 2;
            else dp[0][j] = 1;
        }
        else dp[0][j] = a[0]==j;
    }
    for(int i=1;i<n;i++){
        for(int j=0;j<=tar;j++){
            dp[i][j] = dp[i-1][j];
            if(a[i]<=j)
            dp[i][j]+=dp[i-1][j-a[i]];
        }     
    }
    int diff = INT_MAX;
    for(int i=0;i<=tar;i++)
      if(dp[n-1][i])
          diff = min(diff,abs(tar-2*i));
    return diff;
}
int Opt(int n,vector<int> &a,int tar){
    vector<int>prev(tar+1,0);
    for(int j=0;j<=tar;j++){
        if(j==0){
            if(a[0]==0) prev[j] = 2;
            else prev[j] = 1;
        }
        else prev[j] = a[0]==j;
    }
    for(int i=1;i<n;i++){
        vector<int>curr(tar+1,0);
        for(int j=0;j<=tar;j++){
            curr[j] = prev[j];
            if(a[i]<=j)
            curr[j]+=prev[j-a[i]];
        }  
        prev = curr;   
    }
    int diff = INT_MAX;
    for(int i=0;i<=tar;i++)
      if(prev[i])
          diff = min(diff,abs(tar-2*i));
    return diff;
}
int minSubsetSumDifference(vector<int>& arr, int n)
{
    int sum = 0;
    for(int i=0;i<n;i++) sum+=arr[i];
    
	// return tab(n,arr,sum);
	return Opt(n,arr,sum);
}