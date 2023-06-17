#include <bits/stdc++.h>
using namespace std;
int f(vector<int> &a, int n)
{
    vector<int> dp(n, 1);
    vector<int> dp1(n, 1);
    int maxi = 1;
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < i; j++)
            if (a[i] > a[j] && 1 + dp[j] > dp[i])
                dp[i] = 1 + dp[j];
    }
    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = i + 1; j < n; j++)
            if (a[i] > a[j] && 1 + dp1[j] > dp1[i])
                dp1[i] = 1 + dp1[j];
    }
    int ans = 1;
    for (int i = 0; i < n; i++)
        ans = max(ans, dp[i] + dp1[i] - 1);
    return ans;
}
int longestBitonicSequence(vector<int> &arr, int n)
{
    return f(arr, n);
}