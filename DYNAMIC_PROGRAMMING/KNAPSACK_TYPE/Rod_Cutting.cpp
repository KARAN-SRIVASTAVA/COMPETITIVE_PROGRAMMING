#include <bits/stdc++.h>
using namespace std;
int f(int i, vector<int> &weight, vector<int> &profit, int W, vector<vector<int>> &dp)
{
    if (W == 0)
        return 0;
    if (i == 0)
        return ((W / weight[0]) * profit[0]);
    if (dp[i][W] != -1)
        return dp[i][W];
    int ans1 = f(i - 1, weight, profit, W, dp);
    int ans2 = 0;
    if (weight[i] <= W)
        ans2 = profit[i] + f(i, weight, profit, W - weight[i], dp);
    return dp[i][W] = max(ans1, ans2);
}
int tab(int n, vector<int> &weight, vector<int> &profit, int W)
{
    vector<vector<int>> dp(n, vector<int>(W + 1, 0));
    for (int j = 0; j <= W; j++)
        dp[0][j] = (j / weight[0]) * profit[0];

    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j <= W; j++)
        {
            dp[i][j] = dp[i - 1][j];
            if (weight[i] <= j)
                dp[i][j] = max(dp[i][j], profit[i] + dp[i][j - weight[i]]);
        }
    }
    return dp[n - 1][W];
}
int Opt1(int n, vector<int> &weight, vector<int> &profit, int W)
{
    vector<int> prev(W + 1, 0);
    for (int j = 0; j <= W; j++)
        prev[j] = (j / weight[0]) * profit[0];
    for (int i = 1; i < n; i++)
    {
        vector<int> curr(W + 1, 0);
        for (int j = 1; j <= W; j++)
        {
            curr[j] = prev[j];
            if (weight[i] <= j)
                curr[j] = max(curr[j], profit[i] + curr[j - weight[i]]);
        }
        prev = curr;
    }
    return prev[W];
}
int Opt2(int n, vector<int> &weight, vector<int> &profit, int W)
{
    vector<int> prev(W + 1, 0);
    for (int j = 0; j <= W; j++)
        prev[j] = (j / weight[0]) * profit[0];
    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j <= W; j++)
        {
            if (weight[i] <= j)
                prev[j] = max(prev[j], profit[i] + prev[j - weight[i]]);
        }
    }
    return prev[W];
}
int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight)
{
    // vector<vector<int>>dp(n,vector<int>(w+1,-1));
    // return f(n-1,weight,profit,w,dp);
    //  return tab(n,weight,profit,w);
    //  return Opt1(n,weight,profit,w);
    return Opt2(n, weight, profit, w);
}
int cutRod(vector<int> &price, int n)
{
    vector<int> segments;
    for (int i = 0; i < n; i++)
        segments.push_back(i + 1);
    return unboundedKnapsack(n, n, price, segments);
}
