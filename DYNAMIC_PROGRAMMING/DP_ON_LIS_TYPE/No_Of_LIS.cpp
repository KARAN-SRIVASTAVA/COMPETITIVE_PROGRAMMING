#include <bits/stdc++.h>
using namespace std;
int tab(vector<int> &a, int n)
{
    vector<int> dp(n, 1);
    vector<int> noLIS(n, 1);
    for (int i = 0; i < n; i++)
    {
        int mx = 0;
        for (int j = 0; j < i; j++)
        {
            if (a[j] < a[i])
            {
                if (dp[j] > mx)
                {
                    mx = dp[j];
                    noLIS[i] = noLIS[j];
                }
                else if (dp[j] == mx)
                {
                    noLIS[i] += noLIS[j];
                }
            }
        }
        dp[i] = 1 + mx;
    }
    int mx = 0;
    for (int i = 0; i < n; i++)
        mx = max(mx, dp[i]);
    int cnt = 0;
    for (int i = 0; i < n; i++)
        if (dp[i] == mx)
            cnt += noLIS[i];
    return cnt;
}
int findNumberOfLIS(vector<int> &a)
{
    int n = a.size();
    return tab(a, n);
}