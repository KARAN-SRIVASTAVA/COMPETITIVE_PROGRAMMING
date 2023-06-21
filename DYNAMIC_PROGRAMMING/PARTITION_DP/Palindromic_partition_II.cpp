#include <bits/stdc++.h>
using namespace std;
bool isPalindrome(string &s, int i, int j)
{
    while (i < j)
        if (s[i++] != s[j--])
            return 0;
    return 1;
}
int f(int i, string &str, vector<int> &dp)
{
    if (i >= str.size())
        return 0;
    if (dp[i] != -1)
        return dp[i];
    string temp = "";
    int mn = 1e9;
    for (int ind = i; ind < str.size(); ind++)
    {
        temp += str[ind];
        if (isPalindrome(temp, 0, temp.size() - 1))
            mn = min(mn, 1 + f(ind + 1, str, dp));
    }
    return dp[i] = mn;
}
int tab(string &s)
{
    int n = s.size();
    vector<int> dp(n + 1, 0);
    for (int i = n - 1; i >= 0; i--)
    {
        string temp = "";
        int mn = 1e9;
        for (int j = i; j < n; j++)
        {
            temp += s[j];
            if (isPalindrome(temp, 0, temp.size() - 1))
                mn = min(mn, 1 + dp[j + 1]);
        }
        dp[i] = mn;
    }
    return dp[0] - 1;
}
int palindromePartitioning(string str)
{
    // vector<int>dp(str.size(),-1);
    // return f(0,str,dp)-1;
    return tab(str);
}