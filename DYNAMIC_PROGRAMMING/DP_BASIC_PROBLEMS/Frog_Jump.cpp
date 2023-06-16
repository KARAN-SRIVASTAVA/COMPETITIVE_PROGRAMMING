#include <bits/stdc++.h>
using namespace std;
// O(2^n),O(n)
int f(int n, vector<int> &h, vector<int> &dp)
{
    // base case
    if (n == 0)
        return 0;
    if (n == 1)
        return abs(h[0] - h[1]);
    if (dp[n] != -1)
        return dp[n];
    int a1 = abs(h[n] - h[n - 1]) + f(n - 1, h, dp);
    int a2 = abs(h[n] - h[n - 2]) + f(n - 2, h, dp);
    return dp[n] = min(a1, a2);
}
// O(n),O(n)
int f1(int n, vector<int> &h)
{
    vector<int> dp(n, 0);
    dp[1] = abs(h[0] - h[1]);
    for (int i = 2; i < n; i++)
    {
        int a1 = abs(h[i] - h[i - 1]) + dp[i - 1];
        int a2 = abs(h[i] - h[i - 2]) + dp[i - 2];
        dp[i] = min(a1, a2);
    }
    return dp[n - 1];
}
// O(n),O(1)
int f2(int n, vector<int> &h)
{
    int prev2 = 0;
    int prev1 = abs(h[0] - h[1]);
    for (int i = 2; i < n; i++)
    {
        int a1 = abs(h[i] - h[i - 1]) + prev1;
        int a2 = abs(h[i] - h[i - 2]) + prev2;
        int ans = min(a1, a2);
        prev2 = prev1;
        prev1 = ans;
    }
    return prev1;
}
int frogJump(int n, vector<int> &h)
{
    // vector<int> dp(n,-1);
    // return f(n-1,h,dp);
    // return f1(n,h);
    return f2(n, h);
}