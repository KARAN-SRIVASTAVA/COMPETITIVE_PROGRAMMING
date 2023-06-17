#include <bits/stdc++.h>
using namespace std;
int f(int *a, int n, int ind, int last, vector<vector<int>> &dp)
{
    if (ind >= n)
        return 0;
    if (dp[ind][last + 1] != -1)
        return dp[ind][last + 1];
    if (last == -1)
    {
        return dp[ind][last + 1] = max(1 + f(a, n, ind + 1, ind, dp), f(a, n, ind + 1, -1, dp));
    }
    else if (a[ind] > a[last])
    {
        int a1 = 1 + f(a, n, ind + 1, ind, dp);
        int a2 = f(a, n, ind + 1, last, dp);
        return dp[ind][last + 1] = max(a1, a2);
    }
    else
    {
        return dp[ind][last + 1] = f(a, n, ind + 1, last, dp);
    }
}
int tab(int *a, int n)
{
    vector<int> dp(n, 1);
    for (int i = 0; i < n; i++)
    {
        int mx = 0;
        for (int j = 0; j < i; j++)
        {
            if (a[j] < a[i])
                mx = max(mx, dp[j]);
        }
        dp[i] = 1 + mx;
    }
    int mx = 0;
    for (int i = 0; i < n; i++)
        mx = max(mx, dp[i]);
    return mx;
}
// Optimal Approach
int bs(int *a, int n)
{
    vector<int> dp;
    dp.emplace_back(a[0]);
    for (int i = 1; i < n; i++)
    {
        if (a[i] > dp.back())
            dp.emplace_back(a[i]);
        else
        {
            int index = lower_bound(dp.begin(), dp.end(), a[i]) - dp.begin();
            dp[index] = a[i];
        }
    }
    return dp.size();
}
int longestIncreasingSubsequence(int arr[], int n)
{
    // vector<vector<int>>dp(n,vector<int>(n+1,-1));
    // return f(arr,n,0,-1,dp);
    // return tab(arr,n);
    return bs(arr, n);
}