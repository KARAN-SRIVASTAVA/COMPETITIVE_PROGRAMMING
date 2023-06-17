#include <bits/stdc++.h>
using namespace std;
vector<int> tab(vector<int> &a, int n)
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
            if (a[i] % a[j] == 0)
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
    vector<int> LDS;
    while (parent[ind] != ind)
    {
        LDS.emplace_back(a[ind]);
        ind = parent[ind];
    }
    LDS.emplace_back(a[ind]);
    reverse(LDS.begin(), LDS.end());
    return LDS;
}
vector<int> divisibleSet(vector<int> &a)
{
    int n = a.size();
    sort(a.begin(), a.end());
    return tab(a, n);
}