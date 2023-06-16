#include <bits/stdc++.h>
using namespace std;
#define M 1000000007
// O(2^n),O(n)
int f(int n)
{
    // Base Case
    if (n == 0 || n == 1)
        return 1;
    return f(n - 1) + f(n - 2);
}
// O(n),O(n)+O(n)
int f1(int n, vector<int> &dp)
{
    // Base Case
    if (n == 0 || n == 1)
        return 1;
    if (dp[n] != -1)
        return dp[n];
    return dp[n] = (f1(n - 1, dp) + f1(n - 2, dp)) % M;
}
// O(n),O(n)
int f2(int n)
{
    vector<int> dp(n + 1, 0);
    dp[0] = dp[1] = 1;
    for (int i = 2; i <= n; i++)
        dp[i] = (dp[i - 1] + dp[i - 2]) % M;
    return dp[n];
}
// O(n),O(1)
int f3(int n)
{
    int prev2 = 1;
    int prev1 = 1;
    for (int i = 2; i <= n; i++)
    {
        int ans = (prev2 + prev1) % M;
        prev2 = prev1;
        prev1 = ans;
    }
    return prev1;
}
int countDistinctWays(int n)
{
    // return f(n);
    // vector<int>dp(n+1,-1);
    // return f1(n,dp);
    return f3(n);
}