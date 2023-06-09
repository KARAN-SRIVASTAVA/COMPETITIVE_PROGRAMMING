#include <bits/stdc++.h>
using namespace std;
// O(n),O(n)+O(n)
int f(int i, vector<vector<int>> &points, int last, vector<vector<int>> &dp)
{
    if (i == 0)
    {
        int mx = 0;
        for (int j = 0; j < 3; j++)
            if (j != last)
                mx = max(mx, points[0][j]);
        return mx;
    }
    if (dp[i][last] != -1)
        return dp[i][last];
    int ans = 0;
    for (int j = 0; j < 3; j++)
        if (j != last)
            ans = max(ans, points[i][j] + f(i - 1, points, j, dp));
    return dp[i][last] = ans;
}
// O(n),O(n)
int tab(int n, vector<vector<int>> &points)
{
    vector<vector<int>> dp = points;
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            int mx = 0;
            for (int k = 0; k < 3; k++)
                if (k != j)
                    mx = max(mx, dp[i - 1][k]);
            dp[i][j] = dp[i][j] + mx;
        }
    }
    int ans = 0;
    for (int i = 0; i < 3; i++)
        ans = max(ans, dp[n - 1][i]);
    return ans;
}

// O(n),O(1)
int opt(int n, vector<vector<int>> &points)
{
    vector<int> prev = points[0];
    for (int i = 1; i < n; i++)
    {
        vector<int> curr(3, 0);
        for (int j = 0; j < 3; j++)
        {
            int mx = 0;
            for (int k = 0; k < 3; k++)
                if (k != j)
                    mx = max(mx, prev[k]);
            curr[j] = points[i][j] + mx;
        }
        prev = curr;
    }
    int ans = 0;
    for (int i = 0; i < 3; i++)
        ans = max(ans, prev[i]);
    return ans;
}
int ninjaTraining(int n, vector<vector<int>> &points)
{
    // vector<vector<int>> dp(n,vector<int>(4,-1));
    // return f(n-1,points,3,dp);
    // return tab(n,points);
    return opt(n, points);
}