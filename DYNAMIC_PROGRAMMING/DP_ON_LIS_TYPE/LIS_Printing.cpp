#include <bits/stdc++.h>
using namespace std;
vector<int> tab(int *a, int n)
{
    vector<int> dp(n, 1);
    vector<int> parent(n);
    for (int i = 0; i < n; i++)
        parent[i] = i;
    for (int i = 0; i < n; i++)
    {
        int mx = 0;
        for (int j = 0; j < i; j++)
        {
            if (a[j] < a[i])
            {
                if (dp[j] > mx)
                {
                    parent[i] = j;
                    mx = dp[j];
                }
            }
        }
        dp[i] = 1 + mx;
    }
    int mx = 0;
    int ind = -1;
    for (int i = 0; i < n; i++)
    {
        if (mx < dp[i])
        {
            mx = dp[i];
            ind = i;
        }
    }
    vector<int> LIS;
    while (parent[ind] != ind)
    {
        LIS.emplace_back(a[ind]);
        ind = parent[ind];
    }
    LIS.emplace_back(a[ind]);
    reverse(LIS.begin(), LIS.end());
    return LIS;
}
vector<int> longestIncreasingSubsequence(int arr[], int n)
{
    vector<int> LIS = tab(arr, n);
    return LIS;
}
