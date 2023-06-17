#include <bits/stdc++.h>
using namespace std;
static bool comp(string &s1, string &s2)
{
    return s1.size() < s2.size();
}
bool ChangeofOne(string s1, string s2)
{
    if (s2.size() - s1.size() != 1)
        return 0;
    int i = 0, j = 0, changes = 0;
    while (i < s1.size())
    {
        if (s1[i] == s2[j])
        {
            i++;
            j++;
        }
        else
        {
            changes++;
            j++;
            if (changes > 1)
                return 0;
        }
    }
    return 1;
}
int longestStrChain(vector<string> &a)
{
    sort(a.begin(), a.end(), comp);
    int n = a.size();
    vector<int> dp(n, 1);
    for (int i = 0; i < n; i++)
    {
        int mx = 0;
        for (int j = 0; j < i; j++)
        {
            bool b = ChangeofOne(a[j], a[i]);
            if (b)
            {
                mx = max(mx, dp[j]);
            }
        }
        dp[i] = 1 + mx;
    }
    int mx = 0;
    for (int i = 0; i < n; i++)
        mx = max(mx, dp[i]);
    return mx;
}