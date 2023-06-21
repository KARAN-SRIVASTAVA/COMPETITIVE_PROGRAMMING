#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define ll long long
ll f(ll i, ll j, bool isTrue, string &s, vector<vector<vector<ll>>> &dp)
{
    // Base Case
    if (i == j)
        if (isTrue)
            return s[i] == 'T';
        else
            return s[i] == 'F';
    if (dp[i][j][isTrue] != -1)
        return dp[i][j][isTrue];
    ll ways = 0;
    for (ll ind = i + 1; ind < j; ind += 2)
    {
        ll LT = f(i, ind - 1, 1, s, dp);
        ll LF = f(i, ind - 1, 0, s, dp);
        ll RT = f(ind + 1, j, 1, s, dp);
        ll RF = f(ind + 1, j, 0, s, dp);
        if (s[ind] == '&')
        {
            if (isTrue)
                ways = (ways + (LT * RT) % MOD) % MOD;
            else
                ways =
                    (ways + (LT * RF) % MOD + (LF * RT) % MOD + (LF * RF) % MOD) % MOD;
        }
        else if (s[ind] == '|')
        {
            if (isTrue)
                ways =
                    (ways + (LT * RF) % MOD + (LF * RT) % MOD + (LT * RT) % MOD) % MOD;
            else
                ways = (ways + (LF * RF) % MOD) % MOD;
        }
        else
        {
            if (isTrue)
                ways = (ways + (LT * RF) % MOD + (LF * RT) % MOD) % MOD;
            else
                ways = (ways + (LT * RT) % MOD + (LF * RF) % MOD) % MOD;
        }
    }
    return dp[i][j][isTrue] = ways;
}
ll evaluateExp(string &exp)
{
    ll n = exp.size();
    vector<vector<vector<ll>>> dp(n, vector<vector<ll>>(n, vector<ll>(2, -1)));
    return f(0, n - 1, 1, exp, dp);
}