#include <bits/stdc++.h>
using namespace std;
void print(vector<vector<int>> &v)
{
    for (auto it : v)
    {
        for (auto j : it)
            cout << j << " ";
        cout << endl;
    }
}
int f(int i, vector<int> &a, int tar, vector<vector<int>> &dp)
{
    if (i == 0)
    {
        if (tar == 0)
        {
            if (a[i] == 0)
                return 2;
            else
                return 1;
        }
        else
            return a[i] == tar;
    }
    if (dp[i][tar] != -1)
        return dp[i][tar];
    int a1 = f(i - 1, a, tar, dp);
    int a2 = 0;
    if (a[i] <= tar)
        a2 = f(i - 1, a, tar - a[i], dp);
    return dp[i][tar] = a1 + a2;
}
int tab(int n, vector<int> &a, int tar)
{
    vector<vector<int>> dp(n, vector<int>(tar + 1, 0));
    for (int j = 0; j <= tar; j++)
    {
        if (j == 0)
        {
            if (a[0] == 0)
                dp[0][j] = 2;
            else
                dp[0][j] = 1;
        }
        else
            dp[0][j] = a[0] == j;
    }
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j <= tar; j++)
        {
            dp[i][j] = dp[i - 1][j];
            if (a[i] <= j)
                dp[i][j] += dp[i - 1][j - a[i]];
        }
    }
    // print(dp);
    return dp[n - 1][tar];
}
int Opt(int n, vector<int> &a, int tar)
{
    vector<int> prev(tar + 1, 0);
    for (int j = 0; j <= tar; j++)
    {
        if (j == 0)
        {
            if (a[0] == 0)
                prev[j] = 2;
            else
                prev[j] = 1;
        }
        else
            prev[j] = a[0] == j;
    }
    for (int i = 1; i < n; i++)
    {
        vector<int> curr(tar + 1, 0);
        for (int j = 0; j <= tar; j++)
        {
            curr[j] = prev[j];
            if (a[i] <= j)
                curr[j] += prev[j - a[i]];
        }
        prev = curr;
    }
    return prev[tar];
}
int findWays(vector<int> &num, int tar)
{
    int n = num.size();
    // vector<vector<int>>dp(n,vector<int>(tar+1,-1));
    // return f(n-1,num,tar,dp);
    // return tab(n,num,tar);
    return Opt(n, num, tar);
}